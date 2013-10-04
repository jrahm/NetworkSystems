
CC=gcc
CFLAGS:=-Wall -Wextra -g3 -ggdb
OBJS:=blockqueue.o gbn_read.o gbn_socket.o gbn_write.o
LDFLAGS:=-lpthread
CLIENT:=client
SERVER:=server
DEBUGFLAGS=-DDEBUG4

all: $(OBJS) gbn_client.o gbn_server.o
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(CLIENT) $(OBJS) gbn_client.o $(LDFLAGS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(SERVER) $(OBJS) gbn_server.o $(LDFLAGS)

blockqueue.o: blockqueue.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ -c $<

gbn_client.o: gbn_client.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ -c $<

gbn_read.o: gbn_read.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ -c $<

gbn_socket.o: gbn_socket.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ -c $<

gbn_write.o: gbn_write.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ -c $<

clean:
	rm *.o client