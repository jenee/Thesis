CC    = g++
CFLAGS   = -lsqlite3 -Wall -pedantic

all: wordBreakdown
   
wordBreakdown: wordBreakdown.cpp wordBreakdown.h
	$(CC) $(CFLAGS) -g -o $@ $^

noGDB: wordBreakdown.cpp wordBreakdown.h
	$(CC) $(CFLAGS)  -o wordBreakdown $^

clean: 
	rm -rf wordBreakdown a.out wordBreakdown.dSYM
