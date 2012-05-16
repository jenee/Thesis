CC    = g++
CFLAGS   = -lsqlite3 

all: simpleExample
   
simpleExample: simpleExample.c
	$(CC) $(CFLAGS) -o $@ $^
   
clean: 
	rm -f simpleExample a.out
