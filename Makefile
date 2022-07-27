TARGET = ./build/mylang
TEST_TARGET = ./build/mylang_test

SRC_EXT  = cpp
INC_EXT  = h

SCRS_DIR = scr
SCRS     = $(wildcard $(SCRS_DIR)/*.$(SRC_EXT))

TEST_DIR = test
TEST_SCRS= $(wildcard $(TEST_DIR)/*.$(SRC_EXT))
CC = g++
CFLAGS = -g -O1 -Wall

run: 
	g++ $(CFLAGS) $(SCRS) -o $(TARGET) 

utest:
	g++ $(TEST_SCRS) -o $(TEST_TARGET) -lCppUTest