#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qmailsmtpd.sh,v 1.31 2021/01/14 15:42:36 schmonz Exp $
#
# @PKGNAME@ script to control qmail-smtpd (SMTP service).
#

# PROVIDE: qmailsmtpd mail
# REQUIRE: qmailsend

name="qmailsmtpd"

# User-settable rc.conf variables and their default values:
: ${qmailsmtpd_postenv:=""}
: ${qmailsmtpd_datalimit:="540000000"}
: ${qmailsmtpd_pretcpserver:=""}
: ${qmailsmtpd_tcpserver:="@PREFIX@/bin/sslserver"}
: ${qmailsmtpd_tcpflags:="-ne -vRl0"}
: ${qmailsmtpd_tcphost:=":0"}
: ${qmailsmtpd_tcpport:="25"}
: ${qmailsmtpd_tcprules:="@PKG_SYSCONFDIR@/control/tcprules/smtp"}
: ${qmailsmtpd_autocdb:="YES"}
: ${qmailsmtpd_presmtpd:="@PREFIX@/bin/greetdelay -- @PREFIX@/bin/rblsmtpd -r zen.spamhaus.org @PREFIX@/bin/fixsmtpio"}
: ${qmailsmtpd_smtpdcmd:="@PREFIX@/bin/qmail-smtpd"}
: ${qmailsmtpd_postsmtpd:=""}
: ${qmailsmtpd_log:="YES"}
: ${qmailsmtpd_logcmd:="logger -t nbqmail/smtpd -p mail.info"}
: ${qmailsmtpd_nologcmd:="@PREFIX@/bin/multilog -*"}
: ${qmailsmtpd_tls:="auto"}
: ${qmailsmtpd_tls_dhparams:="@PKG_SYSCONFDIR@/control/dh2048.pem"}
: ${qmailsmtpd_tls_cert:="@PKG_SYSCONFDIR@/control/servercert.pem"}
: ${qmailsmtpd_tls_key:="@PKG_SYSCONFDIR@/control/serverkey.pem"}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcvar=${name}
required_files="@PKG_SYSCONFDIR@/control/me"
required_files="${required_files} @PKG_SYSCONFDIR@/control/concurrencyincoming"
required_files="${required_files} @PKG_SYSCONFDIR@/control/rcpthosts"
required_files="${required_files} ${qmailsmtpd_tcprules}"
command="${qmailsmtpd_tcpserver}"
procname=nb${name}
start_precmd="qmailsmtpd_precmd"
extra_commands="stat pause cont cdb reload"
stat_cmd="qmailsmtpd_stat"
pause_cmd="qmailsmtpd_pause"
cont_cmd="qmailsmtpd_cont"
cdb_cmd="qmailsmtpd_cdb"
reload_cmd=${cdb_cmd}

qmailsmtpd_configure_tls() {
	if [ "auto" = "${qmailsmtpd_tls}" ]; then
		if [ -f "${qmailsmtpd_tls_cert}" ]; then
			qmailsmtpd_enable_tls
		else
			qmailsmtpd_disable_tls
		fi
	elif [ -f /etc/rc.subr ] && checkyesno qmailsmtpd_tls; then
		qmailsmtpd_enable_tls
	else
		qmailsmtpd_disable_tls
	fi
}

qmailsmtpd_disable_tls() {
	qmailsmtpd_postenv="DISABLETLS=1 ${qmailsmtpd_postenv}"
}

qmailsmtpd_enable_tls() {
	qmailsmtpd_postenv="CADIR=@SSLDIR@/certs ${qmailsmtpd_postenv}"
	qmailsmtpd_postenv="SSL_UID=$(@ID@ -u @UCSPI_SSL_USER@) ${qmailsmtpd_postenv}"
	qmailsmtpd_postenv="SSL_GID=$(@ID@ -g @UCSPI_SSL_GROUP@) ${qmailsmtpd_postenv}"
	qmailsmtpd_postenv="DHFILE=${qmailsmtpd_tls_dhparams} ${qmailsmtpd_postenv}"
	qmailsmtpd_postenv="CERTFILE=${qmailsmtpd_tls_cert} ${qmailsmtpd_postenv}"
	if [ -n "${qmailsmtpd_tls_key}" -a ! -f "${qmailsmtpd_tls_key}" ]; then
		openssl rsa -in ${qmailsmtpd_tls_cert} -out ${qmailsmtpd_tls_key}
		@CHMOD@ 640 ${qmailsmtpd_tls_key}
	fi
	qmailsmtpd_postenv="KEYFILE=${qmailsmtpd_tls_key} ${qmailsmtpd_postenv}"
}

qmailsmtpd_precmd() {
	if [ -f /etc/rc.subr ] && ! checkyesno qmailsmtpd_log; then
		qmailsmtpd_logcmd=${qmailsmtpd_nologcmd}
	fi
	qmailsmtpd_configure_tls
	if [ -f /etc/rc.subr ] && checkyesno qmailsmtpd_autocdb; then
		qmailsmtpd_needcdb && qmailsmtpd_cdb
	fi
	# tcpserver(1) is akin to inetd(8), but runs one service per process.
	# We want to signal only the tcpserver process responsible for this
	# service. Use argv0(1) to set procname to "nbqmailsmtpd".
	command="@PREFIX@/bin/pgrphack @SETENV@ - ${qmailsmtpd_postenv} \
@PREFIX@/bin/softlimit -m ${qmailsmtpd_datalimit} ${qmailsmtpd_pretcpserver} \
@PREFIX@/bin/argv0 ${qmailsmtpd_tcpserver} ${procname} \
${qmailsmtpd_tcpflags} -x ${qmailsmtpd_tcprules}.cdb \
-c `@HEAD@ -1 @PKG_SYSCONFDIR@/control/concurrencyincoming` \
-u `@ID@ -u @QMAIL_DAEMON_USER@` -g `@ID@ -g @QMAIL_DAEMON_USER@` \
${qmailsmtpd_tcphost} ${qmailsmtpd_tcpport} \
${qmailsmtpd_presmtpd} ${qmailsmtpd_smtpdcmd} ${qmailsmtpd_postsmtpd} \
2>&1 | \
@PREFIX@/bin/pgrphack @PREFIX@/bin/setuidgid @QMAIL_LOG_USER@ ${qmailsmtpd_logcmd}"
	command_args="&"
	rc_flags=""
}

qmailsmtpd_stat() {
	run_rc_command status
}

qmailsmtpd_pause() {
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Pausing ${name}."
	kill -STOP $rc_pid
}

qmailsmtpd_cont() {
	if ! statusmsg=`run_rc_command status`; then
		@ECHO@ $statusmsg
		return 1
	fi
	@ECHO@ "Continuing ${name}."
	kill -CONT $rc_pid
}

qmailsmtpd_needcdb() {
	_src=${qmailsmtpd_tcprules}
	_dst=${qmailsmtpd_tcprules}.cdb
	[ -f "${_src}" -a "${_src}" -nt "${_dst}" ] || [ ! -f "${_dst}" ]
}

qmailsmtpd_cdb() {
	@ECHO@ "Reloading ${qmailsmtpd_tcprules}."
	@PREFIX@/bin/tcprules ${qmailsmtpd_tcprules}.cdb ${qmailsmtpd_tcprules}.tmp < ${qmailsmtpd_tcprules}
	@CHMOD@ 644 ${qmailsmtpd_tcprules}.cdb
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO_N@ " ${name}"
	qmailsmtpd_precmd
	eval ${command} ${qmailsmtpd_flags} ${command_args}
fi
