CC    = g++
CFLAGS   = -lsqlite3  -pedantic

all: cleantree cleanTest treeGUI testWordBreakdown
  
treeGUI:  wordBreakdown.* ../LTreeLighting/*.h ../LTreeLighting/*.cpp
	echo "--------------------------COMPILE treeGUI----------------------------"
	$(CC) $(CFLAGS) -framework GLUT -framework OpenGL  -g -o $@ $^
 
test:  testWordBreakdown 

testWordBreakdown: wordBreakdown.cpp testWordBreakdown.cpp 2dStackedBarTreeViz.cpp
	echo "----------------------COMPILE testWordBreakdown----------------------"
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^

runTest: test 
	echo "......................RUN testWordBreakdown......................"
	./testWordBreakdown all

warnings: wordBreakdown.cpp testWordBreakdown.cpp 2dStackedBarTreeViz.cpp
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

clean: cleanTest cleantree
	echo "-----------------------------------CLEAN----------------------------"
	rm -rf wordBreakdown a.out *.dSYM testWordBreakdown treeGUI
