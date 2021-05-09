#!/bin/bash

# Quit on error
set -e

MY_PWD=${PWD}
BUILD_SCRIPT_DIR=${MY_PWD}/../../../build
export BUILD_SCRIPT_DIR=${BUILD_SCRIPT_DIR}

echo "Include ${BUILD_SCRIPT_DIR}/common.sh"
# shellcheck source=Common/common.sh
. "${BUILD_SCRIPT_DIR}/common.sh"

LIBPYBIND11_DIR="${MY_PWD}/ext/pybind11"
LIBPYBIND11_VER=2.6.1

##############################################
# configure pybind11
configure_pybind11()
{
    if [ ! -d "$LIBPYBIND11_DIR/$LIBPYBIND11_VER" ]; then
        cd $LIBPYBIND11_DIR

        rm -rf $LIBPYBIND11_VER
        tar xzf pybind11-$LIBPYBIND11_VER.tar.gz

        cd -
    fi
}

##############################################
# Set local environments
do_set_local_environment()
{
	CRAD_PYTHON_CMAKE_BUILD_DIR="${MY_PWD}/build_${TARGET_ARCH}"
	CRAD_PYTHON_CMAKE_OPTIONS="-Dtarget_os=${TARGET_OS}"
	CRAD_PYTHON_CMAKE_OPTIONS="${CRAD_PYTHON_CMAKE_OPTIONS} -Dgtest_dir=${CRAD_TOP_OUTPUT_DIR}/gtest"
	CRAD_PYTHON_CMAKE_OPTIONS="${CRAD_PYTHON_CMAKE_OPTIONS} -Dgmock_dir=${CRAD_TOP_OUTPUT_DIR}/gmock"
	CRAD_PYTHON_CMAKE_OPTIONS="${CRAD_PYTHON_CMAKE_OPTIONS} -Dlog4cpp_dir=${CRAD_TOP_OUTPUT_DIR}/log4cpp"
  CRAD_PYTHON_CMAKE_OPTIONS="${CRAD_PYTHON_CMAKE_OPTIONS} CMakeLists.txt -B${CRAD_PYTHON_CMAKE_BUILD_DIR}"
}

##############################################
# Compile sources
do_compile()
{
	configure_pybind11

	if [ ! -e $MY_PWD/out/pybind11 ] || [ ! -e $MY_PWD/out ]; then
        do_install_pybind11
	fi

	echo "cmake ${CRAD_PYTHON_CMAKE_OPTIONS}"
	# shellcheck disable=SC2086
	cmake ${CRAD_PYTHON_CMAKE_OPTIONS}

	# shellcheck disable=SC2164
	cd "${CRAD_PYTHON_CMAKE_BUILD_DIR}" || exit
        make -j "${CRAD_BUILD_CORES}"
	cd - || exit

	do_check_error
}

##############################################
# Compile sources
do_install()
{
	cd "${CRAD_PYTHON_CMAKE_BUILD_DIR}" || exit
	make install
	cd - || exit
	do_check_error
}

# Install pybind11
function do_install_pybind11() {
    echo "Installing pybind11"
    mkdir -p $MY_PWD/out
    mkdir -p $MY_PWD/out/include
    mkdir -p $MY_PWD/out/include/pybind11


    cd ${LIBPYBIND11_DIR}/${LIBPYBIND11_VER}
    cp -r include/pybind11/* "${MY_PWD}/out/include/pybind11"
    cd -
}

##############################################
# Compile sources
do_clean()
{
	case "${1}" in
		--clean)
		rm -rf "${CRAD_PYTHON_CMAKE_BUILD_DIR}" ./bin
		echo "rm -rf ${CRAD_PYTHON_CMAKE_BUILD_DIR} ./bin"

		rm -rf "${MY_PWD}/out"
        echo "rm -rf ${MY_PWD}/out"
        rm -rf ${LIBPYBIND11_DIR}/${LIBPYBIND11_VER}
		;;
		
		*)
		echo "Invalid argument : ${1}"
		;;
	esac
	do_check_error
}

do_main(){
    do_parse_args "$1"
    do_set_environment
    do_set_local_environment
    if [ -n "${CRAD_CLEAN}" ]; then
        do_clean "${CRAD_CLEAN}"
    else
        do_compile
        do_install
    fi
}

do_main "$*"

