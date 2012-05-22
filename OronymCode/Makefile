CC    = g++
CFLAGS   = -lsqlite3 -Wall -pedantic

all: test
   
test: wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^

#wordBreakdown: wordBreakdown.cpp wordBreakdown.h
#	$(CC) $(CFLAGS) -g -o $@ $^

noGDB: wordBreakdown.cpp wordBreakdown.h
	$(CC) $(CFLAGS)  -o wordBreakdown $^

clean: 
	rm -rf wordBreakdown a.out *.dSYM testWordBreakdown
