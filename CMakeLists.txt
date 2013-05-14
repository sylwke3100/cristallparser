cmake_minimum_required (VERSION 2.6)
project (CristallParser)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
add_library(CristallParser SHARED CristallGrammar.cpp CristallParser.cpp CristallValues.cpp)

