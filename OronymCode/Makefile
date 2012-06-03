CC    = g++
CFLAGS   = -lsqlite3  -pedantic

all: treeGUI
  
treeGUI: cleanTreeGUI wordBreakdown.* ../LTreeLighting/*.h ../LTreeLighting/*.cpp
	echo "--------------------------COMPILE treeGUI----------------------------"
	$(CC) $(CFLAGS) -framework GLUT -framework OpenGL  -g -o $@ $^
   
test: cleanTest wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	echo "----------------------COMPILE testWordBreakdown----------------------"
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^

runTest: test wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	echo "......................RUN testWordBreakdown......................"
	./testWordBreakdown all

warnings: wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	echo "------------COMPILE testWordBreakdown with ALL warnings----------------"
	$(CC) $(CFLAGS) -Wall -g -o testWordBreakdown $^

#wordBreakdown: wordBreakdown.cpp wordBreakdown.h
#	$(CC) $(CFLAGS) -g -o $@ $^

noGDB: wordBreakdown.cpp wordBreakdown.h
	echo "-------------------------------------noGDB----------------------------"
	$(CC) $(CFLAGS)  -o wordBreakdown $^

cleanTest: 
	echo "-----------------------------------CLEAN----------------------------"
	rm -rf  *.dSYM testWordBreakdown

cleanTreeGUI: 
	echo "-----------------------------------CLEAN----------------------------"
	rm -rf treeGUI

clean: 
	echo "-----------------------------------CLEAN----------------------------"
	rm -rf wordBreakdown a.out *.dSYM testWordBreakdown treeGUI
