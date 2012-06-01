#include "testWordBreakdown.h"
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

bool testDiscoverOronymsForPhrase( string orthoPhrase ) {
   assert( testsSetup );
   cout << "TESTING discoverOronymsForPhrase; orthoPhrase = " << orthoPhrase << endl;
   vector<string> oronymPhrases = discoverOronymsForPhrase( orthoPhrase );
   cout << "!Discovered "<<oronymPhrases.size()<<" oronyms:"<<endl;
   for( int i = 0; i < oronymPhrases.size(); i++) {
      //cout << i<<": '";
      cout <<oronymPhrases.at(i)<< endl;
      //cout << "'"<<endl;
   }
   return true;
}

bool testDiscoverOronymsForPhrase() {
   return testDiscoverOronymsForPhrase("a nice cold shower");
}

bool testFindAllPhoneSeqsForOrthoPhrase(string orthoPhrase) {
   assert( testsSetup );
   cout << "TESTING findAllPhoneSeqsForOrthoPhrase; orthoPhrase = " << orthoPhrase << endl;
   vector< vector<phone> > phoneSeqs = findAllPhoneSeqsForOrthoPhrase( orthoPhrase );
   
   for( int i = 0; i < phoneSeqs.size(); i++) {
      vector<phone> p = phoneSeqs[i];
      cerr <<"---"<< phoneVectToString( p ) << endl;
   }
   cerr <<endl;
   return true;
}



bool testFindAllPhoneSeqsForOrthoPhrase() {
   //assert( testsSetup );
   //cout << "TESTING findAllPhoneSeqsForOrthoPhrase; orthoPhrase = 'A nice cold shower' " << endl;
   return testFindAllPhoneSeqsForOrthoPhrase("A nice cold shower");
}



bool testFindPhoneTreeForOrthoPhrase( string orthoPhrase ) {
   assert( testsSetup );
   cout << "TESTING findPhoneTreeForOrthoPhrase; orthoPhrase = " << orthoPhrase << endl;
   vector< set< phone > > phoneSeqs = findPhoneTreeForOrthoPhrase( orthoPhrase );
   
   for( int i = 0; i < phoneSeqs.size(); i++) {
      vector<phone> temp( phoneSeqs[i].begin(), phoneSeqs[i].end() );
      cerr <<"--- {";
      for( int j = 0; j < temp.size(); j++) {
         cerr << " " << temp.at(j);
      }
      cerr << " }"<< endl;
   }
   cerr <<endl;

   return true;
}


bool testFindPhoneTreeForOrthoPhrase() {
   //assert( testsSetup );
   //cout << "TESTING findAllPhoneSeqsForOrthoPhrase; orthoPhrase = 'A nice cold shower' " << endl;
   return testFindPhoneTreeForOrthoPhrase("A nice cold shower");
}

bool testQueryDBwithSampaForOrthoStrs( string sampaStr ) {
   assert( testsSetup );
   cout << "TESTING queryDBwithSampaForOrthoStrs; sampa = " << sampaStr << endl;
   vector<string> result = queryDBwithSampaForOrthoStrs(sampaStr);
   for(int i = 0; i < result.size(); i++) {
      cout << sampaStr << " "<< i << ":" << result.at(i) <<endl;
   }
   cout << endl;
   return true;
}

bool testQueryDBwithSampaForOrthoStrs( ) {
   return testQueryDBwithSampaForOrthoStrs( "\"k{$r@t" );
}


bool testQueryDBForOrthoStrsWithSampaPrefix( string sampaPrefix ) {
   assert( testsSetup );
   cout << "TESTING queryDBForOrthoStrsWithSampaPrefix; sampa = |" << sampaPrefix << "|"<< endl;
   vector<string> result = queryDBForOrthoStrsWithSampaPrefix(sampaPrefix);
   for(int i = 0; i < result.size(); i++) {
      cout << sampaPrefix << " "<< i << ":" << result.at(i) <<endl;
   }
   cout << endl;
   return true;
}

bool testQueryDBForOrthoStrsWithSampaPrefix() {
   return  testQueryDBForOrthoStrsWithSampaPrefix("A`rdv");
}

