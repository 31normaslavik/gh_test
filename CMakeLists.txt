cmake_minimum_required(VERSION 3.22.1)
project(testCmake VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --verbose -static --gcc-install-dir=/usr/lib/gcc/x86_64-pc-linux-gnu/13.3.0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -v ")
message("CMAKE_CXX_PLATFORM_ID: ${CMAKE_CXX_PLATFORM_ID}")
message("CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_LINKER_ID: ${CMAKE_CXX_COMPILER_LINKER_ID}")

if(CMAKE_CXX_PLATFORM_ID STREQUAL Linux AND 
    (CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU))
    set(CMAKE_LINKER_TYPE LLD)
    message("Current linker: ${CMAKE_LINKER_TYPE}")
    message("CMAKE_LINKER_TYPE: ${CMAKE_LINKER_TYPE}")
endif()
set(CLANG_CONFIG_FILE_SYSTEM_DIR /usr/lib/gcc/x86_64-pc-linux-gnu/11.4.0)

message("CMAKE_CXX_COMPILER_LINKER: ${CMAKE_CXX_COMPILER_LINKER}")

# set(CMAKE_CXX_CREATE_STATIC_LIBRARY TRUE)
# --gcc-install-dir=/usr/lib/gcc/x86_64-pc-linux-gnu/11.4.0 
# --gcc-install-dir=/usr/lib/gcc/x86_64-pc-linux-gnu/12.3.0
# --gcc-install-dir=/usr/lib/gcc/x86_64-pc-linux-gnu/13.3.0
# --gcc-install-dir=/usr/lib/gcc/aarch64-linux-gnu/14.1.0
# --sysroot=/home/pancake/farm_tree
# --target=aarch64-linux-gnu
#   =ldd
# -stdlib=libc++
# --gcc-toolchain=
# --gcc-triple=
# --gcc-install-dir=  unsupported option only clang-16+


# set(CMAKE_CXX_COMPILER_TARGET aarch64-linux-gnu)
message("CMAKE_CXX_COMPILER_TARGET: ${CMAKE_CXX_COMPILER_TARGET}")

add_subdirectory(class)
add_executable(testCmake main.cpp)
target_link_libraries(testCmake PUBLIC mylib)

message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message("CMAKE_INSTALL_LIBDIR: ${CMAKE_INSTALL_LIBDIR}")

include(CTest)
enable_testing()

add_test(NAME test COMMAND  ${${PROJECT_NAME}_BINARY_DIR}/testCmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(GNUInstallDirs)
install(
    TARGETS testCmake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

