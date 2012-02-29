//
//  Metrics.h
//  LTreeLighting
//
//  Created by Jenee Hughes on 2/29/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LTreeLighting_Metrics_h
#define LTreeLighting_Metrics_h

#include <iostream>
#include <vector.h>

typedef std::string lyricWord;
typedef int clarityVal; //the larger the val, the more unclear


std::vector<clarityVal> measureClarity( std::vector<lyricWord> lyrics);



#endif
