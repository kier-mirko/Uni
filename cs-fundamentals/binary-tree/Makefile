CC=clang
CFLAGS=-std=c11 -Weverything -O2

all: main.o str_builder.o binary_tree.o
	$(CC) $(CFLAGS) bin/main.o bin/str_builder.o bin/binary_tree.o -o main

main.o: src/main.c src/str_builder.h src/binary_tree.h
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o

str_builder.o: src/str_builder.c src/str_builder.h
	$(CC) $(CFLAGS) -c src/str_builder.c -o bin/str_builder.o

binary_tree.o: src/binary_tree.c src/binary_tree.h
	$(CC) $(CFLAGS) -c src/binary_tree.c -o bin/binary_tree.o

