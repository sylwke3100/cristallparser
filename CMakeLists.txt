cmake_minimum_required (VERSION 2.6)
project (libcristallparser)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3" )
FILE(GLOB libCristallParserHeader *.h)
FILE(GLOB libCristallParserSrc *.cpp)
set (libCristallParserLib
		libcristallparser.so
	)
add_library(cristallparser SHARED ${libCristallParserSrc})
install(FILES ${libCristallParserHeader} DESTINATION /usr/local/include/cristallparser)
install(FILES ${libCristallParserLib} DESTINATION /usr/local/lib)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake)
