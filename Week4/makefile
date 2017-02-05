CC=gcc
CLAGS=-I
DEPS=apue.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: cat chmod hole ls lsb

cat: simple-cat.o
	gcc -o simple-cat simple-cat.o -I .

chmod: simple-chmod.o
	gcc -o simple-chmod  simple-chmod.o -I .

hole: simple-hole.o
	gcc -o simple-hole simple-hole.o -I .

ls: simple-ls.o
	gcc -o simple-ls simple-ls.o -I .

lsb: simple-ls2.o
	gcc -o simple-ls2 simple-ls2.o -I .
