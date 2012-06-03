#ifndef MAIN_H
#define MAIN_H

//A very simple opengl/GLUT program
/**
 * OS specific from COS 426 code to allow reading binary images from stdin
 **/
#ifdef __unix__
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <glut.h>
#endif

//Example program of simple lighting with two different materials on a 3D cube
//by ZJ Wood for CSC471
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string>
#include <vector>
#include <set>
#include <sstream>

#include <limits.h>

#include "Metrics.h"
#include "../OronymCode/wordBreakdown.h"


#define DEFAULT_RADIUS .25
#define DEFAULT_BRANCH_LEN 2.0

int maxWordFreq = DICTIONARY_MIN_FREQ - 1;
int minWordFreq = DICTIONARY_MAX_FREQ + 1; 

const double minRadius = 0.05;
const double maxRadius = 1.0;

const double farRightTiltAngle = 45.0;
const double farLeftTiltAngle = -1.0 * farRightTiltAngle;

const double deltaXOffset = ( DEFAULT_BRANCH_LEN );      
const double deltaYOffset = DEFAULT_BRANCH_LEN * 1.1;        


int lyricWordIndex = 0;
std::vector<clarityVal> wordClarities;

int GW;
int GH;

int light;
//Globals for lighting - use a white light and apply materials
//light position
GLfloat light_pos[4] = {0.0, 0.0, 1.5, 1.0};
//light color (ambiant, diffuse and specular)
GLfloat light_amb[4] = {0.6, 0.6, 0.6, 1.0};
GLfloat light_diff[4] = {0.6, 0.6, 0.6, 1.0};
GLfloat light_spec[4] = {0.8, 0.8, 0.8, 1.0};

//Globals for animation
int refreshMills = INT_MAX; //1000;    // refresh interval in milliseconds
int deltaRefreshMills = 500;  // the amount by which to change the refresh rate per change
int treeHeight = 0;
int deltaTreeGrow = 1;



//a sphere for drawing a spherical world
GLUquadricObj* mySphere;



int mat = 0;

//set up some materials
typedef struct materialStruct {
   GLfloat ambient[4];
   GLfloat diffuse[4];
   GLfloat specular[4];
   GLfloat shininess[1];
} materialStruct;

std::vector<materialStruct> allMaterials;

materialStruct RedFlat = {
{0.3, 0.0, 0.0, 1.0},
{0.9, 0.0, 0.0, 1.0},
{0.0, 0.0, 0.0, 1.0},
{0.0}
};

materialStruct PurpleFlat = {
{0.3, 0.0, 0.3, 1.0},
{0.9, 0.0, 0.9, 1.0},
{0.0, 0.0, 0.0, 1.0},
{0.0}
};

materialStruct OrangeFlat = {
{1.0, 0.55, 0.0, 1.0},
{0.9, 0.0, 0.0, 1.0},
{0.0, 0.0, 0.0, 1.0},
{0.0}
};

materialStruct OrangeShiny = {
{.5, .1, 0.0, 1.0},
{1.0, 0.3, 0.0, 1.0},
{1.0, .8, 0.6, 1.0},
{5.0}
};


materialStruct YellowShiny = {
{.4, .2, 0.0, 1.0},
{.9, 0.9, 0.0, 1.0},
{1.0, .8, 0.6, 1.0},
{5.0}
};

materialStruct GreenShiny = {
{0.0, 0.3, 0.0, 1.0},
{0.0, 0.9, 0.0, 1.0},
{0.8, 1.0, 0.9, 1.0},
{5.0}
};

materialStruct DarkBlueShiny = {
{0.0, 0.0, 0.3, 1.0},
{0.0, 0.0, 0.9, 1.0},
{0.8, 1.0, 0.9, 1.0},
{5.0}
};

materialStruct BlueShiny = {
{0.1, 0.1, 0.3, 1.0},
{0.0, 0.0, 0.9, 1.0},
{0.8, 1.0, 0.9, 1.0},
{5.0}
};

materialStruct MagentaShiny = {
{0.3, 0.0, 0.3, 1.0},
{0.9, 0.0, 0.9, 1.0},
{0.8, 1.0, 0.9, 1.0},
{5.0}
};
materialStruct WhiteShiny = {
{0.9, 0.9, 0.9, 1.0},
{.9, 0.9, 1.0, 1.0},
{0.8, 0.8, 0.9, 1.0},
{5.0}
};

materialStruct GrayFlat = {
{0.1, 0.1, 0.1, 1.0},
{0.2, 0.2, 0.2, 1.0},
{0.2, 0.2, 0.2, 1.0},
{0.0}
};


void buildMatVect() {
   allMaterials.push_back(OrangeShiny);     
   allMaterials.push_back(YellowShiny);
   allMaterials.push_back(WhiteShiny);
   allMaterials.push_back(MagentaShiny);
   allMaterials.push_back(BlueShiny);
   //allMaterials.push_back(GreenShiny);
   allMaterials.push_back(OrangeFlat);
   allMaterials.push_back(RedFlat);
   allMaterials.push_back(PurpleFlat);
   allMaterials.push_back(DarkBlueShiny);
}

double radiansToDegrees( double rads );
double scaleFreqToRadius( int freqVal );

//wordTreeDraw funcs
void buildAndDrawFullTree();
void buildAndDrawFullTree( std::string orthoPhrase );
void drawBranchesAtFork( std::vector< std::string > fullPhrases, double lastRadius );
void drawBranchesAtFork( std::vector< std::string > fullPhrases, double lastRadius, double xOffCur, double yOffCur );


//main funcs
void drawBranch(double tiltAngle, double xOffset, double yOffset, double cylinderHeight, double startRadius, double endRadius );
void drawBranch(double tiltAngle, double xOffset, double yOffset, double startRadius, double endRadius );
void drawBranches(double tiltAngle, double xOffset, double yOffset);
void drawBranchesRecursive(int countLeft, double tiltAngle, double xOffset, double yOffset);

void drawCylinder(double topRadius, double baseRadius, double cylinderHeight);
void drawCylinder();void Timer(int value);
void drawSphere(double radius );
void drawcube();

void materials(materialStruct materials);
void init_lighting();
void pos_light();
void pauseMine();
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y );
void changeTempoBy( int val );
void changeRefreshRateBy( int val );
int calcGrowth();
void growTreeByVal(int val);
void doLSystemsString(int numIterations); 
void initStuff();


#endif