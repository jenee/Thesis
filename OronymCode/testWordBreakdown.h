#ifndef TEST_WORD_BREAKDOWN_H
#define TEST_WORD_BREAKDOWN_H

#include<stdlib.h> //for atoi in runAllDefaultTests

#include "wordBreakdown.h"
#include "2dStackedBarTreeViz.h"

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
bool testGetTotalFreqForPhrase( std::string orthoPhrase );
bool testGetTotalFreqForPhrase();
bool test_getCSVofWordFreqsForPhrase( std::string orthoPhrase );
bool test_getCSVofWordFreqsForPhrase();
bool test_getCSVofAllPhraseFreqs( std::vector<std::string> orthoPhrases );
bool test_getCSVofAllPhraseFreqs();
bool test_getCSVofEachPhrasesWordsFreqs( std::vector<std::string> orthoPhrases );
bool test_getCSVofEachPhrasesWordsFreqs();
void test_DrawRect();
void test_DrawRect( int width );
void test_DrawRect( int width, int height );
void test_DrawStackedBar();
void test_DrawStackedBar( std::string rootPhrase );
void test_DrawStackedBar( std::vector<std::string> phrases );
bool test_getAllFirstWords();
bool test_getAllFirstWords( std::string rootPhrase );
bool test_getAllFirstWords( std::vector<std::string> phrases );

std::vector<std::string> buildVectorOfStrings();
void oldMain();
bool runAllDefaultTests();
void usageMessage();

#endif