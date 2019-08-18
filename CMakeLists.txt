#Set minimum version requered
cmake_minimum_required(VERSION 2.4.6)

add_compile_options(-std=c++11)

#set project name
project(JAY)

#OpenCV
find_package(OpenCV REQUIRED)

add_executable(face_detection ./main.cpp)

target_link_libraries(face_detection ${OpenCV_LIBS})

