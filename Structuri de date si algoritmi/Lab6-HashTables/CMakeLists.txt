cmake_minimum_required(VERSION 3.20)
project(sdaLR)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} App.cpp Colectie.cpp Colectie.h IteratorColectie.cpp IteratorColectie.h TestExtins.cpp TestExtins.h TestScurt.cpp TestScurt.h)
