#
# Makefile for SpaceRace
# Compiler: clang
# Linker: g++
#

#Run with -j X for X threads

	
UNAME = $(shell uname)
EXECFILE = ./stage3-$(UNAME)
EXEC = ../build/$(EXECFILE)

TINYXMLSRC = tinyxml/tinystr.cpp tinyxml/tinyxml.cpp tinyxml/tinyxmlerror.cpp tinyxml/tinyxmlparser.cpp
TINYXMLOBJ =  $(TINYXMLSRC:.cpp=.o)

SOURCES = $(wildcard *.cpp) $(wildcard Engine/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o) $(TINYXMLOBJ) #$(wildcard Engine/*.o)

COMPILER := g++
LINKER := g++
REMOVE := rm
LFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
CFLAGS = -DTIXML_USE_STL


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
	cd ../build/ && $(EXECFILE)

#TinyXML
tinyxml : $(TINYXMLOBJ)

#Doxygen
doxygen : $(SOURCES)
	cd Engine; doxygen

clean :
	$(REMOVE) $(EXEC) $(OBJECTS)
	#$(REMOVE) *.o Engine/*.o

$(EXEC) : $(OBJECTS) tinyxml
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $(EXEC)

#Kompiler .cpp filer
%.o : %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@
