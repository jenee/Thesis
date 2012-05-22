#ifndef WORD_BREAKDOWN_H
#define WORD_BREAKDOWN_H

#include <algorithm> //for toLower's transform statement
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>

#include <sqlite3.h>
//#include "SQLite/sqlite-amalgamation-3071000/sqlite3.h"


#define MAX_DATABASE_FILE_PATH_LEN 1024
#define MAX_DATABASE_QUERY_LEN 1024

typedef std::string phone;

static int callback(void *queryterm, int nCol, char **values, char **headers);


std::vector<std::string> findAllPermutations(std::string orthoPhrase);
std::vector< std::vector<phone> > getSampa( std::string orthoWord );
std::vector<std::string> queryDBwithOrthoForSAMPA( std::string orthoWord );
std::vector<std::string> interpretPhrase( std::vector<phone> sampaPhrase );
std::vector<std::string> dictLookup( std::string sampaStr );
void queryDBwithOrthoForRow( std::string orthoWord );
std::vector<phone> parseSAMPAintoPhonemes( std::string sampaStr );
std::vector<std::string> splitSampaIntoLetters(std::string phrase);

void connectToPhoneticDictionaryDatabase(std::string databaseFilename);
std::string phoneVectToString( std::vector< phone > phoneVect );
void printDatabaseResultsRows();
std::vector<std::string> strTokOnWhitespace(std::string phrase);
std::string delSpaces( std::string &str);
std::string toLowerCase( std::string data);
void DDDDDDDDDDDEBUG(std::string s);
void cleanupDatabase();

#endif

