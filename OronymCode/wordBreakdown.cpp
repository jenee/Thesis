#include <algorithm> //for toLower's transform statement
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>

#include <sqlite3.h>
//#include "SQLite/sqlite-amalgamation-3071000/sqlite3.h"

using namespace std;


#define MAX_DATABASE_FILE_PATH_LEN 1024
#define MAX_DATABASE_QUERY_LEN 1024

typedef string phone ;


vector<string> findAllPermutations(string orthoPhrase);
void DDDDDDDDDDDEBUG(string s);
void cleanupDatabase();
void connectToPhoneticDictionaryDatabase(string databaseFilename);
vector<string> strTokOnWhitespace(string phrase);
vector<string> interpretPhrase( vector<phone> sampaPhrase );
vector<phone> getSampa( string orthoWord );
string queryDBforSAMPA( string orthoWord );
vector<phone> parseSAMPAintoPhonemes( string sampaString );
vector<string> dictLookup( string sampaStr ); 
vector<string> splitSampaIntoLetters( string phrase );


//GLOBALS for database access
sqlite3 *db;
vector< vector< string > > databaseResults;


static int callback(void *queryterm, int nCol, char **values, char **headers){
   int i;
   vector<string> rowEntry;
   fprintf(stderr,"===Callback for %s===\n",(char *) queryterm);
   for(i=0; i< nCol; i++){
      fprintf(stderr, "%s = %s\n", headers[i], values[i] ? values[i] : "NULL");
      rowEntry.push_back( values[i] );
   }
   printf("\n");
   databaseResults.push_back(rowEntry);
   return 0;
}


int main() {
   connectToPhoneticDictionaryDatabase("/Users/admin/Documents/Thesis/SQLiteDatabases/phoneticDict");

   //TODO Do stuff!
   //fprintf(stderr, "gets here, 0\n");
   string phrase = "A nice cold shower";
   //fprintf(stderr, "gets here, phrase = %s\n", phrase.c_str());
   vector<string> phraseWords = strTokOnWhitespace( phrase );
   //fprintf(stderr, "gets here, phrase = %s\n", phrase.c_str());
   //TODO remove: loop is for debugging
   for( int i = 0; i < phraseWords.size(); i++) {
      string w = phraseWords[i];
      cout << w << "|";
   }
   cout <<endl;
   
   for( int i = 0; i < phraseWords.size(); i++) {
      string w = phraseWords[i];
      cout <<"~~~~~~~~~~"<<w<<"~~~~~~~~~~"<< queryDBforSAMPA( w ) <<"~~~~~~~~"<<w<<" end~~~~~~~~~~~~"; 
   }
   cout <<endl;



   vector<string> orthoPhrases = findAllPermutations( phrase );
   
   for( int i = 0; i < orthoPhrases.size(); i++) {
      string p = orthoPhrases[i];
      cout <<"---"<< p << endl;
   }
   cout <<endl;


  cleanupDatabase();
}


vector<string> findAllPermutations(string orthoPhrase) {
	vector<string> permutedPhrases;	
	
	vector<string> orthoWords = strTokOnWhitespace( orthoPhrase );
	vector<phone> sampaPhrase;

   for (int i = 0; i < orthoWords.size(); i++) {
      string orthoWord = orthoWords[i];
		vector<phone> sampaWord = getSampa( orthoWord );
		sampaPhrase.insert( sampaPhrase.end(), sampaWord.begin(), sampaWord.end() );
	}	

	vector<string> misheard = interpretPhrase( sampaPhrase );
	
	for (int i = 0; i < misheard.size(); i++) {
      string s = misheard[i];
      DDDDDDDDDDDEBUG(s);
	}	


	return misheard;

}
	
void DDDDDDDDDDDEBUG(string s) {
	cout << s << endl;	
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
   sqlite3_close(db);
}

//http://www.daniweb.com/software-development/cpp/threads/27905
vector<string> strTokOnWhitespace(string phrase) {
   string temp;
   stringstream ss(phrase);
   vector<string> tokens;
   
   //while (phrase >> temp) {
   while ( getline(ss, temp, ' ') ) {
      tokens.push_back(temp);
   }
   return tokens;
}

vector<phone> getSampa( string orthoWord ) {
   string sampaString = queryDBforSAMPA( orthoWord );
   vector<phone> sampaWord = parseSAMPAintoPhonemes( sampaString );
   return sampaWord;
}

vector<string> dictLookup( string sampaStr ) {
   vector<string> orthoMatches;
   vector<phone> sampaSylls = parseSAMPAintoPhonemes(sampaStr);
   assert(0); // PUT SQL QUERY HERE
   
   return orthoMatches;
}

string toLowerCase( string data) {
   std::transform(data.begin(), data.end(), data.begin(), ::tolower);
   return data;
}


/* given ortho, returns SAMPA */
string queryDBforSAMPA( string orthoWord ) {
   //assert(0); // PUT SQL QUERY HERE
   char* sqlQuery = (char*) malloc( sizeof(char*) * MAX_DATABASE_QUERY_LEN );
   char* zErr;
   fprintf(stderr, "queryDBforSAMPA, orthoWord = %s\n", orthoWord.c_str());
   string lowercaseOrthoWord = toLowerCase( orthoWord );
   //sprintf(sqlQuery, "select * from phoneticDictTable where ortho = \\\"%s\\\"",orthoWord.c_str()); 
   sprintf(sqlQuery, "select * from phoneticDictTable where lower(ortho) = \"%s\"",lowercaseOrthoWord.c_str()); 
   int rc = sqlite3_exec(db, sqlQuery, callback, (void*)orthoWord.c_str(), &zErr);
   if ( rc != SQLITE_OK ) {
      if ( zErr != NULL ) {
         fprintf(stderr, "SQL error: %s\n", zErr);
         sqlite3_free(zErr);
      }
   }
   
   //TODO Remove: this is debug output

   for(int row = 0; row < databaseResults.size(); row++) {
      cout << "ROW "<<row <<": ";
      for(int col = 0; col < databaseResults[row].size(); col++) {
         cout << databaseResults[row][col] <<" | ";
      }
      cout << endl;
   }

   return "";
}

vector<phone> parseSAMPAintoPhonemes( string sampaString ) {
   vector<phone> sampaSylls = splitSampaIntoLetters(sampaString);
   return sampaSylls;
}

/*This function does the phoneme-tree-traversal thing for oronyms
   returns orthographic phrases (I *think* each string is a full phrase...)*/
vector<string> interpretPhrase( vector<phone> sampaPhrase ) {
	vector<string> misheardOrthoPhrases;
   
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

