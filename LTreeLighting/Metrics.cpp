//
//  Metrics.cpp
//  LTreeLighting
//
//  Created by Jenee Hughes on 2/29/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector.h>
using namespace std;

typedef string lyricWord;
typedef  int clarityVal; //the larger the val, the more unclear


vector<clarityVal> measureClarity( vector<lyricWord> lyrics);

vector<clarityVal> measureClarity( vector<lyricWord> lyrics){
   vector<clarityVal> toReturn;
   toReturn.push_back(1);
   toReturn.push_back(3);
   toReturn.push_back(9);
   toReturn.push_back(1);
   toReturn.push_back(10);
   toReturn.push_back(4);

}