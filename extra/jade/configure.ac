AC_REVISION($Id: configure.in,v 1.3 2001/10/14 20:27:45 adam Exp $)
AC_INIT([jade], [1.2.1])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE
TOP=`pwd`
AC_SUBST(TOP)

if test "$CXXFLAGS" = ""; then 
  CXXFLAGS="-O2"
fi

LTVERSION=`cat VERSION | cut -d'.' -f1,2 | sed 's/\./:/g'`
AC_SUBST(LTVERSION)

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_CXX
AC_PROG_CXXCPP
AC_PATH_PROGS(M4, gm4 gnum4 m4, m4)
AC_PATH_PROGS(PERL, perl, perl)
test "$INSTALL" = "./config/install.sh -c" && INSTALL=`pwd`"/config/install.sh -c"

dnl
dnl  Stuff special to GNU C++
dnl
if test "$GXX"
then
  CXXFLAGS="$CXXFLAGS -fno-implicit-templates"
fi

dnl
dnl  Checks for header files.
dnl
AC_HEADER_STDC
AC_CHECK_HEADERS(limits.h)

dnl
dnl  Checks for typedefs, structures, and compiler characteristics.
dnl
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_STRUCT_ST_BLKSIZE
AC_CACHE_CHECK(for sig_atomic_t in signal.h,
    ac_cv_have_sig_atomic_t,
    AC_TRY_LINK([#include <signal.h>],sig_atomic_t x;,
	ac_cv_have_sig_atomic_t=yes,
	ac_cv_have_sig_atomic_t=no))
if test "$ac_cv_have_sig_atomic_t" = "no"
then
    AC_CHECK_TYPE(sig_atomic_t,int)
fi

dnl
dnl the following tests require c++, not c; note that if you switch this
dnl earlier, AC_C_CONST will fail, at least
dnl
AC_LANG_CPLUSPLUS

AC_CACHE_CHECK(support for bool,
    ac_cv_typedef_bool,
    AC_TRY_LINK(,bool x; x=(false | true);,
       	ac_cv_typedef_bool=yes,
	ac_cv_typedef_bool=no))
if test "$ac_cv_typedef_bool" = "yes"
then
    AC_DEFINE(SP_HAVE_BOOL)
fi

dnl
dnl  Checks for library functions.
dnl 
AC_CHECK_FUNC(memmove,,LIBOBJS="$LIBOBJS memmove.o")
AC_CHECK_FUNC(strerror,,LIBOBJS="$LIBOBJS strerror.o")
dnl this source file doesn't exist
dnl AC_CHECK_FUNC(strtoul,,LIBOBJS="$LIBOBJS strtoul.o")

AC_CHECK_FUNC(setlocale,AC_DEFINE(SP_HAVE_LOCALE))
AC_CHECK_LIB(intl,gettext,AC_DEFINE(SP_HAVE_GETTEXT) LIBS="$LIBS -lintl")

dnl
dnl Check for thread support.
AC_CHECK_LIB(threads,cthread_fork,LIB_THREADS="-lthreads",LIB_THREADS="")
AC_SUBST(LIB_THREADS)

dnl 
dnl  ANSI templates
dnl
AC_CACHE_CHECK(for ANSI template instantiation,
               ac_cv_c_template_ansi,
               AC_TRY_LINK([
class foo {
};

template<class T> class test {
public:
 T *data();};
template class test<foo>;
],,ac_cv_c_template_ansi=yes,
   ac_cv_c_template_ansi=no))
if test "$ac_cv_c_template_ansi" = "yes"
 then
  AC_DEFINE(SP_ANSI_CLASS_INST)
fi

dnl
dnl  HTTP support
dnl
AC_ARG_ENABLE(http,
[  --enable-http           bind in support for http],
    if test $enableval
    then
	AC_DEFINE(SP_HAVE_SOCKET)
	AC_CHECK_LIB(nsl,main,LIBS="$LIBS -lnsl")
	AC_CHECK_LIB(socket,main,LIBS="$LIBS -lsocket")
	AC_MSG_CHECKING(h_errno in netdb.h)
	AC_EGREP_HEADER(h_errno,netdb.h,
	    AC_MSG_RESULT(yes),
	    AC_DEFINE(SP_DECLARE_H_ERRNO)
	    AC_MSG_RESULT(no))
    fi)

dnl
dnl  Framemaker support
dnl
AC_ARG_ENABLE(mif,
[  --enable-mif            include support for FrameMaker MIF output],
    if test $enableval
    then
	AC_DEFINE(JADE_MIF)
    fi)

dnl
dnl  HTML backend support
dnl
AC_ARG_ENABLE(html,
[  --enable-html           include support for HTML output],
    if test $enableval
    then
	AC_DEFINE(JADE_HTML)
    fi)


dnl 
dnl  Other options
dnl
AC_DEFINE(SP_MULTI_BYTE)
AC_ARG_ENABLE(default-catalog,
[  --enable-default-catalog=pathlist
                          provide one or more default catalog files or
                          sysids, e.g. /usr/local/lib/sgml/catalog],
              if test $enableval
               then
                AC_DEFINE_UNQUOTED(SGML_CATALOG_FILES_DEFAULT,"$enableval")
              fi)
AC_ARG_ENABLE(default-search-path,
[  --enable-default-search-path=pathlist
                          provide a default value for SGML_SEARCH_PATH],
    if test $enableval
    then
	AC_DEFINE_UNQUOTED(SGML_SEARCH_PATH_DEFAULT,"$enableval")
    fi)

AC_SUBST(LIBOBJS)

AM_PROG_LIBTOOL

AC_OUTPUT(Makefile lib/Makefile grove/Makefile spgrove/Makefile style/Makefile spam/Makefile nsgmls/Makefile sgmlnorm/Makefile spent/Makefile jade/Makefile sx/Makefile)
