#include "wordTreeDraw.h"

using namespace std;

/*http://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
 *                     (b-a)(freqVal - min)
 *     scaledRadius = ----------------------  + a
 *                          max - min
 */
double scaleFreqToRadius( int freqVal ) {
   assert ( maxWordFreq != DICTIONARY_MIN_FREQ - 1 );
   assert ( minWordFreq != DICTIONARY_MAX_FREQ + 1 );
   
   double a = minRadius;
   double b = maxRadius;
   double max = 1.0 * maxWordFreq;
   double min = 1.0 * minWordFreq;
   
   double scaledRadius = ( ( b - a )*( freqVal - min ) );
   scaledRadius /= ( max = min );
   scaledRadius += a;
   
   return scaledRadius;
}


string FirstWord(const string& line)
{
    return line.substr(0, line.find(' ')+1 );
}

void drawBranchesAtFork( vector< string > fullPhrases, double lastRadius ) {

   if( fullPhrases.size() == 0 ) {
      return;
   }
   
   //use a set to ensure no duplicates
   set< string > firstWords;
   
   //put the first word of each phrase into the set
   for(int i = 0; i < fullPhrases.size(); i++){
      if( fullPhrases.at(i).size() > 0 ) {
         firstWords.insert( FirstWord( fullPhrases.at(i) ) );
      }
   } 
   
   double angleDelta = 90.0 / firstWords.size();
   
   double farRightXOffset = ( defaultXOffset * firstWords.size() ) / 2.0;
   double farLeftXOffset = farRightXOffset * -1.0;
   
   set<string>::iterator curFirstWordIter;
   int i = 0;
   //for each firstWord in the set
   for ( curFirstWordIter = firstWords.begin(); curFirstWordIter != firstWords.end(); curFirstWordIter++) {
      string curFirstWord = *curFirstWordIter;
      int firstWordFreq = queryDBwithOrthoForFreq ( curFirstWord );
      double firstWordRadius = scaleFreqToRadius( firstWordFreq );

      
      //draw a branch
      //TODO: this will have to be scaled, translated
      double tiltAngle = farLeftTiltAngle + ( angleDelta * i ); 
      double curXOffset = farLeftXOffset + ( defaultXOffset * i );
      double curYOffset = defaultYOffset;     

      drawBranch( tiltAngle, curXOffset, curXOffset, lastRadius, firstWordRadius );
      
      glPushMatrix();
      {
         //if firstWord indicates a dead end ( xxx or fff, defined in wordBreakdown.h )
         if( curFirstWord == deadEndDelim1  || curFirstWord == deadEndDelim2 ) {
            //draw a red cube/sphere at the end of the branch
            drawcube();
            //TODO: this will have to be scaled, translated and parameterized;
         } else {
            //find all phrases in fullPhrases that start with that firstWord
            set<string> tailPhrases;
            for (int j = 0; j < fullPhrases.size(); j++) {
               if( curFirstWord == FirstWord( fullPhrases.at(j) ) ) {
                  //remove firstWord from those phrases
                  string tempFull = fullPhrases.at(j);
                  string tempTail = tempFull.substr( tempFull.find(' ')+1 );
                  tailPhrases.insert( tempTail );
               }
            }
            //convert set to vector
            vector<string> tailsVect( tailPhrases.begin(), tailPhrases.end() );
            //pass those phrases to drawBranchesAtFork
            drawBranchesAtFork( tailsVect, firstWordRadius );
         }
      }
      glPopMatrix();
      i++;
   }
   
      
}


void buildAndDrawFullTree( string orthoPhrase ) {
   vector< string > fullPhrases = discoverOronymsForPhrase( orthoPhrase );
   getMaxAndMinFreqForAllOrthoPhrases( fullPhrases, &maxWordFreq, &minWordFreq);
   drawBranchesAtFork ( fullPhrases, DEFAULT_RADIUS );
}

void buildAndDrawFullTree() {
   buildAndDrawFullTree("a nice cold hour");
}
