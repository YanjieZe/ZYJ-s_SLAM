cmake_minimum_required(VERSION 3.16)

project(feature_extraction)

set(CMAKE_CXX_STANDARD 14)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
ADD_EXECUTABLE(main ${DIR_SRCS} pose_estimation_2d2d.cpp feature_extraction.cpp visualOdometry.h triangulation.cpp)
target_link_libraries(main ${OpenCV_LIBS})
