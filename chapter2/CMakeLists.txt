cmake_minimum_required(VERSION 3.24)
project(chapter2 C)

add_executable(example_2_5_lines lines.c)
target_link_libraries(example_2_5_lines ${LIBS})

add_executable(example_2_6_polys polys.c)
target_link_libraries(example_2_6_polys ${LIBS})