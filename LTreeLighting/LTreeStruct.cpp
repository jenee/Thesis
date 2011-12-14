//
//  LTreeStruct.cpp
//  LTreeLighting
//
//  Created by Jenee Hughes on 11/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


struct LTreeBranch
{
    string id;
    LTreeBranch* parent;
    LTreeBranch** children;
    
    
    
};