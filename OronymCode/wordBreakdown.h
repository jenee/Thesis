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

std::vector< std::vector<phone> > getPhoneSeqsForSampaStrs( std::vector<std::string> sampaWords );
std::vector< std::vector<phone> > getPhoneSeqsForOrthoWord( std::string orthoWord );
std::vector< std::vector<phone> > findAllPhoneSeqsForOrthoPhrase( std::string orthoPhrase );

std::vector<std::string>  discoverOronymsForPhrase( std::string origOrthoPhrase );
std::vector<std::string> interpretPhrase( std::vector<phone> sampaPhrase );
/*
std::vector< std::vector<std::string>  > findAllValidOrthoPhrasesForPhoneSeqs ( std::vector< std::vector<phone> > fullPhoneSeqs ) {
std::vector< std::string > findValidOrthoWordForSinglePhoneSeq( std::vector<phone> );
*/
std::vector<std::string> queryDBforStrings( char* sqlQuery, std::string queryCallback4thArg );
std::vector<std::string> queryDBwithOrthoForSampaStrs( std::string orthoWord );
std::vector<std::string> queryDBForOrthoStrsWithSampaPrefix( std::string  sampaPrefix );
std::vector<std::string> queryDBwithSampaForOrthoStrs( std::string sampaStr );
void queryDBwithOrthoForRow( std::string orthoWord );

std::vector<phone> parseSAMPAintoPhonemes( std::string sampaStr );
std::vector<std::string> splitSampaIntoLetters(std::string phrase);

std::vector<std::string> strTokOnWhitespace(std::string phrase);
std::string toLowerCase( std::string data);
std::string delSpaces( std::string &str);
std::string stripSampaStrOfEmph( std::string &str);

std::vector< phone > getNoEmphsPhoneVect(std::vector< phone > phoneVectOrig );
std::string phoneVectToString( std::vector< phone > phoneVect );

void printDatabaseResultsRows();
void DDDDDDDDDDDEBUG(std::string s);

void connectToPhoneticDictionaryDatabase(std::string databaseFilename);
void cleanupDatabase();

#endif

