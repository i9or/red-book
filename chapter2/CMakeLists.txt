cmake_minimum_required(VERSION 3.24)
project(chapter2 C)

add_executable(example_2_5_lines lines.c)
target_link_libraries(example_2_5_lines ${LIBS})

add_executable(example_2_6_polys polys.c)
target_link_libraries(example_2_6_polys ${LIBS})

add_executable(example_2_9_varray varray.c)
target_link_libraries(example_2_9_varray ${LIBS})

add_executable(example_2_13_draw_elements draw_elements.c)
target_link_libraries(example_2_13_draw_elements ${LIBS})

add_executable(example_2_13_draw_elements_from_file draw_elements_from_file.c)
target_link_libraries(example_2_13_draw_elements_from_file ${LIBS})