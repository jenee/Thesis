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
bool testQueryDBwithOrthoForSampaStrs( std::string orthoWord);
bool testQueryDBwithOrthoForSampaStrs();
bool testStrTokOnWhitespace( std::string phrase );
bool testStrTokOnWhitespace();
bool testStripSampaStrOfEmph( std::string sampaStr ) ;
bool testStripSampaStrOfEmph();
void oldMain();
bool runAllDefaultTests();
void usageMessage();

#endif