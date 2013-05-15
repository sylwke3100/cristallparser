cmake_minimum_required (VERSION 2.6)
project (CristallParser)
<<<<<<< HEAD
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
add_library(CristallParser SHARED CristallGrammar.cpp CristallParser.cpp CristallValues.cpp)

=======
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3" )
set (libCristallParser 
		CristallGrammar.cpp 
		CristallParser.cpp 
		CristallValues.cpp
	)
add_library(CristallParser SHARED ${libCristallParser})
>>>>>>> ad352edff15d
