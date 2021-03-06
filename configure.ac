AC_PREREQ(2.59)
AC_INIT([Cigma], [0.9.1], [cig-cs@geodynamics.org], [cigma])
AC_CONFIG_AUX_DIR([./aux-config])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])



CIGMA_OPTIONS_ZLIB
CIGMA_OPTIONS_HDF5
CIGMA_OPTIONS_VTK



dnl Get the operating system name
UNAME=`uname`

dnl Check for default compilers
AC_PROG_CC
AC_PROG_CXX
#if test "x${CC}" = "x" -o "x${CXX}" = "x"; then
#    AC_MSG_ERROR([Could not find required compilers, aborting.])
#fi
#LINKER="${CXX}"

dnl Use C++ for all compilation tests
AC_LANG(C++)

dnl Set default flags
#FLAGS="-Wall"
#OPTIM="-g -O2"

dnl Check for various programs
AC_PROG_CPP

dnl How to build static libraries?
AC_PROG_RANLIB
#case "$UNAME" in
#  Darwin*)
#    AR="libtool -o"
#    RANLIB=true
#    ;;
#  *)
#    AC_PROG_RANLIB
#    AC_PATH_PROG(AR, ar)
#    if test "x${AR}" = "x"; then
#        AC_MSG_ERROR([Could not find the library archiver, aborting.])
#    fi
#    AR="${AR} ruvs"
#    ;;
#esac

dnl See if we need a .exe extension on executables
AC_EXEEXT


dnl Check for standard math library
AC_CHECK_LIB(m,main)


dnl Check for the python include directories
CIT_PYTHON_SYSCONFIG
CIGMA_PATH_NUMPY

dnl Check for zlib and hdf5
CIGMA_PATH_ZLIB
CIGMA_PATH_HDF5(
    [echo "Found HDF5 library!"],
    [AC_MSG_ERROR([HDF5 library not found; try specifying its prefix with the configure option --with-hdf5])])

dnl Work-around MPICH SEEK_XXX issues, etc.
CIGMA_PARALLEL_HDF5(
    [CIT_HEADER_MPI],
    [])

dnl Check for vtk-5.0
AM_PATH_VTK(
    [],
    [echo "Found VTK library!"],
    [AC_MSG_ERROR([VTK5 library not found; try specifying its prefix with the configure option --with-vtk])])



dnl Write output

#AC_SUBST(UNAME)
#AC_SUBST(FLAGS)
#AC_SUBST(OPTIM)
#AC_SUBST(LINKER)
AC_SUBST(CIGMA_DIRS)
AC_SUBST(CIGMA_LIBS)
#AC_SUBST(AR)

AC_SUBST(VTK_INCLUDES)
AC_SUBST(VTK_LIBS)
AC_SUBST(VTK_LDFLAGS)

AC_SUBST(HDF5_INCLUDES)
AC_SUBST(HDF5_LIBS)
AC_SUBST(HDF5_LDFLAGS)

AC_SUBST(PYTHON_INCLUDES)
AC_SUBST(PYTHON_LIBS)
AC_SUBST(PYTHON_LDFLAGS)

AC_CONFIG_FILES([variables
                 Makefile
                 src/Makefile
                 ])

AC_OUTPUT


dnl Print some information
echo "********************************************************************"
echo "Cigma is configured with"
echo "- OS              : $UNAME"
echo "- C compiler      : $CC"
echo "- C++ compiler    : $CXX"
echo "- HDF5 includes   : $HDF5_INCLUDES"
echo "- HDF5 libs       : $HDF5_LIBS"
echo "- HDF5 ldflags    : $HDF5_LDFLAGS"
echo "- VTK includes    : $VTK_INCLUDES"
echo "- VTK libs        : $VTK_LIBS"
echo "- VTK ldflags     : $VTK_LDFLAGS"
echo "- Python includes : $PYTHON_INCLUDES"
echo "- Python libs     : $PYTHON_LIBS"
echo "- Python ldflags  : $PYTHON_LDFLAGS"
#echo "- Linker       : $LINKER"
#echo "- Optimization : $OPTIM"
#echo "- Options      : $FLAGS"
