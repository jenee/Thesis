#include "2dStackedBarTreeViz.h"

using namespace std;

vector< vector <string> > allBars;
int x;
int y;
int heightConst = 1;
int fullWidth = 80;

// bar visualization code
//Need a library that allows me to draw a rectangle on an x/y coordinate grid


int getValueForWord( string word ) {
   return queryDBwithOrthoForFreq( word );
}

void generateStackedBarGraphOronymTree( vector <string> phrases ) {
   x=0; //top left
   y=-1; //top left
   drawStackedBar( fullWidth, phrases );
} 


void drawStackedBar( int width, vector <string> tailPhrases) {
   translateYBy(heightConst);
   int sum = 0;
   vector<string> firstWords = getAllFirstWords(tailPhrases); //function defined elsewhere 
   for (int i = 0; i < firstWords.size(); i++) {
      int freqTemp = getValueForWord( firstWords[i] ); //function defined elsewhere 
      sum += freqTemp;
   }
   for (int i = 0; i < firstWords.size(); i++) {
      int freqTemp = getValueForWord( firstWords[i] ); //function defined elsewhere 
      float ratio = freqTemp / sum;
      float scaledWidth = width * ratio;
      int widthDrawn = drawBar(scaledWidth);
      vector<string> newTails = getAllOrthoTailPhrasesOf( firstWords[i], tailPhrases ); //function defined elsewhere 
      drawStackedBar( widthDrawn, newTails );
   }

   translateYBy( -1 * heightConst);
   translateXBy( -1 * width);
}

string removeSuccessAndDeadendIndicatorsFromString( string orig ) {
   string newString;
   size_t endPosition = string::npos;
   string deadEndIndic1 = "xxx";
   string deadEndIndic2 = "fff";
   string successIndic = "___SUCCESS!___";
   
   if( string::npos != ( endPosition = orig.find( deadEndIndic1 ) ) ){
      newString = orig.substr(0, endPosition);
   } else if( string::npos != ( endPosition = orig.find( deadEndIndic2 ) ) ){
      newString = orig.substr(0, endPosition);
   } else if( string::npos != ( endPosition = orig.find( successIndic ) ) ) {
      newString = orig.substr(0, endPosition);
   } else {
      newString = orig;
   }
   
   //Error checking to see that it was actually removed
   if( string::npos !=  newString.find( deadEndIndic1 ) || 
         string::npos !=  newString.find( deadEndIndic2 ) ||
         string::npos !=  newString.find( successIndic ) ) {
      assert(0);
      //this should NEVER happen. 
   }
   
   return trimWhitespace(newString);
}


vector<string> stripOronymOutputOfEndIndicators ( vector<string> phrases ) {
   vector<string> newPhrases;
   
   for(int i = 0; i < phrases.size(); i++ ) {
      string strippedStr;
      strippedStr = removeSuccessAndDeadendIndicatorsFromString( phrases[i] );
      newPhrases.push_back( strippedStr );
   }
   return newPhrases;
}



void makeProtvisDiagram ( vector <string> phrases ) {
   cout << "var root = { " << endl;
   writeProtovisDataLevel( phrases, 1 );
   cout << "}"<<endl;
}

void writeProtovisDataLevel( vector <string> tailPhrases, int curMultiplicativeVal ) {
   vector<string> firstWords = getAllFirstWords(tailPhrases); //function defined elsewhere 
   
   for (int i = 0; i < firstWords.size(); i++) {
      int freqTemp = getValueForWord( firstWords[i] ); //function defined elsewhere 
      
      assert(0);
      //todo: write things!  
      
      vector<string> newTails = getAllOrthoTailPhrasesOf( firstWords[i], tailPhrases ); //function defined elsewhere 
      
      writeProtovisDataLevel( newTails, curMultiplicativeVal * freqTemp );
   }
   
}


/*returns width drawn*/
int drawBar(float width) {
   int drawWidth = 1;
   if( width > 1 ) {
      drawWidth = width;
   }
   drawRectangle(drawWidth, heightConst);
   translateXBy(width); //to set up for the next rectangle to be drawn
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
