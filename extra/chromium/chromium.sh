#!/usr/bin/bash

SYSCTL=kern.ipc.shm_allow_removed
if [ "`/sbin/sysctl -n $SYSCTL`" = 0 ] ; then
	cat << EOMSG
For correct operation, shared memory support has to be enabled
in Chromium by performing the following command as root :

sysctl $SYSCTL=1

To preserve this setting across reboots, append the following
to /etc/sysctl.conf :

$SYSCTL=1
EOMSG
	exit 1
fi

# Allow users to override command-line options
# Based on Gentoo's chromium package (and by extension, Debian's)
if [[ -f /etc/chromium/default ]]; then
	. /etc/chromium/default
fi

# Prefer user defined CHROMIUM_USER_FLAGS (from env) over system
# default CHROMIUM_FLAGS (from /etc/chromium/default)
CHROMIUM_FLAGS=${CHROMIUM_USER_FLAGS:-$CHROMIUM_FLAGS}

export CHROME_WRAPPER=$(readlink -f "$0")
export CHROME_DESKTOP=chromium.desktop

exec /usr/lib/chromium/chromium $CHROMIUM_FLAGS "$@"
