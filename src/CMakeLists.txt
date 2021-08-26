cmake_minimum_required(VERSION 2.8)
project(ExtendPythonSimple)


#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(hello_object wrapper.cpp)
add_library(hello_ext SHARED ${hello_object})
set_target_properties(hello_ext PROPERTIES PREFIX "")

#add_executable(hello main.cpp)
#target_link_libraries(hello pthread boost_python)

#dependencies
INCLUDE(FindPkgConfig)
pkg_check_modules(PYTHON REQUIRED python)
include_directories(/usr/include ${PYTHON_INCLUDE_DIRS})
target_link_libraries(hello_ext boost_python)