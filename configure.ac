AC_INIT([theciphers], [0.0.1], [igordeoliveirasa@gmail.com])
AC_CONFIG_SRCDIR([src/commons/commons.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AM_INIT_AUTOMAKE
AC_CONFIG_MACRO_DIR([m4])
AM_MAINTAINER_MODE([disable])
CXXFLAGS="-std=c++11 -stdlib=libc++"
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([float.h stddef.h stdlib.h string.h strings.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([dup2 memset rmdir strcasecmp strchr strdup strerror])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_CONFIG_SUBDIRS([deps/gmock-1.7.0])
AC_OUTPUT
