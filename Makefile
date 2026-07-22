CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Iinclude

.PHONY: all demo clean

all: libnu_emit.a

libnu_emit.a: src/nu_emit.c include/nu_emit.h
	$(CC) $(CFLAGS) -c src/nu_emit.c -o nu_emit.o
	ar rcs $@ nu_emit.o

demo: libnu_emit.a examples/demo.c
	$(CC) $(CFLAGS) examples/demo.c libnu_emit.a -o demo

clean:
	rm -f nu_emit.o libnu_emit.a demo demo.exe
