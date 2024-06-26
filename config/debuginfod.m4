dnl Copyright (C) 1997-2020 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

AC_DEFUN([AC_DEBUGINFOD],
[
# Handle optional debuginfod support as well as optional section
# downloading support.
#
# Define HAVE_LIBDEBUGINFOD if libdebuginfod is found with version >= 0.179.
#
# Define HAVE_LIBDEBUGINFOD_FIND_SECTION if libdebuginfod is found with
# version >= 0.188.
AC_ARG_WITH([debuginfod],
  AS_HELP_STRING([--with-debuginfod], [Enable debuginfo lookups with debuginfod (auto/yes/no)]),
  [], [with_debuginfod=auto])
AC_MSG_CHECKING([whether to use debuginfod])
AC_MSG_RESULT([$with_debuginfod])

if test "x$with_debuginfod" != xno; then
  PKG_CHECK_MODULES([DEBUGINFOD], [libdebuginfod >= 0.188],
    [AC_DEFINE([HAVE_LIBDEBUGINFOD_FIND_SECTION], [1],
               [Define to 1 if debuginfod section downloading is supported.])],
    [AC_MSG_WARN([libdebuginfod is missing or some features may be unavailable.])])

  PKG_CHECK_MODULES([DEBUGINFOD], [libdebuginfod >= 0.179],
    [AC_DEFINE([HAVE_LIBDEBUGINFOD], [1], [Define to 1 if debuginfod is enabled.])],
    [if test "x$with_debuginfod" = xyes; then
       AC_MSG_ERROR(["--with-debuginfod was given, but libdebuginfod is missing or unusable."])
     else
       AC_MSG_WARN([libdebuginfod is missing or unusable; some features may be unavailable.])
     fi])
else
  AC_MSG_WARN([debuginfod support disabled; some features may be unavailable.])
fi
])
