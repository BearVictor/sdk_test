# CMakeLists.txt for Crad Boost Python Program
cmake_minimum_required (VERSION 3.0)
project (CradPython)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "out/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "out/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "out/lib")

set(CRAD_TOP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
set(CRAD_PYTHON_TOP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CRAD_INCLUDE_DIR "${CRAD_TOP_DIR}/include")
set(CRAD_LIB_DIR "${CRAD_TOP_DIR}/lib")
set(CRAD_SRC_DIR "${CRAD_TOP_DIR}/src")
set(CRAD_TOP_OUT_DIR "${CRAD_TOP_DIR}/out")

include_directories(${CRAD_INCLUDE_DIR})
include_directories(${CRAD_SRC_DIR})
include_directories(${CRAD_TOP_OUT_DIR}/rabbitmq/include)

#Set Python library
find_package(PythonLibs 3.6 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

#Include external libs (pybind11)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/out/include)

execute_process(COMMAND python3-config --extension-suffix OUTPUT_VARIABLE CRADPY_LIB_NAME_SUFFIX)
string(REGEX REPLACE "\n$" "" CRADPY_LIB_NAME_SUFFIX "${CRADPY_LIB_NAME_SUFFIX}")  # Strips the trailing newline

set(CRAD_BOOST_PYTHON_SRC
        cradpy.cpp
        crad_delegate_impl.cpp
    )


link_directories(${CRAD_LIB_DIR})

add_library(cradpy SHARED ${CRAD_BOOST_PYTHON_SRC})
target_link_libraries(cradpy crad)

set_target_properties(cradpy PROPERTIES PREFIX "")
set_target_properties(cradpy PROPERTIES SUFFIX "${CRADPY_LIB_NAME_SUFFIX}")

install (
    TARGETS cradpy 
    ARCHIVE DESTINATION ${CRAD_PYTHON_TOP_DIR}/lib
    LIBRARY DESTINATION ${CRAD_PYTHON_TOP_DIR}/lib
)

install(DIRECTORY DESTINATION ${CRAD_PYTHON_TOP_DIR}/../data)
