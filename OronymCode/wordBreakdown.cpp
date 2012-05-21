
#include "wordBreakdown.h"

using namespace std;


//GLOBALS for database access
sqlite3 *db;
vector< vector< string > > databaseResults;


static int callback(void *queryterm, int nCol, char **values, char **headers){
   int i;
   vector<string> rowEntry;
   //fprintf(stderr,"===Callback for %s===\n",(char *) queryterm);
   for(i=0; i< nCol; i++){
      //fprintf(stderr,"%s = %s\n", headers[i], values[i] ? values[i] : "NULL");
      rowEntry.push_back( values[i] );
   }
   //printf("\n");
   databaseResults.push_back(rowEntry);
   return 0;
}


int main() {
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


vector<string> findAllPermutations(string orthoPhrase) {
	vector<string> permutedPhrases;	
	
	vector<string> orthoWords = strTokOnWhitespace( orthoPhrase );
	vector< vector<phone> > sampaPhrases; 
   cerr << "FIND ALL PERMUTATIONS" << endl;
   for (int i = 0; i < orthoWords.size(); i++) {
      vector< vector<phone> > sampaSyllWords = getSampa( orthoWords[i] );
      for( int j = 0; j < sampaSyllWords.size(); j++ ) {
         /*
         //DEBUG
         cerr << j <<": ";
         for ( int k = 0; k < sampaSyllWords[j].size(); k++ ) {
            cerr<< "_" << sampaSyllWords[j][k] << "_";
         }
         cerr << endl; 
         //END DEBUG
         */  
         //if this is ths first orthoWord
         if( i == 0 ) {
            sampaPhrases.push_back( sampaSyllWords[j] );
         } else {
            int numFullPhrases = sampaPhrases.size();
            cerr << "\tnumFullPhrases = "<< numFullPhrases << endl;//TODO debug
            if ( sampaSyllWords.size() > 1 ) {
               cerr << "\tsampaSyllWords.size() = "<< sampaSyllWords.size() << endl;//TODO debug
               for(int m = 1; m < sampaSyllWords.size(); m++) {
                  //if there's more than one phonetic interpretation of the 
                  // ortho word to be added, then we need to create duplicates 
                  // of all existing sampaPhrase entries for each of them.
                  for( int n = 0; n < numFullPhrases; n++){
                     vector< phone > copyOfSampaPhraseN( sampaPhrases[n] ); 
                     sampaPhrases.push_back( copyOfSampaPhraseN );
                  }
               }
            }
            for( int m = 0; m < sampaPhrases.size(); m++){
               int phrsToAppendNdx = m / numFullPhrases;
               vector<phone> phraseToAppend( sampaSyllWords[phrsToAppendNdx] );
               sampaPhrases[m].insert( sampaPhrases[m].end(),
                                       phraseToAppend.begin(), 
                                       phraseToAppend.end() );
            }
                  //DEBUG
                  for ( int e = 0; e < sampaPhrases.size(); e++ ) {
                     cerr << e <<"***sampa phrase after append  ";
                     for ( int f = 0; f < sampaPhrases[e].size(); f++ ) {
                        cerr<< "_" << sampaPhrases[e][f] << "_";
                     }
                     cerr << endl; 
                  }
                  //END DEBUG
         }
         
         //DEBUG
         cerr << j <<"++SAMPA+PHRASES++  ";
         for ( int k = 0; k < sampaPhrases[j].size(); k++ ) {
            cerr<< "-" << sampaPhrases[j][k] << "-";
         }
         cerr << endl; 
         //END DEBUG
                //6vector<phone> sampaWord = sampaSyllWords[j];
         //sampaPhrase.insert( sampaPhrase.end(), sampaWord.begin(), sampaWord.end() );
      }
      
	}	
         assert(0);

   vector<string> misheard;
   for (int i = 0; i < sampaPhrases.size(); i++){
   	 //misheard.push_back( interpretPhrase( sampaPhrases[i] ) ) 
	}
	
	for (int i = 0; i < misheard.size(); i++) {
      string s = misheard[i];
      DDDDDDDDDDDEBUG(s);
	}	


	return misheard;

}

vector< vector<phone> > getSampa( string orthoWord ) {
   vector<string> sampaStrings = queryDBwithOrthoForSAMPA( orthoWord );
   vector< vector <phone> > sampaSyllPhrases;
   for(int i = 0; i < sampaStrings.size(); i++) {
      vector<phone> sampaSylls = parseSAMPAintoPhonemes( sampaStrings[i] );
      sampaSyllPhrases.push_back(sampaSylls);
    }
   return sampaSyllPhrases;
}


/* given ortho, returns SAMPAs */
vector<string> queryDBwithOrthoForSAMPA( string orthoWord ) {
   char* sqlQuery = (char*) malloc( sizeof(char*) * MAX_DATABASE_QUERY_LEN );
   char* zErr;
   
   fprintf(stderr, "\nqueryDBwithOrthoForSAMPA, orthoWord = %s\n", orthoWord.c_str());
   
   string lowercaseOrthoWord = toLowerCase( orthoWord );

   sprintf(sqlQuery, "select SAMPA from phoneticDictTable where lower(ortho) = \"%s\"",lowercaseOrthoWord.c_str()); 

   /*The following line calls the callback function, passing its 4th arg as the 
    first param of the callback function.  The sqlite3_exec function 
    queries the database, then for every result that it gets, it calls the 
    callback function.*/
   int rc = sqlite3_exec(db, sqlQuery, callback, (void*)orthoWord.c_str(), &zErr);
   if ( rc != SQLITE_OK ) {
      if ( zErr != NULL ) {
         fprintf(stderr, "SQL error: %s\n", zErr);
         sqlite3_free(zErr);
      }
   }
   //int SAMPAcolIndex = 3;
    
   vector<string> SAMPAvals;
   /*
   cerr << "Database results size = " << databaseResults.size() << endl;
   printDatabaseResultsRows(); //TODO  remove DEBUG
   */
   for( int i = 0; i < databaseResults.size(); i++) {
      SAMPAvals.push_back( delSpaces( databaseResults[i][0] ) );
      cerr << "!~" << SAMPAvals[i] << "!~" ; //TODO DEBUG output
   }
   cerr<< endl; //TODO DEBUG
   databaseResults.clear();
   /*
   cerr << "After clear, database results size = " << databaseResults.size() << endl;
   printDatabaseResultsRows(); //TODO  remove DEBUG
   */
   return SAMPAvals;
}  

/*This function does the phoneme-tree-traversal thing for oronyms
   returns orthographic phrases (I *think* each string is a full phrase...)*/
vector<string> interpretPhrase( vector<phone> sampaPhrase ) {
	vector<string> misheardOrthoPhrases;
  
   cerr << "INTERPRET PHRASE" << endl;
	if( sampaPhrase.size() == 0 ) {
		misheardOrthoPhrases.push_back("");
		return misheardOrthoPhrases;
	}
	
   string sampaStr = "";
	vector <phone> usedPhones;
   
   for (int i = 0; i < sampaPhrase.size(); i++) {
      phone p = sampaPhrase[i];
		sampaStr += p;
		usedPhones.push_back(p);
		vector<string> orthoMatches = dictLookup( sampaStr );
		if ( orthoMatches.size() == 0 ) {
			misheardOrthoPhrases.push_back("DEADBEEF");
			return misheardOrthoPhrases;
		}

      for (int i = 0; i < orthoMatches.size(); i++) {
         string orthoWord = orthoMatches[i];
			vector<phone> sampaPhraseTail( sampaPhrase.begin(), sampaPhrase.begin() + i );
			vector<string> orthoLeaves = interpretPhrase ( sampaPhraseTail );
			if ( orthoLeaves.size() == 0 ) {
				misheardOrthoPhrases.push_back( orthoWord.append( "DEADBEEF" ) );
				return misheardOrthoPhrases;
			} else {
                        
            for (int i = 0; i < orthoLeaves.size(); i++) {
               string orthoLeaf = orthoLeaves[i];
					misheardOrthoPhrases.push_back( orthoWord + orthoLeaf );
				}
            
			}
		}
	}
	return misheardOrthoPhrases;
}


vector<string> dictLookup( string sampaStr ) {
   vector<string> orthoMatches;
   vector<phone> sampaSylls = parseSAMPAintoPhonemes(sampaStr);
   assert(0); // PUT SQL QUERY HERE
   
   return orthoMatches;
}


/* given ortho, returns entire row to databaseResults */
void queryDBwithOrthoForRow( string orthoWord ) {
   char* sqlQuery = (char*) malloc( sizeof(char*) * MAX_DATABASE_QUERY_LEN );
   char* zErr;
   
   fprintf(stderr, "queryDBwithOrthoForSAMPA, orthoWord = %s\n", orthoWord.c_str());
   
   string lowercaseOrthoWord = toLowerCase( orthoWord );

   sprintf(sqlQuery, "select * from phoneticDictTable where lower(ortho) = \"%s\"",lowercaseOrthoWord.c_str()); 

   int rc = sqlite3_exec(db, sqlQuery, callback, (void*)orthoWord.c_str(), &zErr);
   if ( rc != SQLITE_OK ) {
      if ( zErr != NULL ) {
         fprintf(stderr, "SQL error: %s\n", zErr);
         sqlite3_free(zErr);
      }
   }
}  
 

vector<phone> parseSAMPAintoPhonemes( string sampaString ) {
   vector<phone> sampaSylls = splitSampaIntoLetters(sampaString);
   return sampaSylls;
}


vector<string> splitSampaIntoLetters(string phrase) {
   vector<string> tokens;
   string sampaCharacter;
   
   for (size_t i=0; i < phrase.length(); i++) {
      // We're not at the last character
      if (i+1 < phrase.length()) {
         // Get a two-character set.
       sampaCharacter = phrase.substr(i, 2);
       if (sampaCharacter == "@`"
             || sampaCharacter == "`r"
             || sampaCharacter == "3`"
             || sampaCharacter == "A`"
             || sampaCharacter == "aI"
             || sampaCharacter == "aU"
             || sampaCharacter == "dZ"
             || sampaCharacter == "E`"
             || sampaCharacter == "I`"
             || sampaCharacter == "jU"
             || sampaCharacter == "ju"
             || sampaCharacter == "l="
             || sampaCharacter == "m="
             || sampaCharacter == "n="
             || sampaCharacter == "O`"
             || sampaCharacter == "OI"
             || sampaCharacter == "oU"
             || sampaCharacter == "ou"
             || sampaCharacter == "tS"
             || sampaCharacter == "U`") {
          // We're good.  Skip the second character for purpose of the loop.
          i++;
         } else {
            sampaCharacter = phrase.at(i);
         }
      } else {
         sampaCharacter = phrase.at(i);
      }
      tokens.push_back(sampaCharacter);
   }
   return tokens;
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


void printDatabaseResultsRows() {
   for(int row = 0; row < databaseResults.size(); row++) {
      cerr << "ROW "<<row <<": ";
      for(int col = 0; col < databaseResults[row].size(); col++) {
         cerr << databaseResults[row][col] <<" | ";
      }
      cerr << endl;
   }
}


//http://www.daniweb.com/software-development/cpp/threads/27905
vector<string> strTokOnWhitespace(string phrase) {
   string temp;
   stringstream ss(phrase);
   vector<string> tokens;
   
   //while (phrase >> temp) {
   while ( getline(ss, temp, ' ') ) {
      tokens.push_back( delSpaces(temp) );
   }
   return tokens;
}

//From http://stackoverflow.com/a/8868204
string delSpaces(string &str) 
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

string toLowerCase( string data) {
   std::transform(data.begin(), data.end(), data.begin(), ::tolower);
   return data;
}

void DDDDDDDDDDDEBUG(string s) {
	cerr << s << endl;	
}
  

void cleanupDatabase() {
   sqlite3_close(db);
}
/*
vector<string>  getPhrasePhonemes(string phrase) {
	vector<string> phrasePhones;;
	vector<string> words = split(/\s/); //split on any whitespace character

	for ( string s : words) {
		vector<string> sampleSylls = getSAMPAForPhrase(s);
		//append to end
		phrasePhones.insert( phrasePhones.end(), 
			sampaSylls.begin(), sampaSylls.end() );			
	}
	return phrasePhones;
}
string[] getSAMPAForPhrase(string orthoWord) {
	//lookup in dictionary
	split sampa phrase
	$src_SAMPA =~ s/\s$//; #remove trailing whitespace;
	$src_SAMPA =~ s#^\s*##; # remove leading whitespace.
	
	print OUTFILE "$src_SAMPA\t";
	print OUTFILE ":\t";
	print "$src_SAMPA\t";

	@array_src_SAMPA = split (/[\$|%|\"]/, $src_SAMPA);
	
	//return split sampa phrase
}


vector<PhoneWithIndex> embedPhoneOrder(vector<string> phones) {
	vector<PhoneWithIndex> toRet;
	int i = 0;
	for( string s : phones) {
		toRet.add( LocPhone(i++, s) );  
	}
	return toRet;
}
*/

