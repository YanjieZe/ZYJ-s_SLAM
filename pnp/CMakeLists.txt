cmake_minimum_required(VERSION 3.16)
project(pnp)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(pnp main.cpp)
target_link_libraries(pnp ${OpenCV_LIBS})