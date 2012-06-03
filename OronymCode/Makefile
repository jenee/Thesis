CC    = g++
CFLAGS   = -lsqlite3  -pedantic

all: cleantree treeGUI
  
treeGUI:  wordBreakdown.* ../LTreeLighting/*.h ../LTreeLighting/*.cpp
	echo "--------------------------COMPILE treeGUI----------------------------"
	$(CC) $(CFLAGS) -framework GLUT -framework OpenGL  -g -o $@ $^
   
test: cleanTest wordBreakdown.cpp wordBreakdown.h testWordBreakdown.cpp testWordBreakdown.h 
	echo "----------------------COMPILE testWordBreakdown----------------------"
	$(CC) $(CFLAGS) -g -o testWordBreakdown $^

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