bool testQueryDBwithOrthoForSampaStrs(string orthoWord) {
   assert( testsSetup );
   cout << "TESTING queryDBwithOrthoForSampaStrs; ortho = " << orthoWord << endl;
   vector<string> result = queryDBwithOrthoForSampaStrs(orthoWord);
   for(int i = 0; i < result.size(); i++) {
      cout << orthoWord << " "<< i << ":" << result.at(i) <<endl;
   }
   cout << endl;
   return true;
}

bool testQueryDBwithOrthoForSampaStrs() {
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

   vector<string> aActual = queryDBwithOrthoForSampaStrs(a); 
   vector<string> bActual = queryDBwithOrthoForSampaStrs(b); 
   vector<string> cActual = queryDBwithOrthoForSampaStrs(c); 
   vector<string> dActual = queryDBwithOrthoForSampaStrs(d); 
   vector<string> eActual = queryDBwithOrthoForSampaStrs(e); 
   
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
  
   cout << "testing queryDBwithOrthoForSampaStrs: "<<numPassedTests<<" tests passed"<<endl; 

   return passedAllTests;

}

bool testQueryDBwithOrthoForFreq( std::string orthoWord){
   assert( testsSetup );
   cout << "TESTING queryDBwithOrthoForFreq; ortho = " << orthoWord << endl;
   int freq = queryDBwithOrthoForFreq(orthoWord);
   cout<< "freq="<< freq << endl;
   return true;
}

bool testQueryDBwithOrthoForFreq(){
   return testQueryDBwithOrthoForFreq("a");
}

bool testStrTokOnWhitespace( string phrase ) {
   vector<string> phraseWords = strTokOnWhitespace( phrase );
   //fprintf(stderr, "gets here, phrase = %s\n", phrase.c_str());
   //TODO remove: loop is for debugging
   cerr << "PHRASEWORDS DEBUG PRINT:";
   for( int i = 0; i < phraseWords.size(); i++) {
      string w = phraseWords[i];
      cerr << w << "|";
   }
   cerr <<endl;
   return true;
}

bool testStrTokOnWhitespace() {
   return testStrTokOnWhitespace("A nice cold shower");
}

bool testStripSampaStrOfEmph( std::string sampaStr ) {
   cerr<<"TEST stripSampaStrOfEmph, sampaStr = "<< sampaStr<<endl;
   string SAMPAnoEMph = stripSampaStrOfEmph( sampaStr );
   cerr<<"~~~> " << SAMPAnoEMph << endl;
   bool testPassed = true;
   testPassed &= ( string::npos == SAMPAnoEMph.find("\"") );
   testPassed &= ( string::npos == SAMPAnoEMph.find("%") );
   testPassed &= ( string::npos == SAMPAnoEMph.find("$") );
   return testPassed;
}

bool testStripSampaStrOfEmph() {
   return testStripSampaStrOfEmph("strO%bE$ri");
}

bool testGetSampaStrWithoutGlottalStops( std::string sampaStr ) {
   cerr<<"TEST getSampaStrWithoutGlottalStops, sampaStr = "<< sampaStr<<endl;
   string SAMPAnoGlottals = getSampaStrWithoutGlottalStops( sampaStr );
   cerr<<"~~~> " << SAMPAnoGlottals << endl;
   bool testPassed = true;
   return testPassed;
}

bool testGetSampaStrWithoutGlottalStops() {
   bool testPassed = true;
   testPassed &= testGetSampaStrWithoutGlottalStops("VnbVtn=");
   testPassed &= testGetSampaStrWithoutGlottalStops("sVmWVt");
   return testPassed;
}

bool testGetSampaStrWithoutContiguousDuplicatePhones( std::string sampaStr ) {
   cerr<<"TEST getSampaStrWithoutContiguousDuplicatePhones, sampaStr = "<< sampaStr<<endl;
   string SAMPAnoDupes = getSampaStrWithoutContiguousDuplicatePhones( sampaStr );
   cerr<<"~~~> " << SAMPAnoDupes << endl;
   bool testPassed = true;
   return testPassed;
}

