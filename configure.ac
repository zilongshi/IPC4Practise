#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([exec], [0.01], [zilongshi.com])
AC_CONFIG_SRCDIR([sys/debug.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([mkfifo])

AM_INIT_AUTOMAKE([1.15 subdir-objects -Wall -Werror])
AC_OUTPUT([Makefile pipe/Makefile named_pipe/Makefile xsi_messages/Makefile])
