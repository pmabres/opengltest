CC = gcc

glfw_inc = include
glfw_lib = lib

INCLUDES = -I$(glfw_inc)
LIBRARIES = -L$(glfw_lib)

CXXFLAGS   = $(INCLUDES)
CXXFLAGS  += -O3
CXXFLAGS  += -std=c++0x
CXXFLAGS  += -pg -D_DEBUG -g -Wall

LDFLAGS = $(LIBRARIES) -lglfw3 -lGLEW -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -ldl -lGL -lm -lpthread -lstdc++

TARGET = main
OBJECTS = main.cpp

target: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o main $(LDFLAGS)

all:target