cmake_minimum_required(VERSION 3.8.0)
project(C-Primer)
set(CMAKE_CXX_STANDARD 20)
#设置输出exe路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
message(STATUS "source path: ${EXECUTABLE_OUTPUT_PATH}")
#搜索src目录下的源文件
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
#生成可执行文件
add_executable(app main.cpp ${SRC_LIST})
