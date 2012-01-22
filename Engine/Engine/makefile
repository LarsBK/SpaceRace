#
# Makefile for SpaceRaceEngine
# Compiler: g++
# Linker: g++
#

SOURCES = $(wildcard *.cpp) 
OBJECTS = $(SOURCES:.cpp=.o)
COMPILER := g++
LINKER := g++
REMOVE := rm
CFLAGS = 

ifdef SystemRoot
	#Windows
	REMOVE := del
else
	ifeq ($(UNAME),Darwin)
		#EXEC = ../build/SpaceRace.app/Contents/MacOS/SpaceRace
	endif

	ifeq ($(UNAME),Linux)
	endif
endif

#ALL
all : doxygen release

debug :	CFLAGS := $(CFLAGS) -g -O0
debug : libengine.a

release : CFLAGS := $(CFLAGS) -O2
release : libengine.a


#Doxygen
doxygen : FORCE
	doxygen

clean:
	$(REMOVE) $(OBJECTS)

#Kompiler .cpp filer
%.o : %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@


tinyxml : FORCE
	make -C tinyxml

libengine.a : $(OBJECTS) tinyxml
	ar crvs libengine.a $(OBJECTS) tinyxml/tinystr.o tinyxml/tinyxml.o tinyxml/tinyxmlerror.o tinyxml/tinyxmlparser.o

FORCE :
