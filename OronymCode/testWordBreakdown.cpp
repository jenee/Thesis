#include "testWordBreakdown.h"
using namespace std;

bool allTestsPassed = true;
bool testsSetup = false;

void setupTests() {
   allTestsPassed = true;
   if( testsSetup == false ) {
      connectToFreqDictionaryDatabase();
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
   cerr << "TESTING discoverOronymsForPhrase; orthoPhrase = " << orthoPhrase << endl;
   vector<string> oronymPhrases = discoverOronymsForPhrase( orthoPhrase );
   cout << "!Discovered "<<oronymPhrases.size()<<" oronyms:"<<endl;
   for( int i = 0; i < oronymPhrases.size(); i++) {
      //cout << i<<": '"
      //cout <<"\\item ";
      cout <<oronymPhrases.at(i)<< endl;
      //cout << "'"<<endl;
   }
   return true;
}

bool testDiscoverOronymsForPhrase() {
   return testDiscoverOronymsForPhrase("a nice cold hour");
}

bool testFindAllPhoneSeqsForOrthoPhrase(string orthoPhrase) {
   assert( testsSetup );
   cout << "TESTING findAllPhoneSeqsForOrthoPhrase; orthoPhrase = " << orthoPhrase << endl;
   vector< vector<phone> > phoneSeqs = findAllPhoneSeqsForOrthoPhrase( orthoPhrase );
   
   cout << "!Discovered "<<phoneSeqs.size()<<" phoneseqs:"<<endl;

   for( int i = 0; i < phoneSeqs.size(); i++) {
      vector<phone> p = phoneSeqs[i];
      cout <<"---"<< phoneVectToString( p ) << endl;
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
   cerr<<"TEST trimWhitespace, str = "<< str <<endl;

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

bool testGetTotalFreqForPhrase( string orthoPhrase ) {
   cout <<"TEST getTotalFreqForPhrase, orthoPhrase ="<<orthoPhrase;
   int returned = getTotalFreqForPhrase( orthoPhrase );
   cout <<"; freq="<<returned<<endl;
   if( orthoPhrase == "empty email" ) {
      int expected = 918 + 15141;
      return ( expected == returned );
   } else {
      return true;
   }
}

bool testGetTotalFreqForPhrase() {
   return testGetTotalFreqForPhrase("empty email");
}


bool test_getCSVofWordFreqsForPhrase() {
   return test_getCSVofWordFreqsForPhrase("empty email");
}

bool test_getCSVofWordFreqsForPhrase(string orthoPhrase ) {
   cout <<"TEST getCSVofWordFreqsForPhrase, orthoPhrase ="<<orthoPhrase<<endl;
   string returned = getCSVofWordFreqsForPhrase( orthoPhrase );
   cout <<""<<returned<<endl;
   return true;
}


bool test_getCSVofAllPhraseFreqs( vector<string> orthoPhrases ) {
   cerr <<"TEST getCSVofAllPhraseFreqs, orthoPhrases.size() ="<< orthoPhrases.size()<<endl;

   vector<string> csvStrings = getCSVofAllPhraseFreqs ( orthoPhrases );
   for(int i = 0; i < csvStrings.size(); i++){
      cout << i<< "," << trimWhitespace(csvStrings.at( i )) <<endl;
   }
   return true;
}

bool test_getCSVofAllPhraseFreqs() {
   vector<string> orthoPhrases = buildVectorOfStrings();
   return  test_getCSVofAllPhraseFreqs ( orthoPhrases );
}




bool test_getCSVofEachPhrasesWordsFreqs( vector<string> orthoPhrases ) {
   cerr <<"TEST getCSVofEachPhrasesWordsFreqs, orthoPhrases.size() ="<< orthoPhrases.size()<<endl;

   vector<string> csvStrings = getCSVofEachPhrasesWordsFreqs ( orthoPhrases );
   for(int i = 0; i < csvStrings.size(); i++){
      cout << i<< ", " <<csvStrings.at( i ) <<endl;
   }
   return true;
}

bool test_getCSVofEachPhrasesWordsFreqs() {
   vector<string> orthoPhrases = buildVectorOfStrings();
   return  test_getCSVofEachPhrasesWordsFreqs ( orthoPhrases );
}



void test_DrawStackedBar( vector<string> phrases ) {
   generateStackedBarGraphOronymTree( phrases );
}

void test_DrawStackedBar( string rootPhrase ) {
   vector<string> phrases = discoverOronymsForPhrase( rootPhrase );
   test_DrawStackedBar(phrases);
}

void test_DrawStackedBar() {
   test_DrawStackedBar("time may tell");
}



void test_DrawRect( int width, int height ) {
   drawRectangle( width,  height);
}

void test_DrawRect( int width ) {
   test_DrawRect(width, 1);
}

void test_DrawRect() {
   test_DrawRect(3);
}



bool test_getAllFirstWords() {
   return test_getAllFirstWords("what no incense stinks");
}

bool test_getAllFirstWords( string rootPhrase ) {
   vector<string> phrases = discoverOronymsForPhrase( rootPhrase );
   return test_getAllFirstWords(phrases);

}

bool test_getAllFirstWords( vector<string> phrases ) {
   cerr <<"TEST getAllFirstWords, phrases.size() ="<< phrases.size()<<endl;
   vector<string> firsts = getAllFirstWords( phrases );
   for(int i=0; i < firsts.size(); i++) {
      cout << i<<": "<< firsts[i]<< endl;
   }
   return true;
}

bool test_removeSuccessAndDeadendIndicatorsFromString() {
   bool retVal = true;
   retVal &= test_removeSuccessAndDeadendIndicatorsFromString("dead end indic x's xxx");   
   retVal &= test_removeSuccessAndDeadendIndicatorsFromString("dead end indic f's fff");
   retVal &= test_removeSuccessAndDeadendIndicatorsFromString("success indic ___SUCCESS!___");
   return retVal;
}

bool test_removeSuccessAndDeadendIndicatorsFromString(string test) {
   string newStr = removeSuccessAndDeadendIndicatorsFromString(test);
   cout << "\'"<<test<<"\' ---> \'"<<newStr<<"\'"<<endl;
   string deadEndIndic1 = "xxx";
   string deadEndIndic2 = "fff";
   string successIndic = "___SUCCESS!___";
   
   if( string::npos ==  newStr.find( deadEndIndic1 ) || 
         string::npos ==  newStr.find( deadEndIndic2 ) ||
         string::npos ==  newStr.find( successIndic ) ) {
      return true;
   } else {
      return false;
   }
}
bool test_stripOronymOutputOfEndIndicators() {

   bool retVal = true;
   
   vector<string> testPhrases;
   testPhrases.push_back("dead end indic x's xxx");   
   testPhrases.push_back("dead end indic f's fff");
   testPhrases.push_back("success indic ___SUCCESS!___");
   
   retVal &= test_stripOronymOutputOfEndIndicators( testPhrases );
   return retVal;
}

bool test_stripOronymOutputOfEndIndicators( string rootPhrase ) {

   bool retVal = true;
   
   vector<string> testPhrases = discoverOronymsForPhrase( rootPhrase );

   retVal &= test_stripOronymOutputOfEndIndicators( testPhrases );
   
   return retVal;
}

bool test_stripOronymOutputOfEndIndicators( vector<string> testPhrases ) {
   cout <<"TEST stripOronymOutputOfEndIndicators, testPhrases.size() ="<< testPhrases.size()<<endl;

   bool retVal = true;
   string deadEndIndic1 = "xxx";
   string deadEndIndic2 = "fff";
   string successIndic = "___SUCCESS!___";
   
   vector<string> newStrings = stripOronymOutputOfEndIndicators(testPhrases);
   
   for(int i = 0; i < testPhrases.size(); i++) {
      string newStr = newStrings[i];
      cout << "\'"<<testPhrases[i]<<"\' ---> \'"<<newStr<<"\'"<<endl;
      if( string::npos ==  newStr.find( deadEndIndic1 ) || 
          string::npos ==  newStr.find( deadEndIndic2 ) ||
            string::npos ==  newStr.find( successIndic ) ) {
         retVal &= true;
      } else {
         cout << "<>FAILED stripOronymOutputOfEndIndicators, newStr = "<<newStr <<endl;
         retVal &= false;
      }
   }
   return retVal;
}


bool test_makeProtvisDiagram() {

   bool retVal = true;
   
   vector<string> testPhrases;
   testPhrases.push_back("why that sin sane");
   testPhrases.push_back("why that sin seine");
   testPhrases.push_back("why that's in sane");
   testPhrases.push_back("why that's in seine");
   testPhrases.push_back("why that's inn sane");
   testPhrases.push_back("why that's inn seine");
   testPhrases.push_back("why that's insane");
   
   retVal &= test_makeProtvisDiagram( testPhrases );
   return retVal;
}

bool test_makeProtvisDiagram( string rootPhrase ) {

   bool retVal = true;
   
   /*for this particular branch, we can't discover oronyms, so
   substitute in pre-built vector*/
   cerr << "In this COCA branch, unique oronyms cannot be created on the fly.";
   cerr << endl << "Substituting the oronyms for \'an ice cold hour\'" <<endl;
   vector<string> testPhrases = buildVectorOfStrings();
                        //discoverOronymsForPhrase( rootPhrase );

   retVal &= test_makeProtvisDiagram( testPhrases );
   
   return retVal;
}

bool test_makeProtvisDiagram( vector<string> testPhrases ) {
   cout <<"TEST makeProtvisDiagram, testPhrases.size() ="<< testPhrases.size()<<endl;

   bool retVal = true;
   
   makeProtvisDiagram(testPhrases);
   
   
   return true;
}




vector<string> buildVectorOfStrings() {
   vector<string> orthoPhrases;
   /*
   {
   orthoPhrases.push_back( "empty hour e mail" );
   orthoPhrases.push_back( "empty hour e male" );
   orthoPhrases.push_back( "empty hour e-mail" );
   orthoPhrases.push_back( "empty hour email" );
   orthoPhrases.push_back( "empty our e mail" );
   orthoPhrases.push_back( "empty our e male" );
   orthoPhrases.push_back( "empty our e-mail" );
   orthoPhrases.push_back( "empty our email" );
   } */
   /*mech turk answers*
   {
      orthoPhrases.push_back( "	a nice cold hour	" );
      orthoPhrases.push_back( "	an ice cold dower	" );
      orthoPhrases.push_back( "	a nice cold hour	" );
      orthoPhrases.push_back( "	on ice cold dower	" );
      orthoPhrases.push_back( "	on ice cold hour	" );
      orthoPhrases.push_back( "	an ice cold hour	" );
      orthoPhrases.push_back( "	a nice old hour	" );
      orthoPhrases.push_back( "	a nice gold hour	" );
      orthoPhrases.push_back( "	an ice gold hour	" );
      orthoPhrases.push_back( "	an ice old hour	" );
      orthoPhrases.push_back( "	an ice cold shower	" );
      orthoPhrases.push_back( "	in ice cold davar	" );
      orthoPhrases.push_back( "	a nice odd hour	" );
      orthoPhrases.push_back( "	a nice hold hour	" );
      orthoPhrases.push_back( "	an ice cold dollar	" );
      orthoPhrases.push_back( "	an ice cold dour	" );
      orthoPhrases.push_back( "	a nice bold hour	" );
      orthoPhrases.push_back( "	an ice cold our	" );
      orthoPhrases.push_back( "	a nice spoke hour	" );
      orthoPhrases.push_back( "	a nice scored hour	" );
      orthoPhrases.push_back( "	in unschooled hour	" );
      orthoPhrases.push_back( "	on ice cold our	" );
      orthoPhrases.push_back( "	in ice cold hour	" );
      orthoPhrases.push_back( "	and i scold hour	" );
      orthoPhrases.push_back( "	a nice fold hour	" );
      orthoPhrases.push_back( "	a nice cold our	" );
      orthoPhrases.push_back( "	on ice cold bauer	" );
      orthoPhrases.push_back( "	Then ices co the where	" );
      orthoPhrases.push_back( "	enoise cothawer	" );
      orthoPhrases.push_back( "	and i scored the hour	" );
      orthoPhrases.push_back( "	a nice gold dollar	" );
      orthoPhrases.push_back( "	a nice cool dollar	" );
      orthoPhrases.push_back( "	a nice cool hour	" );
      orthoPhrases.push_back( "	a nice cold shower	" );
      orthoPhrases.push_back( "	an ice cold ower	" );
      orthoPhrases.push_back( "	a nice called hour	" );
      orthoPhrases.push_back( "	an ice cold bower	" );
      orthoPhrases.push_back( "	an ice cold bauer	" );
      orthoPhrases.push_back( "	an ice called dower	" );
      orthoPhrases.push_back( "	The nice cold hour	" );
      orthoPhrases.push_back( "	a nice cold dollar	" );
      orthoPhrases.push_back( "	an ice cold grave	" );
      orthoPhrases.push_back( "	a nice godfather	" );
      orthoPhrases.push_back( "	then ice go their were	" );
      orthoPhrases.push_back( "	an ice coal dower	" );
      orthoPhrases.push_back( "	he nice on the hour	" );
      orthoPhrases.push_back( "	a nine scold hour	" );
      orthoPhrases.push_back( "	a nice cold dour	" );
      orthoPhrases.push_back( "	on ice cold dour	" );
      orthoPhrases.push_back( "	in eye spole dower	" );
      orthoPhrases.push_back( "	a nine spole dower	" );
      orthoPhrases.push_back( "	and i scold our	" );
      orthoPhrases.push_back( "	on ice col dour	" );
      orthoPhrases.push_back( "	on eis kol dour	" );
      orthoPhrases.push_back( "	an eye scold hour	" );
      orthoPhrases.push_back( "	a nigh scold hour	" );
      orthoPhrases.push_back( "	an nice cold our	" );
      orthoPhrases.push_back( "	hey nice hold hour	" );
      orthoPhrases.push_back( "	on ice co dover	" );
      orthoPhrases.push_back( "	ei nice cold hour	" );
      orthoPhrases.push_back( "	an ice ocld hour	" );
      orthoPhrases.push_back( "	ej nice cold ohur	" );
      orthoPhrases.push_back( "	an ice could hour	" );
      orthoPhrases.push_back( "	an ice hold hour	" );
      orthoPhrases.push_back( "	ej nice cold hout	" );
      orthoPhrases.push_back( "	a nights cold hour	" );
      orthoPhrases.push_back( "	on ice called our	" );
      orthoPhrases.push_back( "	all ice cold hour	" );
      orthoPhrases.push_back( "	in ice cold our	" );
      orthoPhrases.push_back( "	nice cold hour	" );
      orthoPhrases.push_back( "	an ice scold hour	" );
      orthoPhrases.push_back( "	and ice cold dollar	" );
      orthoPhrases.push_back( "	an iced cold hour	" );
      orthoPhrases.push_back( "	a niceco daver	" );
      orthoPhrases.push_back( "	a nice code hour	" );
      orthoPhrases.push_back( "	an ice cove daver	" );
      orthoPhrases.push_back( "	in ice co daver	" );
      orthoPhrases.push_back( "	in ice cove diver	" );
      orthoPhrases.push_back( "	in icecube daver	" );
      orthoPhrases.push_back( "	In ice cove daver	" );
      orthoPhrases.push_back( "	in ice code our	" );
      orthoPhrases.push_back( "	in nice code over	" );
      orthoPhrases.push_back( "	in nice code our	" );
      orthoPhrases.push_back( "	in ice gold hour	" );
      orthoPhrases.push_back( "	on eyes cold over	" );
      orthoPhrases.push_back( "	in eyes cold over	" );
      orthoPhrases.push_back( "	in nice cold hour	" );
      orthoPhrases.push_back( "	in ice coal dour	" );
      orthoPhrases.push_back( "	an ice coal dour	" );
      orthoPhrases.push_back( "	on ice cold air	" );
      orthoPhrases.push_back( "	an I scold hour	" );
      orthoPhrases.push_back( "	on the ice cold dour	" );
      orthoPhrases.push_back( "	an ice cold hour 	" );
      orthoPhrases.push_back( "	an icecold hour	" );
      orthoPhrases.push_back( "	a nice could hour	" );
      orthoPhrases.push_back( "	an ounce gold hour	" );
      orthoPhrases.push_back( "	on ice coal dour	" );
      orthoPhrases.push_back( "	an nice cold hour	" );
      orthoPhrases.push_back( "	an ice cole dower	" );
      orthoPhrases.push_back( "	a nice coal dower	" );
      orthoPhrases.push_back( "	a nice cold dower	" );
      orthoPhrases.push_back( "	and i scored over	" );
      orthoPhrases.push_back( "	a nice cold thou are	" );
      orthoPhrases.push_back( "	on ice cold thou art	" );
      orthoPhrases.push_back( "	on a nice cold hour	" );
      orthoPhrases.push_back( "	an ice cold thou are	" );
      orthoPhrases.push_back( "	on ice old hour	" );
      orthoPhrases.push_back( "	on the ice cold hour	" );
      orthoPhrases.push_back( "	can i score the hour  	" );
      orthoPhrases.push_back( "	a nice coal dour	" );
      orthoPhrases.push_back( "	a nice pollard	" );
      orthoPhrases.push_back( "	hey nine scold hour	" );
      orthoPhrases.push_back( "	in a ice cold hour	" );
      orthoPhrases.push_back( "	the nice gold hour	" );
      orthoPhrases.push_back( "	a nice scold hour	" );
      orthoPhrases.push_back( "	an ice cold hour	" );
      orthoPhrases.push_back( "	an eye scol dagr	" );
      orthoPhrases.push_back( "	ah nay skull dower	" );
      orthoPhrases.push_back( "	a nye scoldower	" );
      orthoPhrases.push_back( "	a nice cool bowl	" );
      orthoPhrases.push_back( "	A nice cold bowl	" );
      orthoPhrases.push_back( "	A nice cob bower	" );
      orthoPhrases.push_back( "	On ice core bower	" );
      orthoPhrases.push_back( "	an ice core bower	" );
      orthoPhrases.push_back( "	An ice cold bowl	" );
      orthoPhrases.push_back( "	An ice bore bower	" );
      orthoPhrases.push_back( "	A nice pod our	" );
      orthoPhrases.push_back( "	An ice co bowel	" );
      orthoPhrases.push_back( "	An ice cob our	" );
      orthoPhrases.push_back( "	A nice cobour.	" );
      orthoPhrases.push_back( "	A nice cob our	" );
      orthoPhrases.push_back( "	a light cold hour	" );
      orthoPhrases.push_back( "	in i scold hour	" );
      orthoPhrases.push_back( "	and nice cold hour	" );
      orthoPhrases.push_back( "	all eyes cold hour	" );
      orthoPhrases.push_back( "	an eyes cold hour	" );
      orthoPhrases.push_back( "	a nice cow is there	" );
      orthoPhrases.push_back( "	on eyes go there	" );
      orthoPhrases.push_back( "	an eyes co thou	" );
      orthoPhrases.push_back( "	an eyes close over	" );
      orthoPhrases.push_back( "	on ice call dour	" );
      orthoPhrases.push_back( "	a nice gold dour	" );
      orthoPhrases.push_back( "	hen eyes oh dawad	" );
      orthoPhrases.push_back( "	hen ice oh dawad	" );
      orthoPhrases.push_back( "	hen eyes oh gawd	" );
      orthoPhrases.push_back( "	on iced cold hour	" );
      orthoPhrases.push_back( "	an ice gold dower	" );
      orthoPhrases.push_back( "	a nice gold dower	" );
      orthoPhrases.push_back( "	i saw tower	" );
   }
   */
    
   {
   orthoPhrases.push_back( "n' ay scold hour" );
   orthoPhrases.push_back( "n' ay scold our" );
   orthoPhrases.push_back( "n' ay skol dour" );
   orthoPhrases.push_back( "n' ay skol dower" );
   orthoPhrases.push_back( "n' aye scold hour" );
   orthoPhrases.push_back( "n' aye scold our" );
   orthoPhrases.push_back( "n' aye skol dour" );
   orthoPhrases.push_back( "n' aye skol dower" );
   orthoPhrases.push_back( "n' e scold hour" );
   orthoPhrases.push_back( "n' e scold our" );
   orthoPhrases.push_back( "n' e skol dour" );
   orthoPhrases.push_back( "n' e skol dower" );
   orthoPhrases.push_back( "n' eye scold hour" );
   orthoPhrases.push_back( "n' eye scold our" );
   orthoPhrases.push_back( "n' eye skol dour" );
   orthoPhrases.push_back( "n' eye skol dower" );
   orthoPhrases.push_back( "n' i scold hour" );
   orthoPhrases.push_back( "n' i scold our" );
   orthoPhrases.push_back( "n' i skol dour" );
   orthoPhrases.push_back( "n' i skol dower" );
   orthoPhrases.push_back( "n' ice coal dour" );
   orthoPhrases.push_back( "n' ice coal dower" );
   orthoPhrases.push_back( "n' ice cold hour" );
   orthoPhrases.push_back( "n' ice cold our" );
   orthoPhrases.push_back( "n' ice cole dour" );
   orthoPhrases.push_back( "n' ice cole dower" );
   orthoPhrases.push_back( "n' ice kohl dour" );
   orthoPhrases.push_back( "n' ice kohl dower" );
   orthoPhrases.push_back( "n' ice-cold hour" );
   orthoPhrases.push_back( "n' ice-cold our" );
   orthoPhrases.push_back( "a gneiss coal dour" );
   orthoPhrases.push_back( "a gneiss coal dower" );
   orthoPhrases.push_back( "a gneiss cold hour" );
   orthoPhrases.push_back( "a gneiss cold our" );
   orthoPhrases.push_back( "a gneiss cole dour" );
   orthoPhrases.push_back( "a gneiss cole dower" );
   orthoPhrases.push_back( "a gneiss kohl dour" );
   orthoPhrases.push_back( "a gneiss kohl dower" );
   orthoPhrases.push_back( "a knee scold hour" );
   orthoPhrases.push_back( "a knee scold our" );
   orthoPhrases.push_back( "a knee skol dour" );
   orthoPhrases.push_back( "a knee skol dower" );
   orthoPhrases.push_back( "a ne scold hour" );
   orthoPhrases.push_back( "a ne scold our" );
   orthoPhrases.push_back( "a ne skol dour" );
   orthoPhrases.push_back( "a ne skol dower" );
   orthoPhrases.push_back( "a nice coal dour" );
   orthoPhrases.push_back( "a nice coal dower" );
   orthoPhrases.push_back( "a nice cold hour" );
   orthoPhrases.push_back( "a nice cold our" );
   orthoPhrases.push_back( "a nice cole dour" );
   orthoPhrases.push_back( "a nice cole dower" );
   orthoPhrases.push_back( "a nice kohl dour" );
   orthoPhrases.push_back( "a nice kohl dower" );
   orthoPhrases.push_back( "a niece coal dour" );
   orthoPhrases.push_back( "a niece coal dower" );
   orthoPhrases.push_back( "a niece cold hour" );
   orthoPhrases.push_back( "a niece cold our" );
   orthoPhrases.push_back( "a niece cole dour" );
   orthoPhrases.push_back( "a niece cole dower" );
   orthoPhrases.push_back( "a niece kohl dour" );
   orthoPhrases.push_back( "a niece kohl dower" );
   orthoPhrases.push_back( "a nigh scold hour" );
   orthoPhrases.push_back( "a nigh scold our" );
   orthoPhrases.push_back( "a nigh skol dour" );
   orthoPhrases.push_back( "a nigh skol dower" );
   orthoPhrases.push_back( "a nye scold hour" );
   orthoPhrases.push_back( "a nye scold our" );
   orthoPhrases.push_back( "a nye skol dour" );
   orthoPhrases.push_back( "a nye skol dower" );
   orthoPhrases.push_back( "ah gneiss coal dour" );
   orthoPhrases.push_back( "ah gneiss coal dower" );
   orthoPhrases.push_back( "ah gneiss cold hour" );
   orthoPhrases.push_back( "ah gneiss cold our" );
   orthoPhrases.push_back( "ah gneiss cole dour" );
   orthoPhrases.push_back( "ah gneiss cole dower" );
   orthoPhrases.push_back( "ah gneiss kohl dour" );
   orthoPhrases.push_back( "ah gneiss kohl dower" );
   orthoPhrases.push_back( "ah knee scold hour" );
   orthoPhrases.push_back( "ah knee scold our" );
   orthoPhrases.push_back( "ah knee skol dour" );
   orthoPhrases.push_back( "ah knee skol dower" );
   orthoPhrases.push_back( "ah ne scold hour" );
   orthoPhrases.push_back( "ah ne scold our" );
   orthoPhrases.push_back( "ah ne skol dour" );
   orthoPhrases.push_back( "ah ne skol dower" );
   orthoPhrases.push_back( "ah nice coal dour" );
   orthoPhrases.push_back( "ah nice coal dower" );
   orthoPhrases.push_back( "ah nice cold hour" );
   orthoPhrases.push_back( "ah nice cold our" );
   orthoPhrases.push_back( "ah nice cole dour" );
   orthoPhrases.push_back( "ah nice cole dower" );
   orthoPhrases.push_back( "ah nice kohl dour" );
   orthoPhrases.push_back( "ah nice kohl dower" );
   orthoPhrases.push_back( "ah niece coal dour" );
   orthoPhrases.push_back( "ah niece coal dower" );
   orthoPhrases.push_back( "ah niece cold hour" );
   orthoPhrases.push_back( "ah niece cold our" );
   orthoPhrases.push_back( "ah niece cole dour" );
   orthoPhrases.push_back( "ah niece cole dower" );
   orthoPhrases.push_back( "ah niece kohl dour" );
   orthoPhrases.push_back( "ah niece kohl dower" );
   orthoPhrases.push_back( "ah nigh scold hour" );
   orthoPhrases.push_back( "ah nigh scold our" );
   orthoPhrases.push_back( "ah nigh skol dour" );
   orthoPhrases.push_back( "ah nigh skol dower" );
   orthoPhrases.push_back( "ah nye scold hour" );
   orthoPhrases.push_back( "ah nye scold our" );
   orthoPhrases.push_back( "ah nye skol dour" );
   orthoPhrases.push_back( "ah nye skol dower" );
   orthoPhrases.push_back( "an ay scold hour" );
   orthoPhrases.push_back( "an ay scold our" );
   orthoPhrases.push_back( "an ay skol dour" );
   orthoPhrases.push_back( "an ay skol dower" );
   orthoPhrases.push_back( "an aye scold hour" );
   orthoPhrases.push_back( "an aye scold our" );
   orthoPhrases.push_back( "an aye skol dour" );
   orthoPhrases.push_back( "an aye skol dower" );
   orthoPhrases.push_back( "an e scold hour" );
   orthoPhrases.push_back( "an e scold our" );
   orthoPhrases.push_back( "an e skol dour" );
   orthoPhrases.push_back( "an e skol dower" );
   orthoPhrases.push_back( "an eye scold hour" );
   orthoPhrases.push_back( "an eye scold our" );
   orthoPhrases.push_back( "an eye skol dour" );
   orthoPhrases.push_back( "an eye skol dower" );
   orthoPhrases.push_back( "an i scold hour" );
   orthoPhrases.push_back( "an i scold our" );
   orthoPhrases.push_back( "an i skol dour" );
   orthoPhrases.push_back( "an i skol dower" );
   orthoPhrases.push_back( "an ice coal dour" );
   orthoPhrases.push_back( "an ice coal dower" );
   orthoPhrases.push_back( "an ice cold hour" );
   orthoPhrases.push_back( "an ice cold our" );
   orthoPhrases.push_back( "an ice cole dour" );
   orthoPhrases.push_back( "an ice cole dower" );
   orthoPhrases.push_back( "an ice kohl dour" );
   orthoPhrases.push_back( "an ice kohl dower" );
   orthoPhrases.push_back( "an ice-cold hour" );
   orthoPhrases.push_back( "an ice-cold our" );
   orthoPhrases.push_back( "eh gneiss coal dour" );
   orthoPhrases.push_back( "eh gneiss coal dower" );
   orthoPhrases.push_back( "eh gneiss cold hour" );
   orthoPhrases.push_back( "eh gneiss cold our" );
   orthoPhrases.push_back( "eh gneiss cole dour" );
   orthoPhrases.push_back( "eh gneiss cole dower" );
   orthoPhrases.push_back( "eh gneiss kohl dour" );
   orthoPhrases.push_back( "eh gneiss kohl dower" );
   orthoPhrases.push_back( "eh knee scold hour" );
   orthoPhrases.push_back( "eh knee scold our" );
   orthoPhrases.push_back( "eh knee skol dour" );
   orthoPhrases.push_back( "eh knee skol dower" );
   orthoPhrases.push_back( "eh ne scold hour" );
   orthoPhrases.push_back( "eh ne scold our" );
   orthoPhrases.push_back( "eh ne skol dour" );
   orthoPhrases.push_back( "eh ne skol dower" );
   orthoPhrases.push_back( "eh nice coal dour" );
   orthoPhrases.push_back( "eh nice coal dower" );
   orthoPhrases.push_back( "eh nice cold hour" );
   orthoPhrases.push_back( "eh nice cold our" );
   orthoPhrases.push_back( "eh nice cole dour" );
   orthoPhrases.push_back( "eh nice cole dower" );
   orthoPhrases.push_back( "eh nice kohl dour" );
   orthoPhrases.push_back( "eh nice kohl dower" );
   orthoPhrases.push_back( "eh niece coal dour" );
   orthoPhrases.push_back( "eh niece coal dower" );
   orthoPhrases.push_back( "eh niece cold hour" );
   orthoPhrases.push_back( "eh niece cold our" );
   orthoPhrases.push_back( "eh niece cole dour" );
   orthoPhrases.push_back( "eh niece cole dower" );
   orthoPhrases.push_back( "eh niece kohl dour" );
   orthoPhrases.push_back( "eh niece kohl dower" );
   orthoPhrases.push_back( "eh nigh scold hour" );
   orthoPhrases.push_back( "eh nigh scold our" );
   orthoPhrases.push_back( "eh nigh skol dour" );
   orthoPhrases.push_back( "eh nigh skol dower" );
   orthoPhrases.push_back( "eh nye scold hour" );
   orthoPhrases.push_back( "eh nye scold our" );
   orthoPhrases.push_back( "eh nye skol dour" );
   orthoPhrases.push_back( "eh nye skol dower" );
   orthoPhrases.push_back( "et gneiss coal dour" );
   orthoPhrases.push_back( "et gneiss coal dower" );
   orthoPhrases.push_back( "et gneiss cold hour" );
   orthoPhrases.push_back( "et gneiss cold our" );
   orthoPhrases.push_back( "et gneiss cole dour" );
   orthoPhrases.push_back( "et gneiss cole dower" );
   orthoPhrases.push_back( "et gneiss kohl dour" );
   orthoPhrases.push_back( "et gneiss kohl dower" );
   orthoPhrases.push_back( "et knee scold hour" );
   orthoPhrases.push_back( "et knee scold our" );
   orthoPhrases.push_back( "et knee skol dour" );
   orthoPhrases.push_back( "et knee skol dower" );
   orthoPhrases.push_back( "et ne scold hour" );
   orthoPhrases.push_back( "et ne scold our" );
   orthoPhrases.push_back( "et ne skol dour" );
   orthoPhrases.push_back( "et ne skol dower" );
   orthoPhrases.push_back( "et nice coal dour" );
   orthoPhrases.push_back( "et nice coal dower" );
   orthoPhrases.push_back( "et nice cold hour" );
   orthoPhrases.push_back( "et nice cold our" );
   orthoPhrases.push_back( "et nice cole dour" );
   orthoPhrases.push_back( "et nice cole dower" );
   orthoPhrases.push_back( "et nice kohl dour" );
   orthoPhrases.push_back( "et nice kohl dower" );
   orthoPhrases.push_back( "et niece coal dour" );
   orthoPhrases.push_back( "et niece coal dower" );
   orthoPhrases.push_back( "et niece cold hour" );
   orthoPhrases.push_back( "et niece cold our" );
   orthoPhrases.push_back( "et niece cole dour" );
   orthoPhrases.push_back( "et niece cole dower" );
   orthoPhrases.push_back( "et niece kohl dour" );
   orthoPhrases.push_back( "et niece kohl dower" );
   orthoPhrases.push_back( "et nigh scold hour" );
   orthoPhrases.push_back( "et nigh scold our" );
   orthoPhrases.push_back( "et nigh skol dour" );
   orthoPhrases.push_back( "et nigh skol dower" );
   orthoPhrases.push_back( "et nye scold hour" );
   orthoPhrases.push_back( "et nye scold our" );
   orthoPhrases.push_back( "et nye skol dour" );
   orthoPhrases.push_back( "et nye skol dower" );
   orthoPhrases.push_back( "o' gneiss coal dour" );
   orthoPhrases.push_back( "o' gneiss coal dower" );
   orthoPhrases.push_back( "o' gneiss cold hour" );
   orthoPhrases.push_back( "o' gneiss cold our" );
   orthoPhrases.push_back( "o' gneiss cole dour" );
   orthoPhrases.push_back( "o' gneiss cole dower" );
   orthoPhrases.push_back( "o' gneiss kohl dour" );
   orthoPhrases.push_back( "o' gneiss kohl dower" );
   orthoPhrases.push_back( "o' knee scold hour" );
   orthoPhrases.push_back( "o' knee scold our" );
   orthoPhrases.push_back( "o' knee skol dour" );
   orthoPhrases.push_back( "o' knee skol dower" );
   orthoPhrases.push_back( "o' ne scold hour" );
   orthoPhrases.push_back( "o' ne scold our" );
   orthoPhrases.push_back( "o' ne skol dour" );
   orthoPhrases.push_back( "o' ne skol dower" );
   orthoPhrases.push_back( "o' nice coal dour" );
   orthoPhrases.push_back( "o' nice coal dower" );
   orthoPhrases.push_back( "o' nice cold hour" );
   orthoPhrases.push_back( "o' nice cold our" );
   orthoPhrases.push_back( "o' nice cole dour" );
   orthoPhrases.push_back( "o' nice cole dower" );
   orthoPhrases.push_back( "o' nice kohl dour" );
   orthoPhrases.push_back( "o' nice kohl dower" );
   orthoPhrases.push_back( "o' niece coal dour" );
   orthoPhrases.push_back( "o' niece coal dower" );
   orthoPhrases.push_back( "o' niece cold hour" );
   orthoPhrases.push_back( "o' niece cold our" );
   orthoPhrases.push_back( "o' niece cole dour" );
   orthoPhrases.push_back( "o' niece cole dower" );
   orthoPhrases.push_back( "o' niece kohl dour" );
   orthoPhrases.push_back( "o' niece kohl dower" );
   orthoPhrases.push_back( "o' nigh scold hour" );
   orthoPhrases.push_back( "o' nigh scold our" );
   orthoPhrases.push_back( "o' nigh skol dour" );
   orthoPhrases.push_back( "o' nigh skol dower" );
   orthoPhrases.push_back( "o' nye scold hour" );
   orthoPhrases.push_back( "o' nye scold our" );
   orthoPhrases.push_back( "o' nye skol dour" );
   orthoPhrases.push_back( "o' nye skol dower" );
   orthoPhrases.push_back( "on ay scold hour" );
   orthoPhrases.push_back( "on ay scold our" );
   orthoPhrases.push_back( "on ay skol dour" );
   orthoPhrases.push_back( "on ay skol dower" );
   orthoPhrases.push_back( "on aye scold hour" );
   orthoPhrases.push_back( "on aye scold our" );
   orthoPhrases.push_back( "on aye skol dour" );
   orthoPhrases.push_back( "on aye skol dower" );
   orthoPhrases.push_back( "on e scold hour" );
   orthoPhrases.push_back( "on e scold our" );
   orthoPhrases.push_back( "on e skol dour" );
   orthoPhrases.push_back( "on e skol dower" );
   orthoPhrases.push_back( "on eye scold hour" );
   orthoPhrases.push_back( "on eye scold our" );
   orthoPhrases.push_back( "on eye skol dour" );
   orthoPhrases.push_back( "on eye skol dower" );
   orthoPhrases.push_back( "on i scold hour" );
   orthoPhrases.push_back( "on i scold our" );
   orthoPhrases.push_back( "on i skol dour" );
   orthoPhrases.push_back( "on i skol dower" );
   orthoPhrases.push_back( "on ice coal dour" );
   orthoPhrases.push_back( "on ice coal dower" );
   orthoPhrases.push_back( "on ice cold hour" );
   orthoPhrases.push_back( "on ice cold our" );
   orthoPhrases.push_back( "on ice cole dour" );
   orthoPhrases.push_back( "on ice cole dower" );
   orthoPhrases.push_back( "on ice kohl dour" );
   orthoPhrases.push_back( "on ice kohl dower" );
   orthoPhrases.push_back( "on ice-cold hour" );
   orthoPhrases.push_back( "on ice-cold our" );
   }

   /*
   {
   orthoPhrases.push_back( "	on ice-cold our  	" );
orthoPhrases.push_back( "	on ice-cold hour  	" );
orthoPhrases.push_back( "	on ice kohl dower  	" );
orthoPhrases.push_back( "	on ice kohl dour  	" );
orthoPhrases.push_back( "	on ice cole dower  	" );
orthoPhrases.push_back( "	on ice cole dour  	" );
orthoPhrases.push_back( "	on ice cold our  	" );
orthoPhrases.push_back( "	on ice coal dour  	" );
orthoPhrases.push_back( "	on i skol dower  	" );
orthoPhrases.push_back( "	on i skol dour  	" );
orthoPhrases.push_back( "	on i scold our  	" );
orthoPhrases.push_back( "	on i scold hour  	" );
orthoPhrases.push_back( "	on eye skol dower  	" );
orthoPhrases.push_back( "	on eye skol dour  	" );
orthoPhrases.push_back( "	on eye scold our  	" );
orthoPhrases.push_back( "	on eye scold hour  	" );
orthoPhrases.push_back( "	on aye skol dower  	" );
orthoPhrases.push_back( "	on aye skol dour  	" );
orthoPhrases.push_back( "	eh nye skol dower  	" );
orthoPhrases.push_back( "	eh nye skol dour  	" );
orthoPhrases.push_back( "	eh nye scold our  	" );
orthoPhrases.push_back( "	eh nye scold hour  	" );
orthoPhrases.push_back( "	eh nigh skol dower  	" );
orthoPhrases.push_back( "	eh nigh skol dour  	" );
orthoPhrases.push_back( "	eh nigh scold our  	" );
orthoPhrases.push_back( "	eh nigh scold hour  	" );
orthoPhrases.push_back( "	eh nice kohl dower  	" );
orthoPhrases.push_back( "	eh nice kohl dour  	" );
orthoPhrases.push_back( "	eh nice cole dour  	" );
orthoPhrases.push_back( "	eh nice cold our  	" );
orthoPhrases.push_back( "	eh nice cold hour  	" );
orthoPhrases.push_back( "	eh nice coal dower  	" );
orthoPhrases.push_back( "	eh nice coal dour  	" );
orthoPhrases.push_back( "	a nice coal dower  	" );
orthoPhrases.push_back( "	a nye scold hour  	" );
orthoPhrases.push_back( "	on ice cold hour  	" );
orthoPhrases.push_back( "	an ice kohl dour  	" );
orthoPhrases.push_back( "	on ice coal dower  	" );
orthoPhrases.push_back( "	an ice cole dour  	" );
orthoPhrases.push_back( "	an ice cold hour  	" );
orthoPhrases.push_back( "	ah nice coal dower  	" );
orthoPhrases.push_back( "	an ice coal dour  	" );
orthoPhrases.push_back( "	an i skol dower  	" );
orthoPhrases.push_back( "	an i skol dour  	" );
orthoPhrases.push_back( "	an i scold our  	" );
orthoPhrases.push_back( "	an i scold hour  	" );
orthoPhrases.push_back( "	an ice coal dower  	" );
orthoPhrases.push_back( "	an eye skol dour  	" );
orthoPhrases.push_back( "	an ice-cold our  	" );
orthoPhrases.push_back( "	an eye scold hour  	" );
orthoPhrases.push_back( "	an eye skol dower  	" );
orthoPhrases.push_back( "	an aye skol dour  	" );
orthoPhrases.push_back( "	an aye scold our  	" );
orthoPhrases.push_back( "	an aye scold hour  	" );
orthoPhrases.push_back( "	ah nye skol dower  	" );
orthoPhrases.push_back( "	ah nye skol dour  	" );
orthoPhrases.push_back( "	an aye skol dower  	" );
orthoPhrases.push_back( "	ah nye scold hour  	" );
orthoPhrases.push_back( "	ah nigh skol dower  	" );
orthoPhrases.push_back( "	ah nigh skol dour  	" );
orthoPhrases.push_back( "	ah nigh scold our  	" );
orthoPhrases.push_back( "	ah nigh scold hour  	" );
orthoPhrases.push_back( "	ah nice kohl dower  	" );
orthoPhrases.push_back( "	ah nice kohl dour  	" );
orthoPhrases.push_back( "	ah nice cole dower  	" );
orthoPhrases.push_back( "	ah nice cole dour  	" );
orthoPhrases.push_back( "	ah nice cold our  	" );
orthoPhrases.push_back( "	ah nice cold hour  	" );
orthoPhrases.push_back( "	a nye skol dower  	" );
orthoPhrases.push_back( "	ah nice coal dour  	" );
orthoPhrases.push_back( "	a nigh scold our  	" );
orthoPhrases.push_back( "	a nye skol dour  	" );
orthoPhrases.push_back( "	an ice-cold hour  	" );
orthoPhrases.push_back( "	on aye scold our  	" );
orthoPhrases.push_back( "	a nigh skol dower  	" );
orthoPhrases.push_back( "	a nigh skol dour  	" );
orthoPhrases.push_back( "	an ice cole dower  	" );
orthoPhrases.push_back( "	a nigh scold hour  	" );
orthoPhrases.push_back( "	a nice kohl dower  	" );
orthoPhrases.push_back( "	a nice kohl dour  	" );
orthoPhrases.push_back( "	a nice cole dower  	" );
orthoPhrases.push_back( "	a nice cole dour  	" );
orthoPhrases.push_back( "	an ice kohl dower  	" );
orthoPhrases.push_back( "	a nice cold hour  	" );
orthoPhrases.push_back( "	eh nice cole dower  	" );
orthoPhrases.push_back( "	a nice coal dour  	" );
orthoPhrases.push_back( "	an eye scold our  	" );
orthoPhrases.push_back( "	ah nye scold our  	" );
orthoPhrases.push_back( "	a nye scold our  	" );
orthoPhrases.push_back( "	a nice cold our  	" );
orthoPhrases.push_back( "	an ice cold our  	" );

   } 
   */
   /*
   {
   orthoPhrases.push_back("	'n' ay scold hour 	");
   orthoPhrases.push_back("	'n' ay scold our 	");
   orthoPhrases.push_back("	'n' ay skol dour 	");
   orthoPhrases.push_back("	'n' ay skol dower 	");
   orthoPhrases.push_back("	'n' aye scold hour 	");
   orthoPhrases.push_back("	'n' aye scold our 	");
   orthoPhrases.push_back("	'n' aye skol dour 	");
   orthoPhrases.push_back("	'n' aye skol dower 	");
   orthoPhrases.push_back("	'n' eye scold hour 	");
   orthoPhrases.push_back("	'n' eye scold our 	");
   orthoPhrases.push_back("	'n' eye skol dour 	");
   orthoPhrases.push_back("	'n' eye skol dower 	");
   orthoPhrases.push_back("	'n' i scold hour 	");
   orthoPhrases.push_back("	'n' i scold our 	");
   orthoPhrases.push_back("	'n' i skol dour 	");
   orthoPhrases.push_back("	'n' i skol dower 	");
   orthoPhrases.push_back("	'n' ice coal dour 	");
   orthoPhrases.push_back("	'n' ice coal dower 	");
   orthoPhrases.push_back("	'n' ice cold hour 	");
   orthoPhrases.push_back("	'n' ice cold our 	");
   orthoPhrases.push_back("	'n' ice cole dour 	");
   orthoPhrases.push_back("	'n' ice cole dower 	");
   orthoPhrases.push_back("	'n' ice kohl dour 	");
   orthoPhrases.push_back("	'n' ice kohl dower 	");
   orthoPhrases.push_back("	'n' ice-cold hour 	");
   orthoPhrases.push_back("	'n' ice-cold our 	");
   orthoPhrases.push_back("	a gneiss coal dour 	");
   orthoPhrases.push_back("	a gneiss coal dower 	");
   orthoPhrases.push_back("	a gneiss cold hour 	");
   orthoPhrases.push_back("	a gneiss cold our 	");
   orthoPhrases.push_back("	a gneiss cole dour 	");
   orthoPhrases.push_back("	a gneiss cole dower 	");
   orthoPhrases.push_back("	a gneiss kohl dour 	");
   orthoPhrases.push_back("	a gneiss kohl dower 	");
   orthoPhrases.push_back("	a nice coal dour 	");
   orthoPhrases.push_back("	a nice coal dower 	");
   orthoPhrases.push_back("	a nice cold hour 	");
   orthoPhrases.push_back("	a nice cold our 	");
   orthoPhrases.push_back("	a nice cole dour 	");
   orthoPhrases.push_back("	a nice cole dower 	");
   orthoPhrases.push_back("	a nice kohl dour 	");
   orthoPhrases.push_back("	a nice kohl dower 	");
   orthoPhrases.push_back("	a nigh scold hour 	");
   orthoPhrases.push_back("	a nigh scold our 	");
   orthoPhrases.push_back("	a nigh skol dour 	");
   orthoPhrases.push_back("	a nigh skol dower 	");
   orthoPhrases.push_back("	a nye scold hour 	");
   orthoPhrases.push_back("	a nye scold our 	");
   orthoPhrases.push_back("	a nye skol dour 	");
   orthoPhrases.push_back("	a nye skol dower 	");
   orthoPhrases.push_back("	an ay scold hour 	");
   orthoPhrases.push_back("	an ay scold our 	");
   orthoPhrases.push_back("	an ay skol dour 	");
   orthoPhrases.push_back("	an ay skol dower 	");
   orthoPhrases.push_back("	an aye scold hour 	");
   orthoPhrases.push_back("	an aye scold our 	");
   orthoPhrases.push_back("	an aye skol dour 	");
   orthoPhrases.push_back("	an aye skol dower 	");
   orthoPhrases.push_back("	an eye scold hour 	");
   orthoPhrases.push_back("	an eye scold our 	");
   orthoPhrases.push_back("	an eye skol dour 	");
   orthoPhrases.push_back("	an eye skol dower 	");
   orthoPhrases.push_back("	an i scold hour 	");
   orthoPhrases.push_back("	an i scold our 	");
   orthoPhrases.push_back("	an i skol dour 	");
   orthoPhrases.push_back("	an i skol dower 	");
   orthoPhrases.push_back("	an ice coal dour 	");
   orthoPhrases.push_back("	an ice coal dower 	");
   orthoPhrases.push_back("	an ice cold hour 	");
   orthoPhrases.push_back("	an ice cold our 	");
   orthoPhrases.push_back("	an ice cole dour 	");
   orthoPhrases.push_back("	an ice cole dower 	");
   orthoPhrases.push_back("	an ice kohl dour 	");
   orthoPhrases.push_back("	an ice kohl dower 	");
   orthoPhrases.push_back("	an ice-cold hour 	");
   orthoPhrases.push_back("	an ice-cold our 	");
   orthoPhrases.push_back("	ann ay scold hour 	");
   orthoPhrases.push_back("	ann ay scold our 	");
   orthoPhrases.push_back("	ann ay skol dour 	");
   orthoPhrases.push_back("	ann ay skol dower 	");
   orthoPhrases.push_back("	ann aye scold hour 	");
   orthoPhrases.push_back("	ann aye scold our 	");
   orthoPhrases.push_back("	ann aye skol dour 	");
   orthoPhrases.push_back("	ann aye skol dower 	");
   orthoPhrases.push_back("	ann eye scold hour 	");
   orthoPhrases.push_back("	ann eye scold our 	");
   orthoPhrases.push_back("	ann eye skol dour 	");
   orthoPhrases.push_back("	ann eye skol dower 	");
   orthoPhrases.push_back("	ann i scold hour 	");
   orthoPhrases.push_back("	ann i scold our 	");
   orthoPhrases.push_back("	ann i skol dour 	");
   orthoPhrases.push_back("	ann i skol dower 	");
   orthoPhrases.push_back("	ann ice coal dour 	");
   orthoPhrases.push_back("	ann ice coal dower 	");
   orthoPhrases.push_back("	ann ice cold hour 	");
   orthoPhrases.push_back("	ann ice cold our 	");
   orthoPhrases.push_back("	ann ice cole dour 	");
   orthoPhrases.push_back("	ann ice cole dower 	");
   orthoPhrases.push_back("	ann ice kohl dour 	");
   orthoPhrases.push_back("	ann ice kohl dower 	");
   orthoPhrases.push_back("	ann ice-cold hour 	");
   orthoPhrases.push_back("	ann ice-cold our 	");
   orthoPhrases.push_back("	anne ay scold hour 	");
   orthoPhrases.push_back("	anne ay scold our 	");
   orthoPhrases.push_back("	anne ay skol dour 	");
   orthoPhrases.push_back("	anne ay skol dower 	");
   orthoPhrases.push_back("	anne aye scold hour 	");
   orthoPhrases.push_back("	anne aye scold our 	");
   orthoPhrases.push_back("	anne aye skol dour 	");
   orthoPhrases.push_back("	anne aye skol dower 	");
   orthoPhrases.push_back("	anne eye scold hour 	");
   orthoPhrases.push_back("	anne eye scold our 	");
   orthoPhrases.push_back("	anne eye skol dour 	");
   orthoPhrases.push_back("	anne eye skol dower 	");
   orthoPhrases.push_back("	anne i scold hour 	");
   orthoPhrases.push_back("	anne i scold our 	");
   orthoPhrases.push_back("	anne i skol dour 	");
   orthoPhrases.push_back("	anne i skol dower 	");
   orthoPhrases.push_back("	anne ice coal dour 	");
   orthoPhrases.push_back("	anne ice coal dower 	");
   orthoPhrases.push_back("	anne ice cold hour 	");
   orthoPhrases.push_back("	anne ice cold our 	");
   orthoPhrases.push_back("	anne ice cole dour 	");
   orthoPhrases.push_back("	anne ice cole dower 	");
   orthoPhrases.push_back("	anne ice kohl dour 	");
   orthoPhrases.push_back("	anne ice kohl dower 	");
   orthoPhrases.push_back("	anne ice-cold hour 	");
   orthoPhrases.push_back("	anne ice-cold our 	");
   orthoPhrases.push_back("	o' gneiss coal dour 	");
   orthoPhrases.push_back("	o' gneiss coal dower 	");
   orthoPhrases.push_back("	o' gneiss cold hour 	");
   orthoPhrases.push_back("	o' gneiss cold our 	");
   orthoPhrases.push_back("	o' gneiss cole dour 	");
   orthoPhrases.push_back("	o' gneiss cole dower 	");
   orthoPhrases.push_back("	o' gneiss kohl dour 	");
   orthoPhrases.push_back("	o' gneiss kohl dower 	");
   orthoPhrases.push_back("	o' nice coal dour 	");
   orthoPhrases.push_back("	o' nice coal dower 	");
   orthoPhrases.push_back("	o' nice cold hour 	");
   orthoPhrases.push_back("	o' nice cold our 	");
   orthoPhrases.push_back("	o' nice cole dour 	");
   orthoPhrases.push_back("	o' nice cole dower 	");
   orthoPhrases.push_back("	o' nice kohl dour 	");
   orthoPhrases.push_back("	o' nice kohl dower 	");
   orthoPhrases.push_back("	o' nigh scold hour 	");
   orthoPhrases.push_back("	o' nigh scold our 	");
   orthoPhrases.push_back("	o' nigh skol dour 	");
   orthoPhrases.push_back("	o' nigh skol dower 	");
   orthoPhrases.push_back("	o' nye scold hour 	");
   orthoPhrases.push_back("	o' nye scold our 	");
   orthoPhrases.push_back("	o' nye skol dour 	");
   orthoPhrases.push_back("	o' nye skol dower 	");
   }
*/
/*
   {
   orthoPhrases.push_back( "	a light cold hour	" );
   orthoPhrases.push_back( "	a nice bold hour	" );
   orthoPhrases.push_back( "	a nice called hour	" );
   orthoPhrases.push_back( "	a nice coal dour	" );
   orthoPhrases.push_back( "	a nice coal dower	" );
   orthoPhrases.push_back( "	a nice cob bower	" );
   orthoPhrases.push_back( "	a nice cob our	" );
   orthoPhrases.push_back( "	a nice cobour	" );
   orthoPhrases.push_back( "	a nice code hour	" );
   orthoPhrases.push_back( "	a nice cold bowl	" );
   orthoPhrases.push_back( "	a nice cold dollar	" );
   orthoPhrases.push_back( "	a nice cold dour	" );
   orthoPhrases.push_back( "	a nice cold dower	" );
   orthoPhrases.push_back( "	a nice cold hour	" );
   orthoPhrases.push_back( "	a nice cold hout	" );
   orthoPhrases.push_back( "	a nice cold our	" );
   orthoPhrases.push_back( "	a nice cold shower	" );
   orthoPhrases.push_back( "	a nice cold thou are	" );
   orthoPhrases.push_back( "	a nice cool bowl	" );
   orthoPhrases.push_back( "	a nice cool dollar	" );
   orthoPhrases.push_back( "	a nice cool dower	" );
   orthoPhrases.push_back( "	a nice cool hour	" );
   orthoPhrases.push_back( "	a nice could hour	" );
   orthoPhrases.push_back( "	a nice cow is there	" );
   orthoPhrases.push_back( "	a nice fold hour	" );
   orthoPhrases.push_back( "	a nice for the hour	" );
   orthoPhrases.push_back( "	a nice go the our	" );
   orthoPhrases.push_back( "	a nice godfather	" );
   orthoPhrases.push_back( "	a nice gold dollar	" );
   orthoPhrases.push_back( "	a nice gold dour	" );
   orthoPhrases.push_back( "	a nice gold dower	" );
   orthoPhrases.push_back( "	a nice gold hour	" );
   orthoPhrases.push_back( "	a nice odd hour	" );
   orthoPhrases.push_back( "	a nice old hour	" );
   orthoPhrases.push_back( "	a nice pod our	" );
   orthoPhrases.push_back( "	a nice pollard	" );
   orthoPhrases.push_back( "	a nice school bower	" );
   orthoPhrases.push_back( "	a nice scold dower	" );
   orthoPhrases.push_back( "	a nice scold hour	" );
   orthoPhrases.push_back( "	a nice scored hour	" );
   orthoPhrases.push_back( "	a nice screw driver	" );
   orthoPhrases.push_back( "	a nice screwdriver	" );
   orthoPhrases.push_back( "	a nice spoke hour	" );
   orthoPhrases.push_back( "	a nice cold hour	" );
   orthoPhrases.push_back( "	a niceco daver	" );
   orthoPhrases.push_back( "	a nigh scold hour	" );
   orthoPhrases.push_back( "	a nights cold hour	" );
   orthoPhrases.push_back( "	a nine scold hour	" );
   orthoPhrases.push_back( "	a nine skulled hour	" );
   orthoPhrases.push_back( "	a nine spole dower	" );
   orthoPhrases.push_back( "	a nye scoldower	" );
   orthoPhrases.push_back( "	ah nay skull dower	" );
   orthoPhrases.push_back( "	all eyes cold hour	" );
   orthoPhrases.push_back( "	all ice cold hour	" );
   orthoPhrases.push_back( "	an eye scol dagr	" );
   orthoPhrases.push_back( "	an eye scold hour	" );
   orthoPhrases.push_back( "	an eye scold our	" );
   orthoPhrases.push_back( "	an eyes close over	" );
   orthoPhrases.push_back( "	an eyes co thou	" );
   orthoPhrases.push_back( "	an eyes cold hour	" );
   orthoPhrases.push_back( "	an eyes hold power	" );
   orthoPhrases.push_back( "	an i scold dour	" );
   orthoPhrases.push_back( "	an i scold hour	" );
   orthoPhrases.push_back( "	an i screw driver	" );
   orthoPhrases.push_back( "	an i screwdriver	" );
   orthoPhrases.push_back( "	an ice bore bower	" );
   orthoPhrases.push_back( "	an ice called dower	" );
   orthoPhrases.push_back( "	an ice coal dour	" );
   orthoPhrases.push_back( "	an ice coal dower	" );
   orthoPhrases.push_back( "	an ice cob our	" );
   orthoPhrases.push_back( "	an ice cold bauer	" );
   orthoPhrases.push_back( "	an ice cold bower	" );
   orthoPhrases.push_back( "	an ice cold bowl	" );
   orthoPhrases.push_back( "	an ice cold dollar	" );
   orthoPhrases.push_back( "	an ice cold dour	" );
   orthoPhrases.push_back( "	an ice cold dower	" );
   orthoPhrases.push_back( "	an ice cold grave	" );
   orthoPhrases.push_back( "	an ice cold hour	" );
   orthoPhrases.push_back( "	an ice cold our	" );
   orthoPhrases.push_back( "	an ice cold ower	" );
   orthoPhrases.push_back( "	an ice cold shower	" );
   orthoPhrases.push_back( "	an ice cold thou are	" );
   orthoPhrases.push_back( "	an ice cole dower	" );
   orthoPhrases.push_back( "	an ice cool bower	" );
   orthoPhrases.push_back( "	an ice core bower	" );
   orthoPhrases.push_back( "	an ice could hour	" );
   orthoPhrases.push_back( "	an ice cove daver	" );
   orthoPhrases.push_back( "	an ice go the our	" );
   orthoPhrases.push_back( "	an ice gold dower	" );
   orthoPhrases.push_back( "	an ice gold hour	" );
   orthoPhrases.push_back( "	an ice hold hour	" );
   orthoPhrases.push_back( "	an ice hold power	" );
   orthoPhrases.push_back( "	an ice old hour	" );
   orthoPhrases.push_back( "	an ice scold hour	" );
   orthoPhrases.push_back( "	an ice-cold hour	" );
   orthoPhrases.push_back( "	an iced cold dower	" );
   orthoPhrases.push_back( "	an iced cold hour	" );
   orthoPhrases.push_back( "	an nice cold hour	" );
   orthoPhrases.push_back( "	an nice cold our	" );
   orthoPhrases.push_back( "	an ounce gold hour	" );
   orthoPhrases.push_back( "	and i scold hour	" );
   orthoPhrases.push_back( "	and i scold our	" );
   orthoPhrases.push_back( "	and i scored over	" );
   orthoPhrases.push_back( "	and i scored the hour	" );
   orthoPhrases.push_back( "	and ice cold dollar	" );
   orthoPhrases.push_back( "	and nice cold hour	" );
   orthoPhrases.push_back( "	can i score the hour	" );
   orthoPhrases.push_back( "	can i spoke hour	" );
   orthoPhrases.push_back( "	ei nice cold hour	" );
   orthoPhrases.push_back( "	ej nice cold hout	" );
   orthoPhrases.push_back( "	ej nice cold ohur	" );
   orthoPhrases.push_back( "	enoise cothawer	" );
   orthoPhrases.push_back( "	he nice on the hour	" );
   orthoPhrases.push_back( "	hen eyes oh dawad	" );
   orthoPhrases.push_back( "	hen eyes oh gawd	" );
   orthoPhrases.push_back( "	hen ice oh dawad	" );
   orthoPhrases.push_back( "	hey nice go the our	" );
   orthoPhrases.push_back( "	hey nice go there where	" );
   orthoPhrases.push_back( "	hey nice hold hour	" );
   orthoPhrases.push_back( "	hey nice screwdriver	" );
   orthoPhrases.push_back( "	hey nine scold hour	" );
   orthoPhrases.push_back( "	i saw tower	" );
   orthoPhrases.push_back( "	in a ice cold hour	" );
   orthoPhrases.push_back( "	in a ice cool hour	" );
   orthoPhrases.push_back( "	in eye spole dower	" );
   orthoPhrases.push_back( "	in eyes cold over	" );
   orthoPhrases.push_back( "	in high school hour	" );
   orthoPhrases.push_back( "	in i scold hour	" );
   orthoPhrases.push_back( "	in ice called our	" );
   orthoPhrases.push_back( "	in ice co daver	" );
   orthoPhrases.push_back( "	in ice coal dour	" );
   orthoPhrases.push_back( "	in ice code our	" );
   orthoPhrases.push_back( "	in ice cold davar	" );
   orthoPhrases.push_back( "	in ice cold dour	" );
   orthoPhrases.push_back( "	in ice cold hour	" );
   orthoPhrases.push_back( "	in ice cold our	" );
   orthoPhrases.push_back( "	in ice go tower	" );
   orthoPhrases.push_back( "	in ice gold hour	" );
   orthoPhrases.push_back( "	in ice old hour	" );
   orthoPhrases.push_back( "	in ice-cold hour	" );
   orthoPhrases.push_back( "	in icecube daver	" );
   orthoPhrases.push_back( "	in nice code our	" );
   orthoPhrases.push_back( "	in nice code over	" );
   orthoPhrases.push_back( "	in nice cold hour	" );
   orthoPhrases.push_back( "	in the eyeschool tower	" );
   orthoPhrases.push_back( "	in the ice cold hour	" );
   orthoPhrases.push_back( "	in unschooled hour	" );
   orthoPhrases.push_back( "	make noice whole the hour	" );
   orthoPhrases.push_back( "	n i screwdriver	" );
   orthoPhrases.push_back( "	ni screwdriver	" );
   orthoPhrases.push_back( "	nice cold hour	" );
   orthoPhrases.push_back( "	on a nice cold hour	" );
   orthoPhrases.push_back( "	on eis kol dour	" );
   orthoPhrases.push_back( "	on eyes cold over	" );
   orthoPhrases.push_back( "	on eyes go there	" );
   orthoPhrases.push_back( "	on i screwdriver	" );
   orthoPhrases.push_back( "	on ice call dour	" );
   orthoPhrases.push_back( "	on ice called our	" );
   orthoPhrases.push_back( "	on ice co dover	" );
   orthoPhrases.push_back( "	on ice coal dour	" );
   orthoPhrases.push_back( "	on ice col dour	" );
   orthoPhrases.push_back( "	on ice cold air	" );
   orthoPhrases.push_back( "	on ice cold bauer	" );
   orthoPhrases.push_back( "	on ice cold dour	" );
   orthoPhrases.push_back( "	on ice cold dower	" );
   orthoPhrases.push_back( "	on ice cold hour	" );
   orthoPhrases.push_back( "	on ice cold our	" );
   orthoPhrases.push_back( "	on ice cold thou art	" );
   orthoPhrases.push_back( "	on ice core bower	" );
   orthoPhrases.push_back( "	on ice old hour	" );
   orthoPhrases.push_back( "	on iced cold hour	" );
   orthoPhrases.push_back( "	on the ice cold dour	" );
   orthoPhrases.push_back( "	on the ice cold hour	" );
   orthoPhrases.push_back( "	the nice cold hour	" );
   orthoPhrases.push_back( "	then ice go their were	" );
   orthoPhrases.push_back( "	then ice go there  our	" );
   orthoPhrases.push_back( "	then ice hole power	" );
   orthoPhrases.push_back( "	then ices co the where	" );
   orthoPhrases.push_back( "	we nice old hour	" );

   }
    */
   return orthoPhrases;
}

void oldMain() {

   connectToFreqDictionaryDatabase();

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
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= testGetTotalFreqForPhrase();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_getCSVofAllPhraseFreqs();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_getCSVofEachPhrasesWordsFreqs();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_getCSVofWordFreqsForPhrase();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   /*
   test_DrawRect();
   testsPassed &= true;
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   test_DrawStackedBar();
   testsPassed &= true;
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   */
   testsPassed &= test_getAllFirstWords();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_removeSuccessAndDeadendIndicatorsFromString();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_stripOronymOutputOfEndIndicators();
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_makeProtvisDiagram();
 /*
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= 
*/   cout << "XXXXXXXXXXXXXXXXXXXXXX___DONE___XXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   return testsPassed;
}

void usageMessage() {
   cout << "Usage: ./testWordBreakdown [test type option] [input]\n"; 
   cout << "Available options: ";
   cout << "\n\t\t all";
   cout << "\n\t\t discoverOronymsForPhrase";   
   cout << "\n\t\t queryDBwithOrthoForSampaStrs";
   cout << "\n\t\t queryDBwithOrthoForFreq";
   cout << "\n\t\t findAllPhoneSeqsForOrthoPhrase";   
   cout << "\n\t\t getCSVofEachPhrasesWordsFreqs";
   cout << "\n\t\t getTotalFreqForPhrase";
   cout << "\n\t\t stripSampaStrOfEmph";
   cout << "\n\t\t getSampaStrWithoutGlottalStops";
   cout << "\n\t\t getSampaStrWithoutContiguousDuplicatePhones";
   cout << "\n\t\t strTokOnWhitespace";
   cout << "\n\t\t findPhoneTreeForOrthoPhrase";
   cout << "\n\t\t queryDBForOrthoStrsWithSampaPrefix";
   cout << "\n\t\t queryDBwithSampaForOrthoStrs";
   cout << "\n\t\t trimWhitespace";
   cout << "\n\t\t getCSVofAllPhraseFreqs";
   cout << "\n\t\t getCSVofWordFreqsForPhrase";
   cout << "\n\t\t generateStackedBarGraphOronymTree";   
   cout << "\n\t\t drawRectangle";   
   cout << "\n\t\t getAllFirstWords";   
   cout << "\n\t\t removeSuccessAndDeadendIndicatorsFromString"; 
   cout << "\n\t\t stripOronymOutputOfEndIndicators";  
   cout << "\n\t\t makeProtvisDiagram";

   cout << "\n\t\t help";
   cout << "\n\t\t oldMain\n";
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
      } else if( strcmp( argv[1], "queryDBwithOrthoForSampaStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForSampaStrs();
      } else if( strcmp( argv[1], "queryDBwithOrthoForFreq") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForFreq();
      } else if( strcmp( argv[1], "queryDBForOrthoStrsWithSampaPrefix") == 0 ) {
         allTestsPassed &= testQueryDBForOrthoStrsWithSampaPrefix();
      } else if( strcmp( argv[1], "queryDBwithSampaForOrthoStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithSampaForOrthoStrs();
      } else if( strcmp( argv[1], "trimWhitespace") == 0 ) {
         allTestsPassed &= testTrimWhitespace();
      } else if( strcmp( argv[1], "getTotalFreqForPhrase") == 0 ) {
         allTestsPassed &= testGetTotalFreqForPhrase();
      } else if( strcmp( argv[1], "getCSVofWordFreqsForPhrase") == 0 ) {
         allTestsPassed &= test_getCSVofWordFreqsForPhrase();
      } else if( strcmp( argv[1], "getCSVofEachPhrasesWordsFreqs") == 0 ) {
         allTestsPassed &= test_getCSVofEachPhrasesWordsFreqs();
      } else if( strcmp( argv[1], "getCSVofAllPhraseFreqs") == 0 ) {
         allTestsPassed &= test_getCSVofAllPhraseFreqs();
      } else if( strcmp( argv[1], "generateStackedBarGraphOronymTree") == 0 ) {
         test_DrawStackedBar();
         allTestsPassed &= true;
      } else if( strcmp( argv[1], "drawRectangle") == 0 ) {
         test_DrawRect();
         allTestsPassed &= true;
      } else if( strcmp( argv[1], "getAllFirstWords") == 0 ) {
         allTestsPassed &= test_getAllFirstWords();
      } else if( strcmp( argv[1], "removeSuccessAndDeadendIndicatorsFromString") == 0 ) {
         allTestsPassed &= test_removeSuccessAndDeadendIndicatorsFromString( );
      } else if( strcmp( argv[1], "stripOronymOutputOfEndIndicators") == 0 ) {
         allTestsPassed &= test_stripOronymOutputOfEndIndicators( );
      } else if( strcmp( argv[1], "makeProtvisDiagram") == 0 ) {
         allTestsPassed &= test_makeProtvisDiagram( );
         
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
      } else if( strcmp( argv[1], "queryDBwithOrthoForSampaStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForSampaStrs( argv[2] );
      } else if( strcmp( argv[1], "queryDBwithOrthoForFreq") == 0 ) {
         allTestsPassed &= testQueryDBwithOrthoForFreq( argv[2] );
      } else if( strcmp( argv[1], "queryDBForOrthoStrsWithSampaPrefix") == 0 ) {
         allTestsPassed &= testQueryDBForOrthoStrsWithSampaPrefix( argv[2] );
      } else if( strcmp( argv[1], "queryDBwithSampaForOrthoStrs") == 0 ) {
         allTestsPassed &= testQueryDBwithSampaForOrthoStrs( argv[2] );
      } else if( strcmp( argv[1], "trimWhitespace") == 0 ) {
         allTestsPassed &= testTrimWhitespace( argv[2] );
      } else if( strcmp( argv[1], "getTotalFreqForPhrase") == 0 ) {
         allTestsPassed &= testGetTotalFreqForPhrase( argv[2] );
      } else if( strcmp( argv[1], "getCSVofWordFreqsForPhrase") == 0 ) {
         allTestsPassed &= test_getCSVofWordFreqsForPhrase( argv[2] );
      } else if( strcmp( argv[1], "getCSVofAllPhraseFreqs") == 0 ) {
         cerr << "Error: cannot pass test_getCSVofAllPhraseFreqs argument from command line"<<endl;
         usageMessage();
      } else if( strcmp( argv[1], "getCSVofEachPhrasesWordsFreqs") == 0 ) {
         cerr << "Error: cannot pass test_getCSVofEachPhrasesWordsFreqs argument from command line"<<endl;
         usageMessage();
      } else if( strcmp( argv[1], "generateStackedBarGraphOronymTree") == 0 ) {
         test_DrawStackedBar( argv[2] );
         allTestsPassed &= true;
      } else if( strcmp( argv[1], "drawRectangle") == 0 ) {
         test_DrawRect( atoi( argv[2] ) );
         allTestsPassed &= true;
      } else if( strcmp( argv[1], "getAllFirstWords") == 0 ) {
         allTestsPassed &= test_getAllFirstWords( argv[2] );
      } else if( strcmp( argv[1], "removeSuccessAndDeadendIndicatorsFromString") == 0 ) {
         allTestsPassed &= test_removeSuccessAndDeadendIndicatorsFromString( argv[2] );
      } else if( strcmp( argv[1], "stripOronymOutputOfEndIndicators") == 0 ) {
         allTestsPassed &= test_stripOronymOutputOfEndIndicators( argv[2] );
      } else if( strcmp( argv[1], "makeProtvisDiagram") == 0 ) {
         allTestsPassed &= test_makeProtvisDiagram( argv[2] );
         
      } else {
         cout << "!!-----Invalid usage-----!!\n";
         cout << "!!-----input: " << argv[0] <<" "<< argv[1]<<" "<<"-----!!\n";
         usageMessage();
      }
   }

   teardownTests();

}
