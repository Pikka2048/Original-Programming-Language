#Name 
TARGET = ./build/mylang
TEST_TARGET = ./build/test

#Extension
SRC_EXT  = cpp
INC_EXT  = h

#Program Location
SCRS_DIR = scr
SCRS     = $(wildcard $(SCRS_DIR)/*.$(SRC_EXT))

#Test Program Location
TEST_DIR = test
TEST_SCRS= $(wildcard $(TEST_DIR)/*.$(SRC_EXT))

#Make Shared Static Library
LIB_SCR_DIR = scr/utility
LIB_OUTPUT = lib
LIB_DIR = lib

LIBARGS = -lStringUtl -lDebugUtl

LIB_DEBUG_UTL = DebugUtl
LIB_STRING_UTL = StringUtl

#C++ Compiler Option
CC = g++
CFLAGS = -g -Wall


run: 
	g++ $(CFLAGS) $(SCRS) -o $(TARGET) -L$(LIB_DIR) $(LIBARGS)

utest:
	g++ $(TEST_SCRS) -o $(TEST_TARGET) -L$(LIB_DIR) $(LIBARGS) -lCppUTest

$(LIB_DEBUG_UTL):
	g++ -shared -o $(LIB_OUTPUT)/lib$(LIB_DEBUG_UTL).so -c $(LIB_SCR_DIR)/$(LIB_DEBUG_UTL).$(SRC_EXT)

$(LIB_STRING_UTL):
	g++ -shared -o $(LIB_OUTPUT)/lib$(LIB_STRING_UTL).so -c $(LIB_SCR_DIR)/$(LIB_STRING_UTL).$(SRC_EXT)