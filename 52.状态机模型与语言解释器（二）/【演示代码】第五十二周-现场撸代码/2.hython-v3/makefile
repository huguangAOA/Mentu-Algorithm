CC = g++
CFLAGS = -std=c++11 -DDEBUG
HYTHON_SRCS = src/*.c
SRCS = $(HYTHON_SRCS) src/*.cc main.cpp
LIB_DIR = ./libs
LIBS = $(LIB_DIR)/libantlr3c.a
INCLUDES = -I./include -I./include/antlr
OUTPUT = -o bin/hython
.PHONY: run

all : hython main.cpp
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) $(INCLUDES) $(OUTPUT) 

hython: thirdpart/hython.g
	java -jar ./thirdpart/antlr-3.4-complete.jar thirdpart/hython.g 
	mv thirdpart/*.h include
	mv thirdpart/*.c src
	mv ./hython.tokens thirdpart

run:
	./bin/hython ./bin/input1.hl
	./bin/hython ./bin/input2.hl
	./bin/hython ./bin/input3.hl
