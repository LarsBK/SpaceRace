#
# Makefile for SpaceRaceEngine
# Compiler: g++
# Linker: g++
#

#Run with -j X for X threads

	
UNAME = $(shell uname)
#EXEC = ../build/stage3-$(UNAME)
SOURCES = $(wildcard *.cpp) #$(wildcard Engine/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

ifeq ($(UNAME),Darwin)
	COMPILER := g++
	LINKER := g++
	CFLAGS := -framework sfml-system -framework sfml-window -framework sfml-graphics -lBox2D
	REMOVE := rm
	#EXEC = ../build/SpaceRace.app/Contents/MacOS/SpaceRace
endif

ifeq ($(UNAME),Linux)
	COMPILER := g++
	LINKER := g++
	CFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
	REMOVE := rm
endif

#WINDOWS
ifeq ($(UNAME),Windows)
	COMPILER := g++ -m32
	LINKER := g++
	CFLAGS := -m32 -static -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
	REMOVE := del
endif

#ALL
all : $(doxygen) $(SOURCES)

debug : all
	CFLAGS := $(CFLAGS) -g -O0

release : all
	CFLAGS := $(CFLAGS) -O2

engine : $(OBJECTS)

#Doxygen
doxygen : $(SOURCES)
	doxygen

clean:
	$(REMOVE) $(OBJECTS)

#Kompiler .cpp filer
%.o : %.cpp
	$(COMPILER) -c $< -o $@
