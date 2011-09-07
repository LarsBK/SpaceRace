#
# Makefile for SpaceRace
# Compiler: clang
# Linker: g++
#

UNAME = $(shell uname)
EXEC = ../build/stage3-$(UNAME)
SOURCES = $(wildcard *.cpp) $(wildcard Engine/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

ifeq ($(UNAME),Darwin)
	COMPILER := clang
	LINKER := g++
	CFLAGS := -framework sfml-system -framework sfml-window -framework sfml-graphics -lBox2D
	REMOVE := rm
	#EXEC = ../build/stage3.app/Content/MacOS/stage3-$(UNAME)
endif

ifeq ($(UNAME),Linux)
	COMPILER := clang
	LINKER := clang
	CFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
	REMOVE := rm
endif

#WINDOWS
ifeq ($(UNAME),Windows)
	COMPILER := g++
	LINKER := g++
	CFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
	REMOVE := del
endif


$(EXEC) : $(OBJECTS)
	$(LINKER) $(OBJECTS) $(CFLAGS) -o $(EXEC)

#Kompiler .cpp filer
build/%.o : %.cpp
	$(COMPILER) -c $< -o $@
clean:
	$(REMOVE) $(EXEC) $(OBJECTS)

#Kjør
run: $(EXEC)
	$(EXEC)

#Doxygen
doxygen : $(SOURCES)
	doxygen

#ALL
all : $(doxygen) $(run)
	
