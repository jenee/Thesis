CC    = g++
CFLAGS   = 

all: testProgram1
   
testProgram1: testProgram1.c
	$(CC) $(CFLAGS) -o $@ $^
   
clean: dummyNonExistentFile
	rm -f testProgram1 a.out
