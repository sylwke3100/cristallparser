TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# allow C++11
QMAKE_CXXFLAGS += -std=c++11

# Warn about everything!!!1
QMAKE_CXXFLAGS += -pedantic -Wall -Wextra -Wdouble-promotion -Wpacked
QMAKE_CXXFLAGS += -Wuninitialized -Winit-self -Wshadow -Wconversion -Wredundant-decls

SOURCES += \
	CristallValues.cpp \
	CristallParser.cpp \
	CristallGrammar.cpp \
	main.cpp

HEADERS += \
	CristallValues.h \
	CristallParser.h \
	CristallHeader.h \
	CristallGrammar.h

