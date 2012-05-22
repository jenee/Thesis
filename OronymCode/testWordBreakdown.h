#ifndef TEST_WORD_BREAKDOWN_H
#define TEST_WORD_BREAKDOWN_H

#include "wordBreakdown.h"

void setupTests();
void teardownTests();
bool testFindAllPhoneSeqsForOrthoPhrase( std::string orthoPhrase);
bool testFindAllPhoneSeqsForOrthoPhrase();
bool testQueryDBwithOrthoForSampaStrs( std::string orthoWord);
bool testQueryDBwithOrthoForSampaStrs();
bool testStrTokOnWhitespace( std::string phrase );
bool testStrTokOnWhitespace();
int oldMain();
void usageMessage();

#endif