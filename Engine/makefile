#
# Makefile for SpaceRace
# Compiler: clang
# Linker: g++
#

EXEC = ../build/stage3-$(UNAME)

SOURCES = $(wildcard *.cpp) #$(wildcard Engine/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o) #$(TINYXMLOBJ) #$(wildcard Engine/*.o)

COMPILER := g++
LINKER := g++
REMOVE := rm
LFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lBox2D
CFLAGS = -DTIXML_USE_STL

TOREMOVE = $(OBJECTS)

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
	REMOVE := cmd /C del
	TOREMOVE = $(subst /,\,${OBJECTS})
endif

#ALL
all : $(EXEC)

#engine :
#	cd Engine; make -j 10

debug : CFLAGS += -O0 -g
debug : $(EXEC)

release : CFLAGS += -O2
release : $(EXEC)

#Kjør
run: debug
	$(EXEC)

#TinyXML
#tinyxml : $(TINYXMLOBJ)

#Doxygen
#doxygen : $(SOURCES)
#	cd Engine; doxygen

engine : FORCE
	make -C Engine

FORCE :

clean :
	$(REMOVE) $(TOREMOVE)
	#$(REMOVE) *.o Engine/*.o

$(EXEC) : $(OBJECTS) engine
	$(LINKER) $(OBJECTS) $(LFLAGS) Engine\libengine.a -o $(EXEC)

#Kompiler .cpp filer
%.o : %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@
