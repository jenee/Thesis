CC    = g++
CFLAGS   = -lsqlite3 -Wall -pedantic

all: wordBreakdown
   
wordBreakdown: wordBreakdown.cpp
	$(CC) $(CFLAGS) -o $@ $^

forgdb: wordBreakdown.cpp
	$(CC) $(CFLAGS) -g -o wordBreakdown $^

clean: 
	rm -rf wordBreakdown a.out wordBreakdown.dSYM
