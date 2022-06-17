CC=gcc
CFLAGS=-g -Wall -D_GNU_SOURCE -std=c99
OBJS=hashtable.o hashtablechaining.o hashtablelinearprobing.o
BIN=main
SUBMITNAME=project.zip

all:$(BIN)

main:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

%o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r main *.o *.dSYM $(SUBMITNAME)

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)
