cmake_minimum_required(VERSION 3.13)
project(QtOpenGL)

set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
# 自动添加CMAKE_CURRENT_BINARY_DIR和CMAKE_CURRENT_SOURCE_DIR
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct Cmake to run moc automatically when needed
# 打开Qt的MOC功能和UIC文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Set CMAKE_PREFIX_PATH to find Qt5 Package 设置前缀路径以寻找Qt5的库
set(CMAKE_PREFIX_PATH /home/penglei/software/Qt5.12.0/5.12.0/gcc_64)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5OpenGL)

# 将输出重定向到bin子目录
# 根据编译的不同的平台，将最终结果输出到不同版本里
# cmake -DCMAKE_BUILD_TYPE=Debug/Release
if (CMAKE_BUILD_TYPE MATCHES "Debug"
        OR CMAKE_BUILD_TYPE MATCHES "None")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/debug)
    #message(STATUS "CMAKE_BUILD_TYPE is Debug")
elseif (CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/release)
    #message(STATUS "CMAKE_BUILD_TYPE is Release")
elseif (CMAKE_BUILD_TYPE MATCHES "RelWitchDebInfo")
    #message(STATUS "CMAKE_BUILD_TYPE is RelWitchDebInfo")
elseif (CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
    #message(STATUS "CMAKE_BUILD_TYPE is MinSizeRel")
else ()
    #message(STATUS "unknown CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
endif ()

aux_source_directory(./src CURRENT_SRCS_DIR)

add_executable(QtOpenGL ${CURRENT_SRCS_DIR})

set(TARGET_LIB
        "/usr/lib/x86_64-linux-gnu/libGL.so"
        "/usr/lib/x86_64-linux-gnu/libGLU.so"
        "/usr/lib/x86_64-linux-gnu/libGLEW.so"
        "/usr/lib/x86_64-linux-gnu/libdl.so"
        )

# Use the Widgets module from Qt 5.
target_link_libraries(QtOpenGL ${TARGET_LIB} Qt5::OpenGL Qt5::Core Qt5::Widgets Qt5::Gui)