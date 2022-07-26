TARGET = ./build/mylang

SRC_EXT  = cpp
INC_EXT  = h

SCRS_DIR = scr
SCRS     = $(wildcard $(SCRS_DIR)/*.$(SRC_EXT))
CC = g++
CFLAGS = -g -O1 -Wall 

run: 
	g++ $(CFLAGS) $(SCRS) -o $(TARGET) 