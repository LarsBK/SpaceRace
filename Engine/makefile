#
# Makefile for SpaceRace
# Compiler: clang
# Linker: g++
#

#Run with -j X for X threads

	
UNAME = $(shell uname)
EXEC = ../build/stage3-$(UNAME)
SOURCES = $(wildcard *.cpp) $(wildcard Engine/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o) #$(wildcard Engine/*.o)

COMPILER := g++
LINKER := g++
REMOVE := rm
LFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D


ifeq ($(UNAME),Darwin)
	LFLAGS := -framework sfml-system -framework sfml-window -framework sfml-graphics -lBox2D
	#EXEC = ../build/SpaceRace.app/Contents/MacOS/SpaceRace
endif

ifeq ($(UNAME),Linux)
endif

#WINDOWS
ifeq ($(UNAME),Windows)
	LFLAGS += -static-libgcc -static-libstdc++
	#COMPILER := g++ #-m32
	#LFLAGS := -m32 -static -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
	REMOVE := del
endif

#ALL
all : $(EXEC) doxygen

#engine :
#	cd Engine; make -j 10

debug : CFLAGS += -O0 -g
debug : $(EXEC)	

release : CFLAGS += -O2
release : $(EXEC)

#Kjør
run: debug
	$(EXEC)

#Doxygen
doxygen : $(SOURCES)
	cd Engine; doxygen

clean:
	$(REMOVE) *.o Engine/*.o
	#$(EXEC) $(OBJECTS)

$(EXEC) : $(OBJECTS)
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $(EXEC)

#Kompiler .cpp filer
%.o : %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@
