AC_INIT([exercise3], [1.0])
AM_INIT_AUTOMAKE()
AC_CONFIG_HEADERS([config.h])

AC_PROG_CC

AC_ARG_WITH([libxml2],
    [AS_HELP_STRING([--with-libxml2], [Use libxml2 to generate output])],
    [with_libxml2=$withval], [with_libxml2=no])

if test "$with_libxml2" != "no"; then
    PKG_CHECK_MODULES([LIBXML2], [libxml-2.0])
    AC_DEFINE([WITH_LIBXML2], [1], [Define if building with libxml2])
    CFLAGS="$CFLAGS $LIBXML2_CFLAGS"
    AC_CHECK_FUNCS([xmlBufferCreate], [],
       [AC_MSG_FAILURE([Couldn't find xmlBufferCreate in libxml2])])
else
    AC_MSG_WARN([libxml2 not used])
fi

AC_SEARCH_LIBS([gethostbyname], [nsl])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
