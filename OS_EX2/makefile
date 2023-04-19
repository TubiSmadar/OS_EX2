CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=-L. -Wl,-rpath,.
LIBS=-ldl

.PHONY: all clean

all: encode decode

codecA_lib.o: codecA.c codec.h
	$(CC) $(CFLAGS) -c $< -o $@

codecB_lib.o: codecB.c codec.h
	$(CC) $(CFLAGS) -c $< -o $@

codecA.so: codecA_lib.o
	$(CC) -fPIC -shared -o $@ $<

codecB.so: codecB_lib.o
	$(CC) -shared -o $@ $<

encode.o: encode.c
	$(CC) $(CFLAGS) -c $<

decode.o: decode.c
	$(CC) $(CFLAGS) -c $<

encode: encode.o codecA_lib.o codecA.so codecB.so
	$(CC) $(LDFLAGS) -o $@ $< $(LIBS)

decode: decode.o codecA.so codecB.so
	$(CC) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f *.o *.so encode decode
