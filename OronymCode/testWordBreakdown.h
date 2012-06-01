#ifndef TEST_WORD_BREAKDOWN_H
#define TEST_WORD_BREAKDOWN_H

#include "wordBreakdown.h"

void setupTests();
void teardownTests();
bool testDiscoverOronymsForPhrase(std::string orthoPhrase);
bool testDiscoverOronymsForPhrase();
bool testFindAllPhoneSeqsForOrthoPhrase( std::string orthoPhrase);
bool testFindAllPhoneSeqsForOrthoPhrase();
bool testFindPhoneTreeForOrthoPhrase( std::string orthoPhrase );
bool testFindPhoneTreeForOrthoPhrase();
bool testQueryDBwithSampaForOrthoStrs( std::string sampaStr );
bool testQueryDBwithSampaForOrthoStrs();
bool testQueryDBForOrthoStrsWithSampaPrefix( std::string sampaPrefix );
bool testQueryDBForOrthoStrsWithSampaPrefix();
bool testQueryDBwithOrthoForSampaStrs( std::string orthoWord);
bool testQueryDBwithOrthoForSampaStrs();
bool testQueryDBwithOrthoForFreq( std::string orthoWord);
bool testQueryDBwithOrthoForFreq();
bool testStrTokOnWhitespace( std::string phrase );
bool testStrTokOnWhitespace();
bool testStripSampaStrOfEmph( std::string sampaStr );
bool testStripSampaStrOfEmph();
bool testGetSampaStrWithoutGlottalStops( std::string sampaStr );
bool testGetSampaStrWithoutGlottalStops();
bool testGetSampaStrWithoutContiguousDuplicatePhones( std::string sampaStr );
bool testGetSampaStrWithoutContiguousDuplicatePhones();
bool testTrimWhitespace( std::string str );
bool testTrimWhitespace ();
void oldMain();
bool runAllDefaultTests();
void usageMessage();

#endif