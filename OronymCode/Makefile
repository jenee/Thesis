CC    = g++
CFLAGS   = -lsqlite3  -pedantic

all: cleantree cleanTest treeGUI testStackedBar testWordBreakdown
  
treeGUI:  wordBreakdown.* ../LTreeLighting/*.h ../LTreeLighting/*.cpp
	echo "--------------------------COMPILE treeGUI----------------------------"
	$(CC) $(CFLAGS) -framework GLUT -framework OpenGL  -g -o $@ $^
 
test: cleanTest testWordBreakdown testStackedBar

testWordBreakdown: wordBreakdown.cpp testWordBreakdown.cpp 2dStackedBarTreeViz.cpp
	echo "----------------------COMPILE testWordBreakdown----------------------"
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^
	
testStackedBar: testWordBreakdown 
	echo "----------------------COMPILE testWordBreakdown----------------------"
	$(CC) $(CFLAGS) -g -o testStackedBar $^

runTest: test 
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
	echo "--------------------------------CLEANTEST----------------------------"
	rm -rf  *.dSYM testWordBreakdown

cleantree: 
	echo "--------------------------------CLEANTREE----------------------------"
	rm -rf treeGUI

clean: 
	echo "-----------------------------------CLEAN----------------------------"
	rm -rf wordBreakdown a.out *.dSYM testWordBreakdown treeGUI
