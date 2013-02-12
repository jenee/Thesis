/*DB-agnostic freq lookup*/


//GLOBALS for database access
sqlite3 *db;
vector< vector< string > > databaseResults;




static int callback(void *queryterm, int nCol, char **values, char **headers){
   int i;
   vector<string> rowEntry;
   //fprintf(stderr,"===Callback for query %s===\n",(char *) queryterm);
   for(i=0; i< nCol; i++){
      //fprintf(stderr,"%s = %s\n", headers[i], values[i] ? values[i] : "NULL");
      rowEntry.push_back( values[i] );
   }
   //printf("\n");
   databaseResults.push_back(rowEntry);
   return 0;
}

bool confirmDatabaseInitialization() {
   bool allValsInitialized = true;
   if(db == NULL ) {
      connectToPhoneticDictionaryDatabase("/Users/admin/Documents/Thesis/SQLiteDatabases/phoneticDict");
   }
   allValsInitialized &= (db != NULL);
}


/* given ortho, returns freq val */
int queryDBwithOrthoForFreq( string orthoWord ) {
   confirmDatabaseInitialization();
   char* sqlQuery = (char*) malloc( sizeof(char*) * MAX_DATABASE_QUERY_LEN );
   
   //fprintf(stderr, "\queryDBwithOrthoForFreq, orthoWord = %s\n", orthoWord.c_str());
   
   string lowercaseOrthoWord = toLowerCase( orthoWord );

   sprintf(sqlQuery, "select freq from phoneticDictTable where lower(ortho) = \"%s\"",lowercaseOrthoWord.c_str()); 
   
   vector<string> SAMPAvals = queryDBforStrings( sqlQuery, lowercaseOrthoWord );
   int result = 0;

   if( SAMPAvals.size() > 0 ) {
      stringstream( SAMPAvals.at(0) ) >> result;
   }
/*
   //The following line calls the callback function, passing its 4th arg as the 
    //first param of the callback function.  The sqlite3_exec function 
    //queries the database, then for every result that it gets, it calls the 
    //callback function.
   int rc = sqlite3_exec(db, sqlQuery, callback, (void*)orthoWord.c_str(), &zErr);
   if ( rc != SQLITE_OK ) {
      if ( zErr != NULL ) {
         fprintf(stderr, "SQL error: %s\n", zErr);
         sqlite3_free(zErr);
      }
   }
   //int SAMPAcolIndex = 3;
    
   vector<string> SAMPAvals;
   ///
   //cerr << "Database results size = " << databaseResults.size() << endl;
   //printDatabaseResultsRows(); //TODO  remove DEBUG
   //
   for( int i = 0; i < databaseResults.size(); i++) {
      SAMPAvals.push_back( delSpaces( databaseResults[i][0] ) );
      cerr << "!~" << SAMPAvals[i] << "!~" ; //TODO DEBUG output
   }
   cerr<< endl; //TODO DEBUG
   databaseResults.clear();
   //
   //cerr << "After clear, database results size = " << databaseResults.size() << endl;
   //printDatabaseResultsRows(); //TODO  remove DEBUG
   //
   */
   return result;
}


int getTotalFreqForPhrase( string orthoPhrase ) {
   
   int freqSum = 0;
   
   vector<string> phraseWords = strTokOnWhitespace( orthoPhrase );
   
   //cerr << "--numPhraseWords = "<< phraseWords.size() <<endl;
   
   for(  int i = 0; i < phraseWords.size(); i++ ) {
      //cerr << "--["<<i<<"]:"<< phraseWords.at(i) <<endl;
      freqSum += queryDBwithOrthoForFreq( phraseWords.at(i) );
      
   }
   
   //assert(0);

   return freqSum;
}

string getCSVofWordFreqsForPhrase (string orthoPhrase ) {
   string csvLine = orthoPhrase;
   string delim = " , ";

   csvLine.append( delim );
   
   vector<string> phraseWords = strTokOnWhitespace( orthoPhrase );
   
   for(  int i = 0; i < phraseWords.size(); i++ ) {
      csvLine.append( phraseWords.at(i) );
      csvLine.append( delim );
      stringstream os;
      os << queryDBwithOrthoForFreq( phraseWords.at(i) );
      string freq_str = os.str(); //retrieve as a string
      csvLine.append( freq_str );
      csvLine.append( delim );

   }
   return csvLine;
   
}

vector<string> getCSVofAllPhraseFreqs( vector<string> orthoPhrases ) {

   vector<string> csvStrings;
   string delim = " , ";
   for (int i = 0; i < orthoPhrases.size(); i++) {
      cerr<<"."<<i;
      string csvLine = trimWhitespace( orthoPhrases.at( i ) );
      //cerr<<csvLine <<endl;
      int totalFreq = getTotalFreqForPhrase( csvLine );
      //cerr<<totalFreq <<endl;

      csvLine.append( delim );
      stringstream os;
      os << totalFreq;
      string freq_str = os.str(); //retrieve as a string
      csvLine.append( freq_str );
      csvStrings.push_back( csvLine );
   }
   cerr<<endl;
   return csvStrings;
}

vector< string > getCSVofEachPhrasesWordsFreqs( vector< string > orthoPhrases ) {
   vector<string> csvStrings;   
   for (int i = 0; i < orthoPhrases.size(); i++) {
      csvStrings.push_back( getCSVofWordFreqsForPhrase ( orthoPhrases.at(i) ) );
   }
   return csvStrings;
}

void printDatabaseResultsRows() {
   for(int row = 0; row < databaseResults.size(); row++) {
      cerr << "ROW "<<row <<": ";
      for(int col = 0; col < databaseResults[row].size(); col++) {
         cerr << databaseResults[row][col] <<" | ";
      }
      cerr << endl;
   }
}

void DDDDDDDDDDDEBUG(string s) {
	cerr << s << endl;	
}
  
void connectToPhoneticDictionaryDatabase(string databaseFilename) {
   int rc;
   
   char* databaseName = (char*) malloc( sizeof(char*) * MAX_DATABASE_FILE_PATH_LEN );
   
   if( databaseFilename.empty() ) {
      databaseName = "/Users/admin/Documents/Thesis/SQLiteDatabases/phoneticDict";
   } else {
      sprintf(databaseName, "%s", databaseFilename.c_str());
   }

   rc = sqlite3_open(databaseName, &db);
   if( rc ) {
      fprintf( stderr, "Can't open database %s: %s\n", databaseName, sqlite3_errmsg( db ) );
      sqlite3_close( db );
      exit ( -1 );
   } else {
      
      cerr << "DATABASE SUCCESSFULLY OPENED" << endl;
      //DDDDDDDDDDDEBUG("DATABASE SUCCESSFULLY OPENED");
   }
}

void cleanupDatabase() {
   confirmDatabaseInitialization();
   sqlite3_close(db);
}