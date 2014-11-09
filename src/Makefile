

CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall


all: main.c
	$(CC) $(CFLAGS)  XOR.c base_conversion.c main.c freq_analyze.c -lm -g -o main.o

freq: freq_analyze.c
	$(CC) $(CFLAGS) freq_analyze.c -lm -g -o freq.o

