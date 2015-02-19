CC = gcc
CFLAGS = -O2 -fopenmp

FF = g77
FFLAGS = -O2

all: stream

stream: stream.c
	$(CC) -c stream_locale.c
	$(CC) -c $(CFLAGS) stream.c 
	$(CC) -c stream_util.c
	$(CC) $(CFLAGS) stream_util.o stream_locale.o stream.o -o stream.x

clean:
	rm -f stream.x *.o
