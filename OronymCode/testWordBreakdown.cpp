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
   string e = "doodleboppermajig";

   vector<string> aExpected, bExpected, cExpected, dExpected, eExpected;
   aExpected.push_back("\"e");
   aExpected.push_back("@");
   aExpected.push_back("\"A");
   
   bExpected.push_back("\"e");
   bExpected.push_back("@");
   bExpected.push_back("\"A");
   
   cExpected.push_back("\"strO%bE$ri");
   
   dExpected.push_back("\"prA$dZEkt");
   dExpected.push_back("pr@\"dZEkt");

   vector<string> aActual = queryDBwithOrthoForSAMPA(a); 
   vector<string> bActual = queryDBwithOrthoForSAMPA(b); 
   vector<string> cActual = queryDBwithOrthoForSAMPA(c); 
   vector<string> dActual = queryDBwithOrthoForSAMPA(d); 
   vector<string> eActual = queryDBwithOrthoForSAMPA(e); 
   
   numPassedTests += (aExpected== aActual);
   numPassedTests += (bExpected== bActual);
   numPassedTests += (cExpected== cActual);
   numPassedTests += (dExpected== dActual);
   numPassedTests += (eExpected== eActual);
   
   passedAllTests &= (aExpected== aActual);
   passedAllTests &= (bExpected== bActual);
   passedAllTests &= (cExpected== cActual);
   passedAllTests &= (dExpected== dActual);
   passedAllTests &= (eExpected== eActual);
  
   cout << "testing queryDBwithOrthoForSAMPA: "<<numPassedTests<<" tests passed"<<endl; 

   return passedAllTests;

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
