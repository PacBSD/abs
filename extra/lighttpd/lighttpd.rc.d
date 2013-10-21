#!/sbin/runscript
# Copyright 1999-2005 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: /var/cvsroot/gentoo-x86/www-servers/lighttpd/files/lighttpd.initd,v 1.12 2007/10/12 20:54:46 swegener Exp $

#opts="depend checkconfig start stop reload"

depend() {
need net
use mysql logger spawn-fcgi ldap slapd
after sshd
}

checkconfig() {
if test ! -f ${LIGHTTPD_CONF}; then
ewarn "${LIGHTTPD_CONF} does not exist."
return 1
fi

${LIGHTTPD_BIN} -t -f ${LIGHTTPD_CONF} >/dev/null
}

start() {
checkconfig || return 1

ebegin "Starting lighttpd"
start-stop-daemon --start --quiet \
--make-pidfile \
--background --pidfile ${LIGHTTPD_PID} \
--exec ${LIGHTTPD_BIN} -- -f ${LIGHTTPD_CONF}
eend $?
}

stop() {
local rv=0
ebegin "Stopping lighttpd"
if start-stop-daemon --stop --name lighttpd --quiet \
--signal 2; then
rm -f ${LIGHTTPD_PID}
else
rv=1
fi
eend $rv
}

reload() {
if test ! -f ${LIGHTTPD_PID}; then
eerror "lighttpd isn't running"
return 1
fi
checkconfig || return 1
ebegin "Re-opening lighttpd log files"
kill -HUP `cat ${LIGHTTPD_PID}` &>/dev/null
eend $?
}

