#!/sbin/runscript

name="thttpd HTTP Server"
command="/usr/bin/thttpd"
command_args="${thttpd_flags:--C /etc/thttpd.conf}"

depend() {
  need net
  after logger
}
