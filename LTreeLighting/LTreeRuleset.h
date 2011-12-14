//
//  LTreeRuleset.h
//  LTreeLighting
//
//  Created by Jenee Hughes on 11/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LTreeLighting_LTreeRuleset_h
#define LTreeLighting_LTreeRuleset_h

#include <string.h>
#include <vector>

using namespace std;

typedef int newthingyForInt;

struct TransformRule {
    int origPattern;
    int xformedPattern;
};

struct LTreeRuleset {
public:
    
    LTreeRuleset();
    LTreeRuleset(int seedParam);
    LTreeRuleset(int seedParam, int iterationsParam);
    
private:
    int seed;
    int numIterations;
    vector<TransformRule> ruleslist;
    vector<int> fullTreeString;
    
//TODO: I want to do this with strings!  
    
};




#endif
