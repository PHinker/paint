
SOURCE = callbacks.cpp graphics.cpp util.cpp shape.cpp rectangle.cpp \
         screen.cpp globals.cpp line.cpp ellipse.cpp filledellipse.cpp \
         filledrectangle.cpp

OBJS = $(SOURCE:%.cpp=%.o) main.o
INCLUDES = $(SOURCE:%.cpp=%.h)

LIBS = -lglut -lGLU -lGL -lm
CC = g++
CXXFLAGS = -std=c++11 -g -Wall

all: main

main: main.o $(OBJS) $(INCLUDES)
	$(CC) -o main $(OBJS) $(LIBS)

clean :
	rm -rf $(OBJS) main
