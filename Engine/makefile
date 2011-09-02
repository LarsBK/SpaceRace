#
# Makefile for SpaceRace
# Compiler: g++
#

UNAME = $(shell uname)
EXEC = ../build/stage3-$(UNAME)
SOURCES = $(wildcard *.cpp) $(wildcard Engine/*.cpp)
#SOURCES_ENGINE = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC) : $(OBJECTS)
	g++ -o $(EXEC) -framework sfml-system -framework sfml-window -framework sfml-graphics -lBox2D $(OBJECTS)
#Engine/*.o : 
#	clang -c Engine/*.cpp
#*.o :
#	clang -c *.cpp

#Kompiler .cpp filer
%.o : %.cpp
	clang -c $< -o $@
clean:
	rm -f $(EXEC) $(OBJECTS)
