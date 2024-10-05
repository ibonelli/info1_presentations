CC = gcc
CFLAGS = -Wall
DEPS = sock-lib.h sock-lib.c

all: server client
server: sock-lib.c server.c $(DEPS)
	$(CC) -o $@ sock-lib.c server.c $(CFLAGS)
client: sock-lib.c client.c $(DEPS)
	$(CC) -o $@ sock-lib.c client.c $(CFLAGS)
clean:
	rm -f client server
 