bool testGetSampaStrWithoutContiguousDuplicatePhones() {
   bool testPassed = true;
   testPassed &= testGetSampaStrWithoutContiguousDuplicatePhones("sVmmVD@`rz");
   return testPassed;
}

bool testTrimWhitespace( string str ) {

   string trimmedStr = trimWhitespace( str );
   
   cout << "orig string = '"<<str<<"'"<<endl;
   cout << "trim string = '"<<trimmedStr<<"'"<<endl;
   if( trimmedStr.size() == 0 ) {
      return true;
   } else if( trimmedStr.at(0) != ' ' 
            && trimmedStr.at( trimmedStr.size() - 1 ) != ' ' ) {
      return true;
   } else {
      return false;
   }
}

bool testTrimWhitespace () {
   return testTrimWhitespace( "   I have spaces on both sides!    ");
}

void oldMain() {

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
      cerr << queryDBwithOrthoForSampaStrs( w ) <<"~~~~~~~~"<<w<<" end~~~~~~~~~~~~"<<endl; 
   }
   cerr <<endl;
   printDatabaseResultsRows();
*/

/*
   vector<string> sampaPhrases = findAllPhoneSeqsForOrthoPhrase( phrase );
   
   for( int i = 0; i < sampaPhrases.size(); i++) {
      string p = sampaPhrases[i];
      cerr <<"---"<< p << endl;
   }
   cerr <<endl;
   printDatabaseResultsRows();

*/
  cleanupDatabase();
}

bool runAllDefaultTests() {
   bool testsPassed = true;
   cout << "XXXXXXXXXXXXXXXXX___START___XXXXXXXXXXXXXXXXXXXXXXX"<<endl<<endl;

   testsPassed &= testDiscoverOronymsForPhrase();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testFindAllPhoneSeqsForOrthoPhrase();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   //testsPassed &= testFindPhoneTreeForOrthoPhrase();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testStripSampaStrOfEmph();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testStrTokOnWhitespace();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testQueryDBwithOrthoForSampaStrs();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testQueryDBwithOrthoForFreq();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testQueryDBwithSampaForOrthoStrs();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testQueryDBForOrthoStrsWithSampaPrefix();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testGetSampaStrWithoutGlottalStops();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testGetSampaStrWithoutContiguousDuplicatePhones();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testTrimWhitespace();
   cout << "XXXXXXXXXXXXXXXXXXXXXX___DONE___XXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   return testsPassed;
}

void usageMessage() {
   cout << "Usage: ./testWordBreakdown [test type option] [input]\n"; 
   cout << "Available options: ";
   cout << "\n\t\tall";
   cout << "\n\t\ttrimWhitespace";
   cout << "\n\t\tdiscoverOronymsForPhrase";
   cout << "\n\t\tstripSampaStrOfEmph";
   cout << "\n\t\tgetSampaStrWithoutGlottalStops";
   cout << "\n\t\tgetSampaStrWithoutContiguousDuplicatePhones";
   cout << "\n\t\tstrTokOnWhitespace";
   cout << "\n\t\tfindAllPhoneSeqsForOrthoPhrase";
   cout << "\n\t\tfindPhoneTreeForOrthoPhrase";
   cout << "\n\t\tqueryDBwithOrthoForSampaStrs";
   cout << "\n\t\tqueryDBForOrthoStrsWithSampaPrefix";
   cout << "\n\t\tqueryDBwithOrthoForFreq";
   cout << "\n\t\tqueryDBwithSampaForOrthoStrs";
   cout << "\n\t\thelp";
   cout << "\n\t\toldMain\n";
}

