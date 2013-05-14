cmake_minimum_required (VERSION 2.6)
project (CristallParser)

add_library(CristallParser SHARED CristallGrammar.cpp CristallParser.cpp CristallValues.cpp)

