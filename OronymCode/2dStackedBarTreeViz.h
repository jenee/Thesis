#ifndef TWO_D_STACKED_BAR_TREE_VIZ_H
#define TWO_D_STACKED_BAR_TREE_VIZ_H

#include <stdlib.h>
#include <string>
#include <vector>

#include "wordBreakdown.h"

int getValueForWord( std::string word );
void generateStackedBarGraphOronymTree( std::vector <std::string> phrases );
void drawStackedBar( int width, std::vector <std::string> tailPhrases);
std::string removeSuccessAndDeadendIndicatorsFromString( std::string orig );
std::vector <std::string> stripOronymOutputOfEndIndicators ( std::vector <std::string>  origPhrases ) ;
void makeProtvisDiagram (std::vector <std::string>  phrases );
void writeProtovisDataLevel( std::vector <std::string> tailPhrases, int curMultiplicativeVal, int numTabs );

int drawBar(float width);
void translateYBy(int height);
void translateXBy(int width);
void drawRectangle(int width, int height);


#endif
