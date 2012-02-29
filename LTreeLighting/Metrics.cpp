//
//  Metrics.cpp
//  LTreeLighting
//
//  Created by Jenee Hughes on 2/29/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Metrics.h"

using namespace std;


vector<clarityVal> measureClarity( vector<lyricWord> lyrics ){
   vector<clarityVal> toReturn;
   toReturn.push_back(1);
   toReturn.push_back(3);
   toReturn.push_back(2);
   toReturn.push_back(1);
   toReturn.push_back(6);
   toReturn.push_back(4);
   return toReturn;
}