cmake_minimum_required(VERSION 2.8)
project(tutorial08)
find_package(OpenCV REQUIRED)
add_executable(tutorial08 tutorial08.cpp)
target_link_libraries(tutorial08 ${OpenCV_LIBS})