int main(int argc, char* argv[]) {
   
   setupTests();
   if ( argc <= 1) {
      usageMessage();
      /*
      //run all the default test cases
      allTestsPassed &= testQueryDBWithOrthoForSampaStrs();
      */
   } else if ( argc == 2 ) {
      //run the default test cases for the specified function
      if( strcmp( argv[1], "help") == 0 ) {
         usageMessage();
      } else if( strcmp( argv[1], "oldMain") == 0 ) {
         teardownTests();
         oldMain();
      } else if( strcmp( argv[1], "all") == 0 ) {
          allTestsPassed &= runAllDefaultTests();
      } else if( strcmp( argv[1], "discoverOronymsForPhrase") == 0 ) {
         allTestsPassed &= testDiscoverOronymsForPhrase();
      } else if( strcmp( argv[1], "findPhoneTreeForOrthoPhrase") == 0 ) {
         allTestsPassed &= testFindPhoneTreeForOrthoPhrase();
      } else if( strcmp( argv[1], "findAllPhoneSeqsForOrthoPhrase") == 0 ) {
         allTestsPassed &= testFindAllPhoneSeqsForOrthoPhrase();
      } else if( strcmp( argv[1], "stripSampaStrOfEmph") == 0 ) {
         allTestsPassed &= testStripSampaStrOfEmph();
      } else if( strcmp( argv[1], "getSampaStrWithoutGlottalStops") == 0 ) {
         allTestsPassed &= testGetSampaStrWithoutGlottalStops();
      } else if( strcmp( argv[1], "getSampaStrWithoutContiguousDuplicatePhones") == 0 ) {
         allTestsPassed &= testGetSampaStrWithoutContiguousDuplicatePhones();
      } else if( strcmp( argv[1], "strTokOnWhitespace") == 0 ) {
         allTestsPassed &= testStrTokOnWhitespace();
      } else if( strcmp( argv[1], "trimWhitespace") == 0 ) {
         allTestsPassed &= testTrimWhitespace();
      } else if( strcmp( argv[1], "queryDBwithOrthoForSampaStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForSampaStrs();
      } else if( strcmp( argv[1], "queryDBwithOrthoForFreq") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForFreq();
      } else if( strcmp( argv[1], "queryDBForOrthoStrsWithSampaPrefix") == 0 ) {
         allTestsPassed &= testQueryDBForOrthoStrsWithSampaPrefix();
      } else if( strcmp( argv[1], "queryDBwithSampaForOrthoStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithSampaForOrthoStrs();
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
      } else if( strcmp( argv[1], "discoverOronymsForPhrase") == 0 ) {
         allTestsPassed &= testDiscoverOronymsForPhrase( argv[2] );
      } else if( strcmp( argv[1], "findPhoneTreeForOrthoPhrase") == 0 ) {
         allTestsPassed &= testFindPhoneTreeForOrthoPhrase( argv[2] );
      } else if( strcmp( argv[1], "findAllPhoneSeqsForOrthoPhrase") == 0 ) {
         allTestsPassed &= testFindAllPhoneSeqsForOrthoPhrase( argv[2] );
      } else if( strcmp( argv[1], "stripSampaStrOfEmph") == 0 ) {
         allTestsPassed &= testStripSampaStrOfEmph( argv[2] );
      } else if( strcmp( argv[1], "getSampaStrWithoutGlottalStops") == 0 ) {
         allTestsPassed &= testGetSampaStrWithoutGlottalStops( argv[2] );
      } else if( strcmp( argv[1], "getSampaStrWithoutContiguousDuplicatePhones") == 0 ) {
         allTestsPassed &= testGetSampaStrWithoutContiguousDuplicatePhones( argv[2] );
      } else if( strcmp( argv[1], "strTokOnWhitespace") == 0 ) {
         allTestsPassed &= testStrTokOnWhitespace( argv[2] );
      } else if( strcmp( argv[1], "trimWhitespace") == 0 ) {
         allTestsPassed &= testTrimWhitespace( argv[2] );
      } else if( strcmp( argv[1], "queryDBwithOrthoForSampaStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForSampaStrs( argv[2] );
      } else if( strcmp( argv[1], "queryDBwithOrthoForFreq") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForFreq( argv[2] );
      } else if( strcmp( argv[1], "queryDBForOrthoStrsWithSampaPrefix") == 0 ) {
         allTestsPassed &= testQueryDBForOrthoStrsWithSampaPrefix( argv[2] );
      } else if( strcmp( argv[1], "queryDBwithSampaForOrthoStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithSampaForOrthoStrs( argv[2] );
      } else {
         cout << "!!-----Invalid usage-----!!\n";
         cout << "!!-----input: " << argv[0] <<" "<< argv[1]<<" "<<"-----!!\n";
         usageMessage();
      }
   }

   teardownTests();

}
