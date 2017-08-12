#
#  Makefile
#

CFLAGS = -Wall

all: static shared dinamic

static:
	gcc -c holalib.c $(CFLAGS)

shared:
	gcc -o $@ $^ $(CFLAGS)

dinamic:
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm demo libhola* *.o
