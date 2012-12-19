#ifndef WORD_BREAKDOWN_H
#define WORD_BREAKDOWN_H

#include <algorithm> //for toLower's transform statement
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <assert.h>

#include <sqlite3.h>
//#include "SQLite/sqlite-amalgamation-3071000/sqlite3.h"


#define MAX_DATABASE_FILE_PATH_LEN 1024
#define MAX_DATABASE_QUERY_LEN 1024




//GLOBALS for phraseParsing
typedef std::string phone;
#define DICTIONARY_MAX_FREQ 16006650 // the frequency of "the" 
#define DICTIONARY_MIN_FREQ 0 
#define deadEndDelim1 "xxx" //formerly "DEADBEEF"
#define deadEndDelim2 "fff" //formerly "DEADerBEEF"
#define successDelim "___SUCCESS!___"

typedef struct MetaWord {
   std::string word;
   int freq;
} MetaWord;

static int callback(void *queryterm, int nCol, char **values, char **headers);

bool confirmInitVals();

std::vector< std::vector<phone> > getPhoneSeqsForSampaStrs( std::vector<std::string> sampaWords );
std::vector< std::vector<phone> > getPhoneSeqsForOrthoWord( std::string orthoWord );
std::vector< std::vector<phone> > findAllPhoneSeqsForOrthoPhrase( std::string orthoPhrase );
std::vector< std::set<phone> > findPhoneTreeForOrthoPhrase( std::string orthoPhrase );
 
std::vector<std::string>  discoverOronymsForPhrase( std::string origOrthoPhrase, bool includeDeadends );
std::vector<std::string>  discoverOronymsForPhrase( std::string origOrthoPhrase );
std::vector<std::string> interpretPhrase( std::vector<phone> sampaPhrase );
std::vector<std::string> findOrthoStrsForPhoneSeq( std::vector<phone> phoneSeq );


std::vector<std::string> queryDBforStrings( char* sqlQuery, std::string queryCallback4thArg );
int queryDBwithOrthoForFreq( std::string orthoWord );
std::vector<std::string> queryDBwithOrthoForSampaStrs( std::string orthoWord );
std::vector<std::string> queryDBForOrthoStrsWithSampaPrefix( std::string  sampaPrefix );
std::vector<std::string> queryDBwithSampaForOrthoStrs( std::string sampaStr );
void queryDBwithOrthoForRow( std::string orthoWord );

std::vector<phone> parseSAMPAintoPhonemes( std::string sampaStr );
std::vector<std::string> splitSampaIntoLetters(std::string phrase);

std::string FirstWord(const std::string& line);
std::vector< std::string > getAllFirstWords( std::vector< std::string > origPhrases );
std::vector<std::string> getAllOrthoTailPhrasesOf( std::string prefix, std::vector<std::string> fullPhrases);
std::vector<std::string> strTokOnWhitespace(std::string phrase );
std::string toLowerCase( std::string data );

std::string delSpaces( std::string &str );
std::string trimWhitespace( std::string &str );

void getMaxAndMinFreqForAllOrthoPhrases( std::vector< std::string > fullPhrases, int* max, int* max );
int getTotalFreqForPhrase( std::string orthoPhrase );
std::string getCSVofWordFreqsForPhrase ( std::string orthoPhrase );
std::vector< std::string > getCSVofAllPhraseFreqs( std::vector< std::string > orthoPhrases );
std::vector< std::string > getCSVofEachPhrasesWordsFreqs( std::vector< std::string > orthoPhrases );

std::string stripSampaStrOfEmph( std::string &str);
std::vector< phone > getNoEmphsPhoneVect(std::vector< phone > phoneVectOrig );
std::vector< std::string > getVoicingVariationsOfSampaStr ( std::string sampaStr );
std::vector< std::vector< phone > > getVoicingVariationsOfPhoneVect ( std::vector< phone >  phoneVectOrig );
std::string getSampaStrWithoutGlottalStops ( std::string sampaStr );
std::vector< phone > getNoGlottalStopsPhoneVect( std::vector< phone > phoneVectOrig );
std::string getSampaStrWithoutContiguousDuplicatePhones ( std::string sampaStr );
std::vector< phone > getNoContigDupesPhoneVect( std::vector< phone > phoneVectOrig );

bool isVowel( phone p );
bool isVoiced( phone p );
bool isVoiceless( phone p );
phone getPhoneWithInverseVoicing( phone p );

std::string phoneVectToString( std::vector< phone > phoneVect );

void printDatabaseResultsRows();
void DDDDDDDDDDDEBUG(std::string s);

void connectToPhoneticDictionaryDatabase(std::string databaseFilename);
void cleanupDatabase();

#endif

