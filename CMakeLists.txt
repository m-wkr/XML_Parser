cmake_minimum_required(VERSION 3.30)
project(XML_parser)

add_executable(XML_parser main.cpp)
add_library(lexer STATIC lexer.cpp)
add_library(parser STATIC parser.cpp)

target_link_libraries(XML_parser lexer parser)