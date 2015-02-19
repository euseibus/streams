CC = gcc
CFLAGS = -O2 -fopenmp

FF = g77
FFLAGS = -O2

all: stream

stream_c: stream.c
	$(CC) $(CFLAGS) stream.c -o stream.x

clean:
	rm -f stream.x *.o
