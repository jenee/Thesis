#include "2dStackedBarTreeViz.h"

using namespace std;

vector< vector <string> > allBars;
int x;
int y;
int heightConst = 1;

// bar visualization code
//Need a library that allows me to draw a rectangle on an x/y coordinate grid


void generateStackedBarGraphOronymTree( vector <string> phrases ) {
   int fullWidth = 80;
   x=0; //top left
   y=-1; //top left
   drawStackedBar( fullWidth, phrases );
} 


void drawStackedBar( int width, vector <string> tailPhrases) {
   translateYBy(heightConst);
   int sum = 0;
   vector<string> firstWords = getFirstWords(tailPhrases); //function defined elsewhere 
   for (int i = 0; i < firstWords.size(); i++) {
      int freqTemp = getFreqForOrtho( firstWords[i] ); //function defined elsewhere 
      sum += freqTemp;
   }
   for (int i = 0; i < firstWords.size(); i++) {
      int freqTemp = getFreqForOrtho( firstWords[i] ); //function defined elsewhere 
      float ratio = freqTemp / sum;
      float scaledWidth = width * ratio;
      int widthDrawn = drawBar(scaledWidth);
      vector<string> newTails = getTails( firstWords[i], tailPhrases ); //function defined elsewhere 
      drawStackedBar( widthDrawn, newTails );
   }

   translateYBy( -1 * heightConst);
   translateXBy( -1 * width);
}

/*returns width drawn*/
int drawBar(float width) {
   int drawWidth = 1;
   if( width > 1 ) {
      drawWidth = width;
   }
   drawRectangle(drawWidth, heightConst);
   translateXBy(Width); //to set up for the next rectangle to be drawn
}

void translateYBy(int height) {
   y += height;
}

void translateXBy(int width) {
   x += width;
}

void drawRectangle(int width, int height) {
   if(width ==1) {
      allBars[x++][y++] = "|";
   }
   allBars[x][y] = "[";
   for(int ix = 1; ix < width - 1; ix++) {
      for (int iy = 1; iy < height - 1; iy++) {
         x += 1;
         y += 1;
         allBars[x][y] = "-";
      }
   }
   x+=1;
   y+=1;
   allBars[x][y] = "]";
}
