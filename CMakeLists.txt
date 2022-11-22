cmake_minimum_required(VERSION 3.0)
project(ultraServer)

include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)

# 指定编译选项
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++11 -O0 -ggdb -Wall -Werror")

# -rdynamic: 将所有符号都加入到符号表中，便于使用dlopen或者backtrace追踪到符号
# -fPIC: 生成位置无关的代码，便于动态链接
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -fPIC")

# -Wno-unused-function: 不要警告未使用函数
# -Wno-builtin-macro-redefined: 不要警告内置宏重定义，用于重定义内置的__FILE__宏
# -Wno-deprecated: 不要警告过时的特性
# -Wno-deprecated-declarations: 不要警告使用带deprecated属性的变量，类型，函数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated -Wno-deprecated-declarations")

include_directories(.)

option(BUILD_TEST "ON for complile test" ON)

set(LIB_SRC
        ultra/log.cpp
        ultra/util.cpp
        ultra/mutex.cpp
        ultra/env.cpp
        ultra/config.cpp
        ultra/thread.cpp
        ultra/fiber.cpp
        ultra/scheduler.cpp
        ultra/iomanager.cpp
        ultra/timer.cpp
        ultra/hook.cpp
        ultra/fd_manager.cpp
        ultra/address.cpp
        ultra/socket.cpp
        ultra/bytearray.cpp
        ultra/stream.cpp
        ultra/streams/socket_stream.cpp
        ultra/tcp_server.cpp
        ultra/uri.cpp
        )

add_library(ultra SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(ultra)

set(LIBS
        ultra
        pthread
        dl
        yaml-cpp
        )

if(BUILD_TEST)
    ultra_add_executable(test_log "tests/test_log.cpp" ultra "${LIBS}")
    ultra_add_executable(test_util "tests/test_util.cpp" ultra "${LIBS}")
    ultra_add_executable(test_env "tests/test_env.cpp" ultra "${LIBS}")
    ultra_add_executable(test_config "tests/test_config.cpp" ultra "${LIBS}")
    ultra_add_executable(test_thread "tests/test_thread.cpp" ultra "${LIBS}")
    ultra_add_executable(test_fiber "tests/test_fiber.cpp" ultra "${LIBS}")
    ultra_add_executable(test_scheduler "tests/test_scheduler.cpp" ultra "${LIBS}")
    ultra_add_executable(test_iomanager "tests/test_iomanager.cpp" ultra "${LIBS}")
    ultra_add_executable(test_timer "tests/test_timer.cpp" ultra "${LIBS}")
    ultra_add_executable(test_hook "tests/test_hook.cpp" ultra "${LIBS}")
    ultra_add_executable(test_address "tests/test_address.cpp" ultra "${LIBS}")
    ultra_add_executable(test_socket_client "tests/test_socket_client.cpp" ultra "${LIBS}")
    ultra_add_executable(test_socket_server "tests/test_socket_server.cpp" ultra "${LIBS}")
    ultra_add_executable(test_bytearray "tests/test_bytearray.cpp" ultra "${LIBS}")
    ultra_add_executable(test_tcp_server "tests/test_tcp_server.cpp" ultra "${LIBS}")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)