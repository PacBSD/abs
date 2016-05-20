# $FreeBSD: head/Mk/Uses/libtool.mk 411970 2016-03-27 01:23:25Z bapt $
#
# Bring libtool scripts up to date.
#
# Feature:	libtool
# Usage:	USES=libtool or USES=libtool:args
# Valid args:	keepla	Don't remove libtool libraries (*.la) from the stage
#			directory.  Some ports need them at runtime (e.g. ports
#			that call lt_dlopen from libltdl).
#		build	Add a build dependency on devel/libtool.  This can
#			be used when a port does not generate its own libtool
#			script and relies on the system to provide one.
#
# MAINTAINER:	autotools@FreeBSD.org

patch-libtool:
	@find ${WORKDIR} \( -name configure -or -name ltconfig \)	\
		-type f | while read i; do sed -i.libtool.bak	\
		-e '/dragonfly\*/!s/^ *freebsd\*[ )]/dragonfly* | &/'	\
		-e '/gcc_dir=\\`/s/gcc /$$CC /'				\
		-e '/gcc_ver=\\`/s/gcc /$$CC /'				\
		-e '/link_all_deplibs[0-9A-Z_]*=/s/=unknown/=no/'	\
		-e '/archive_expsym_cmds[0-9A-Z_]*=.$$CC.*-retain-/ {	\
		    s/-retain-symbols-file/-version-script/;		\
		    s/$$export_symbols/$$lib-ver/;			\
		    s/$$CC/echo "{ global:" > $$lib-ver~		\
		    sed -e "s|$$|;|" < $$export_symbols >> $$lib-ver~	\
		    echo "local: *; };" >> $$lib-ver~&/; }'		\
		-e '/objformat=/s/echo aout/echo elf/'			\
		-e '/STRIP -V/s/"GNU strip"/"strip"/'			\
		-e "/freebsd-elf\\*)/,/;;/ {				\
		    /deplibs_check_method=/s/=.*/=pass_all/;		\
		    /library_names_spec=.*\\.so/			\
		    s/=.*/='\$$libname\$$release.so\$$versuffix		\
			\$$libname\$$release.so\$$major \$$libname.so'	\
		    soname_spec='\$$libname\$$release.so\$$major'/;	\
		    /library_names_spec=.*shared_ext/			\
		    s/=.*/='\$$libname\$$release\$$shared_ext\$$versuffix \
			\$$libname\$$release\$$shared_ext\$$major	\
			\$$libname\$$shared_ext'			\
		    soname_spec='\$$libname\$$release\$$shared_ext\$$major'/; \
		    }" $${i} && touch -mr $${i}.libtool.bak $${i}; done

	@find ${WORKDIR} -type f -name ltmain.sh |			\
		xargs sed -i .bak				\
		-e '/case $$version_type in/,+2				\
		    s/darwin|linux|/darwin|freebsd-elf|linux|/'		\
		-e '/freebsd-elf)/,+2 {					\
		    /major=/s/=.*/=.$$(($$current - $$age))/;		\
		    /versuffix=/s/=.*/="$$major.$$age.$$revision"/; }'	\
		-e '/if.*linkmode.*prog.*mode.*!= relink/s/if.*;/if :;/'\
		-e '/if.*prog.*linkmode.*relink !=.*mode/s/if.*;/if :;/'\
		-e '/if.*linkmode.*prog.*mode.* = relink/s/||.*;/;/'	\
		-e '/if.*prog.*linkmode.*relink = .*mode/s/||.*;/;/'	\
		-e 's/|-p|-pg|/|-B*|-fstack-protector*|-p|-pg|/'

