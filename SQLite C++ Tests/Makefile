CC    = g++
CFLAGS   = -lsqlite3 

all: testProgram1
   
testProgram1: testProgram1.c
	$(CC) $(CFLAGS) -o $@ $^
   
clean: 
	rm -f testProgram1 a.out
