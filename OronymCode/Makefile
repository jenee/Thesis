CC    = g++
CFLAGS   = -lsqlite3 -Wall -pedantic

all: wordBreakdown
   
wordBreakdown: wordBreakdown.cpp
	$(CC) $(CFLAGS) -o $@ $^
   
clean: 
	rm -f wordBreakdown a.out
