cmake_minimum_required(VERSION 3.24)
project(chapter1 C)

add_executable(example_1_2_hello hello.c)
target_link_libraries(example_1_2_hello ${LIBS})

add_executable(example_1_3_double double.c)
target_link_libraries(example_1_3_double ${LIBS})