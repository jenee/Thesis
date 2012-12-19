2dstacked bar visualization code


void generateStackedBarGraphOronymTree( vector <string> phrases ) {
   int fullWidth = 80;
   
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
      int ratio = freqTemp / sum;
      int scaledWidth = width * ratio;
      drawBar(scaledWidth);
      vector<string> newTails = getTails( firstWords[i], tailPhrases ); //function defined elsewhere 
      drawStackedBar( scaledWidth, newTails );
      
   }

   translateYBy( -1 * heightConst);
   translateXBy( -1 * width);
}

void drawBar(int width) {
   drawRectangle(width, heightConst);
   translateXBy(width); //to set up for the next rectangle to be drawn
}
   
