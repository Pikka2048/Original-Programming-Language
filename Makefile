TARGET = ./build/mylang
SRCS = main.cpp parser.cpp node.cpp DebugUtl.cpp StringUtl.cpp
CC = g++

run: 
		g++ -g -Wall $(SRCS) -o $(TARGET) 