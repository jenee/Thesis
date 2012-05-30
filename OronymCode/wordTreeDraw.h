#ifndef WORD_TREE_DRAW_H
#define WORD_TREE_DRAW_H

#include <string>
#include <vector>
#include <set>
#include <assert.h>

#include "wordBreakdown.h"
#include "../LTreeLighting/main.h"

#define DEFAULT_RADIUS .25

int maxWordFreq = DICTIONARY_MIN_FREQ - 1;
int minWordFreq = DICTIONARY_MAX_FREQ + 1; 

const double minRadius = 0.05;
const double maxRadius = 1.0;


const double farLeftTiltAngle = -45.0;

const double defaultXOffset = .1;      
const double defaultYOffset = .1;        

double scaleFreqToRadius( int freqVal );

std::string FirstWord(const std::string& line);
void drawBranchesAtFork( std::vector< std::string > fullPhrases, double lastRadius );
void buildAndDrawFullTree( std::string orthoPhrase );
void buildAndDrawFullTree();

#endif
