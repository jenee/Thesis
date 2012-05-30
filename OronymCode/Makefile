CC    = g++
CFLAGS   = -lsqlite3  -pedantic

all: treeGUI
  
treeGUI:  wordBreakdown.* wordTreeDraw.* ../LTreeLighting/*.h ../LTreeLighting/*.cpp
	$(CC) $(CFLAGS) -framework GLUT -framework OpenGL  -g -o $@ $^
   
test: wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^

warnings: wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	$(CC) $(CFLAGS) -Wall -g -o testWordBreakdown $^

#wordBreakdown: wordBreakdown.cpp wordBreakdown.h
#	$(CC) $(CFLAGS) -g -o $@ $^

noGDB: wordBreakdown.cpp wordBreakdown.h
	$(CC) $(CFLAGS)  -o wordBreakdown $^

clean: 
	rm -rf wordBreakdown a.out *.dSYM testWordBreakdown treeGUI
