cmake_minimum_required (VERSION 2.6)
project (cristallparser)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3" )
set (libCristallParserSrc
		CristallGrammar.cpp 
		CristallParser.cpp 
		CristallValues.cpp
	)
set (libCristallParserHeader
		CristallGrammar.h 
		CristallParser.h
		CristallValues.h
	)
set (libCristallParserLib
		libcristallparser.so
	)
add_library(cristallparser SHARED ${libCristallParserSrc})
install(FILES ${libCristallParserHeader} DESTINATION /usr/local/include/cristallparser)
install(FILES ${libCristallParserLib} DESTINATION /usr/local/lib)