cmake_minimum_required(VERSION 3.18)
project(igraph_test)

find_package(igraph REQUIRED)

add_executable(igraph_test igraph_test.c)
target_link_libraries(igraph_test PUBLIC igraph::igraph)