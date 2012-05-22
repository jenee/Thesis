#include "wordBreakdown.h"

using namespace std;

bool allTestsPassed = true;
bool testsSetup = false;

void setupTests() {
   allTestsPassed = true;
   if( testsSetup == false ) {
      connectToPhoneticDictionaryDatabase("/Users/admin/Documents/Thesis/SQLiteDatabases/phoneticDict");
      testsSetup = true;
   }
}

void teardownTests() {
   if(allTestsPassed) {
      cout << "NO TESTS FAILED! :) " << endl;
   } else {
      cout << "some tests failed :( " <<endl; 
   }
   cleanupDatabase();
   testsSetup = false;
}

bool testQueryDBWithOrthoForSAMPA(string orthoWord) {
   assert( testsSetup );
   cout << "TESTING queryDBwithOrthoForSAMPA; ortho = " << orthoWord << endl;
   vector<string> result = queryDBwithOrthoForSAMPA(orthoWord);
   for(int i = 0; i < result.size(); i++) {
      cout << orthoWord << " "<< i << ":" << result.at(i) <<endl;
   }
   cout << endl;
   return true;
}

bool testQueryDBWithOrthoForSAMPA() {
   int numPassedTests = 0;
   bool passedAllTests = true;
   assert( testsSetup );
   
   string a = "A";
   string b = "a";
   string c = "strawberry";
   string d = "project"; 
   
   //string aExpected[] = {

   //vector<phone> aActual = 
   assert(0);
   return true;

}

int oldMain() {

   connectToPhoneticDictionaryDatabase("/Users/admin/Documents/Thesis/SQLiteDatabases/phoneticDict");

   string phrase = "A nice cold shower";

/* OLD DEBUG STUFF
   //fprintf(stderr, "gets here, phrase = %s\n", phrase.c_str());
   vector<string> phraseWords = strTokOnWhitespace( phrase );
   //fprintf(stderr, "gets here, phrase = %s\n", phrase.c_str());
   //TODO remove: loop is for debugging
   cerr << "PHRASEWORDS DEBUG PRINT:";
   for( int i = 0; i < phraseWords.size(); i++) {
      string w = phraseWords[i];
      cerr << w << "|";
   }
   cerr <<endl;
   
   for( int i = 0; i < phraseWords.size(); i++) {
      string w = phraseWords[i];
      cerr <<"~~~~~~~~~~"<<w<<"~~~~~~~~~~";
      cerr << queryDBwithOrthoForSAMPA( w ) <<"~~~~~~~~"<<w<<" end~~~~~~~~~~~~"<<endl; 
   }
   cerr <<endl;
   printDatabaseResultsRows();
*/

   vector<string> orthoPhrases = findAllPermutations( phrase );
   
   for( int i = 0; i < orthoPhrases.size(); i++) {
      string p = orthoPhrases[i];
      cerr <<"---"<< p << endl;
   }
   cerr <<endl;
   printDatabaseResultsRows();


  cleanupDatabase();
}

void usageMessage() {
   cout << "Usage: ./testWordBreakdown [test type option] [input]\n"; 
   cout << "Available options: ";
   cout << "\n\t\tqueryDBwithOrthoForSAMPA";
   cout << "\n\t\thelp";
   cout << "\n\t\toldMain\n";
}

int main(int argc, char* argv[]) {
   
   setupTests();
   if ( argc <= 1) {
      cleanupDatabase();
      oldMain();
      /*
      //run all the default test cases
      allTestsPassed &= testQueryDBWithOrthoForSAMPA();
      */
   } else if ( argc == 2 ) {
      //run the default test cases for the specified function
      if( strcmp( argv[1], "help") == 0 ) {
         usageMessage();
      } else if( strcmp( argv[1], "oldMain") == 0 ) {
         teardownTests();
         oldMain();
      } else if( strcmp( argv[1], "queryDBwithOrthoForSAMPA") == 0 ) {
         allTestsPassed &= testQueryDBWithOrthoForSAMPA();
      } else {
         cout << "!!-----Invalid usage-----!!\n";
         cout << "!!-----input: " << argv[0] <<" "<< argv[1]<<" "<<"-----!!\n";
         usageMessage();
      }
   } else if ( argc > 2 ) {
      //run the test cases for the specified function WITH the param provided
      if( strcmp( argv[1], "help") == 0 ) {
         usageMessage();
      } else if( strcmp( argv[1], "oldMain") == 0 ) {
         teardownTests();
         oldMain();
      } else if( strcmp( argv[1], "queryDBwithOrthoForSAMPA") == 0 ) {
         allTestsPassed &= testQueryDBWithOrthoForSAMPA( argv[2] );
      } else {
         cout << "!!-----Invalid usage-----!!\n";
         cout << "!!-----input: " << argv[0] <<" "<< argv[1]<<" "<<"-----!!\n";
         usageMessage();
      }
   }

   teardownTests();

}
