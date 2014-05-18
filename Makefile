# Created by RILDER: DO NOT EDIT! ;)

default_target: all_rules

#=============================================================================
# Set environment variables for the build.

LIB = ./lib/
SRC = ./src/
INCLUDE = ./include/
CC = gcc
CFLAGS = -I ${INCLUDE} -O3 -Wall -lm

#=============================================================================
# Target rules:

all_rules: swbprng

${LIB}swbprng.o: ${SRC}swbprng.c ${INCLUDE}swbprng.h
	${CC} -c ${SRC}swbprng.c -o ${LIB}swbprng.o ${CFLAGS}

${LIB}main.o: ${SRC}main.c ${INCLUDE}swbprng.h
	${CC} -c ${SRC}main.c -o ${LIB}main.o ${CFLAGS}

swbprng: ${LIB}main.o ${LIB}swbprng.o
	${CC} ${LIB}main.o ${LIB}swbprng.o -o swbprng ${CFLAGS}

# Clean:

clean:
	mkdir ${LIB}; rm swbprng ${LIB}*.o ${SRC}*~ ${INCLUDE}*~ *~

