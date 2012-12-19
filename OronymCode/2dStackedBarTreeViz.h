#ifndef 2D_STACKED_BAR_TREE_VIZ_H
#define 2D_STACKED_BAR_TREE_VIZ_H

#include <stdlib.h>
#include <string>
#include <vector>

#include "wordBreakdown.h"

void generateStackedBarGraphOronymTree( std::vector <std::string> phrases );
void drawStackedBar( int width, std::vector <std::string> tailPhrases);
int drawBar(float width);
void translateYBy(int height);
void translateXBy(int width);
void drawRectangle(int width, int height);


#endif
