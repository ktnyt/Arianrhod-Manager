#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Arianrhod-Manager], [1.0.0], [kotone.nyan@gmail.com])
AM_INIT_AUTOMAKE([foreign 1.14])
AC_CONFIG_SRCDIR([src/arianrhod.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([curses], [initscr])

# Checks for header files.
AC_CHECK_HEADERS([curses.h locale.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
