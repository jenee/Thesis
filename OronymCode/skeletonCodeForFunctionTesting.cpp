// Testing code skeleton
// REPLACE "nameOfFuncToTest" with your function name
// put results in the testWordBreakdown files (h and cpp)
//vector<string> nameOfFuncToTest ( vector<string> phrases ) {

//put in testWordBreakdown.h file
bool test_nameOfFuncToTest();
bool test_nameOfFuncToTest( std::string rootPhrase);
bool test_nameOfFuncToTest( std::vector<std::string> test);


// put in testWordBreakdown.cpp file

bool test_nameOfFuncToTest() {

   bool retVal = true;
   
   vector<string> testPhrases;
   testPhrases.push_back("dead end indic x's xxx");   
   testPhrases.push_back("dead end indic f's fff");
   testPhrases.push_back("success indic ___SUCCESS!___");
   
   retVal &= test_nameOfFuncToTest( testPhrases );
   return retVal;
}

bool test_nameOfFuncToTest( string rootPhrase ) {

   bool retVal = true;
   
   vector<string> testPhrases = discoverOronymsForPhrase( rootPhrase );

   retVal &= test_nameOfFuncToTest( testPhrases );
   
   return retVal;
}

bool test_nameOfFuncToTest( vector<string> testPhrases ) {
   cout <<"TEST nameOfFuncToTest, testPhrases.size() ="<< testPhrases.size()<<endl;

   bool retVal = true;
   string deadEndIndic1 = "xxx";
   string deadEndIndic2 = "fff";
   string successIndic = "___SUCCESS!___";
   
   vector<string> newStrings = nameOfFuncToTest(testPhrases);
   
   for(int i = 0; i < testPhrases.size(); i++) {
      string newStr = newStrings[i];
      cout << "\'"<<testPhrases[i]<<"\' ---> \'"<<newStr<<"\'"<<endl;
      if( string::npos ==  newStr.find( deadEndIndic1 ) || 
          string::npos ==  newStr.find( deadEndIndic2 ) ||
            string::npos ==  newStr.find( successIndic ) ) {
         retVal &= true;
      } else {
         cout << "<>FAILED nameOfFuncToTest, newStr = "<<newStr <<endl;
         retVal &= false;
      }
   }
   return retVal;
}


//in runAllDefaultTests
   cout<< endl<<endl<< "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
   testsPassed &= test_nameOfFuncToTest();
  
  
//in usageMessage  
   cout << "\n\t\t nameOfFuncToTest";



//in main
   //first if!
      } else if( strcmp( argv[1], "nameOfFuncToTest") == 0 ) {
         allTestsPassed &= test_nameOfFuncToTest( );
  
  
  //second if!
  
      } else if( strcmp( argv[1], "nameOfFuncToTest") == 0 ) {
         allTestsPassed &= test_nameOfFuncToTest( argv[2] );