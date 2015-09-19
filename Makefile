
SOURCE = callbacks.cpp main.cpp graphics.cpp util.cpp shape.cpp rectangle.cpp \
         screen.cpp globals.cpp line.cpp

OBJS = $(SOURCE:%.cpp=%.o)

LIBS = -lglut -lGLU -lGL -lm
CC = g++
CXXFLAGS = -std=c++11 -g -Wall

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS) $(LIBS)
	
clean :
	rm -rf $(OBJS) main
