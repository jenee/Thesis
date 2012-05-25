#ifndef TEST_WORD_BREAKDOWN_H
#define TEST_WORD_BREAKDOWN_H

#include "wordBreakdown.h"

void setupTests();
void teardownTests();
bool testDiscoverOronymsForPhrase(std::string orthoPhrase);
bool testDiscoverOronymsForPhrase();
bool testFindAllPhoneSeqsForOrthoPhrase( std::string orthoPhrase);
bool testFindAllPhoneSeqsForOrthoPhrase();
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
void oldMain();
bool runAllDefaultTests();
void usageMessage();

#endif