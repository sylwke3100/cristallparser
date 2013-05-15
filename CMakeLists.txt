cmake_minimum_required (VERSION 2.6)
project (CristallParser)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3" )
set (libCristallParser 
		CristallGrammar.cpp 
		CristallParser.cpp 
		CristallValues.cpp
	)
add_library(CristallParser SHARED ${libCristallParser})
