cmake_minimum_required(VERSION 3.24)
project(red_book C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(PROJECT_OUTPUT_BIN_DIR "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_OUTPUT_BIN_DIR}")

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories({GLUT_INCLUDE_DIR} {OPENGL_INCLUDE_DIR})

set(LIBS GLUT::GLUT OpenGL::GL)
add_compile_definitions(GL_SILENCE_DEPRECATION)

add_subdirectory(chapter1)
add_subdirectory(chapter2)
