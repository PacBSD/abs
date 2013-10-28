#!/usr/bin/bash -e -E

# see http://kernelnomicon.org/?p=275

if ! (type -t flags_for_all |grep 'function'); then
  on_error() {
    umount "$MNTDIR" || true
    mdconfig -d -u ${MDFILE} || true
    msg "There was an error"
    exit 1
  }

  trap on_error ERR

  source PKGBUILD
  msg() {
    local mesg="$1"; shift
    printf "\033[1;34m==>\033[0;0m ${mesg}\n" "$@"
  }
  srcdir=$PWD/src
  flags_for_all
fi

msg "Preparing image"
cd "${srcdir}"
dd if=/dev/zero of="${IMG}" bs=128M count=8
MDFILE=`mdconfig -a -f "${IMG}"`
gpart create -s MBR "${MDFILE}"

msg "Boot partition"
gpart add -s 32m -t '!12' ${MDFILE}
gpart set -a active -i 1 ${MDFILE}
newfs_msdos -L boot -F 16 /dev/${MDFILE}s1
install -dm755 "${MNTDIR}"
mount_msdosfs /dev/${MDFILE}s1 "$MNTDIR"
tar -C "$MNTDIR" -xvf "${srcdir}/${uboot_src}" || true

msg "Config"
cat >> $MNTDIR/config.txt <<__EOC__
gpu_mem=$GPU_MEM
device_tree=devtree.dat
device_tree_address=0x100
disable_commandline_tags=1
__EOC__
cp "$UBLDR" "$MNTDIR"
cp "$DTB" "$MNTDIR/devtree.dat"

umount "$MNTDIR"

msg "FreeBSD partition"
# (empty) FreeBSD partition:
gpart add -t freebsd ${MDFILE}
gpart create -s BSD ${MDFILE}s2
gpart add -t freebsd-ufs ${MDFILE}s2
newfs /dev/${MDFILE}s2a
tunefs -n enable /dev/${MDFILE}s2a
tunefs -j enable -S $[4*1024*1024] /dev/${MDFILE}s2a
# turn on NFSv4 ACLs
tunefs -N enable /dev/${MDFILE}s2a

msg "Setup"
mount /dev/${MDFILE}s2a $MNTDIR
# install the packages there!
# make -C $SRCROOT DESTDIR=$MNTDIR -DDB_FROM_SRC installkernel
# make -C $SRCROOT DESTDIR=$MNTDIR -DDB_FROM_SRC installworld
# make -C $SRCROOT DESTDIR=$MNTDIR -DDB_FROM_SRC distribution

install -dm755 "${MNTDIR}/boot"
echo 'fdt addr 0x100' > "${MNTDIR}/boot/loader.rc"
install -dm755 "${MNTDIR}/etc"
echo '/dev/mmcsd0s2a / ufs rw,noatime 1 1' > $MNTDIR/etc/fstab

cat > "$MNTDIR/etc/rc.conf" <<__EORC__
hostname="raspberry-pi"
ifconfig_ue0="DHCP"
sshd_enable="YES"

devd_enable="YES"
sendmail_submit_enable="NO"
sendmail_outbound_enable="NO"
sendmail_msp_queue_enable="NO"
__EORC__

cat > "$MNTDIR/etc/ttys" <<__EOTTYS__
ttyv0 "/usr/libexec/getty Pc" xterm on secure
ttyv1 "/usr/libexec/getty Pc" xterm on secure
ttyv2 "/usr/libexec/getty Pc" xterm on secure
ttyv3 "/usr/libexec/getty Pc" xterm on secure
ttyv4 "/usr/libexec/getty Pc" xterm on secure
ttyv5 "/usr/libexec/getty Pc" xterm on secure
ttyv6 "/usr/libexec/getty Pc" xterm on secure
ttyu0 "/usr/libexec/getty 3wire.115200" dialup on secure
__EOTTYS__

umount "$MNTDIR"
mdconfig -d -u $MDFILE

