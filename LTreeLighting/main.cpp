#include "main.h"


using namespace std;

string orthoPhraseRoot;

double radiansToDegrees(double rads) {
   double PI = 3.1415926;
   double degrees = ( rads * 180 ) / PI;
   return degrees;
}

double degreesToRadians(double degs) {
   double PI = 3.1415926;
   double radians = ( degs / 180 ) * PI;
   return radians;
}


/* Scale a value onto a logarithmic scale, with a minimum and maximum based on
 * minWordFreq and maxWordFreq.
 *
 * http://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
 *                     (b-a)(log(freqVal + 1) - min)
 *     scaledRadius = -------------------------------  + a
 *                          max - min
 */
double scaleFreqToRadius( int freqVal ) {
  assert ( maxWordFreq != DICTIONARY_MIN_FREQ - 1 );
  assert ( minWordFreq != DICTIONARY_MAX_FREQ + 1 );

  double a = minRadius; /* The minimum value we want after scaling */
  double b = maxRadius; /* The maximum value we want after scaling */

  /* On a linear scale, some higher frequencies dominate the graph, making all
   * the smaller ones look the same.  To prevent this, scale values down using
   * the natural log function.  We also need to shift the graph right by one
   * because log(0) is undefined. */
  freqVal = log(1.0 + freqVal);
  double max = log(1.0 + maxWordFreq); /* Our max input number, scales to b */
  double min = log(1.0 + minWordFreq); /* Our min input number, scales to a */

  double scaledRadius = ( ( b - a )*( freqVal - min ) );
  scaledRadius /= ( max - min );
  scaledRadius += a;

  return scaledRadius;
}


/*http://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
 *                     (b-a)(freqVal - min)
 *     scaledRadius = ----------------------  + a
 *                          max - min
 */
double scaleLinearFreqToRadius( int freqVal ) {
   assert ( maxWordFreq != DICTIONARY_MIN_FREQ - 1 );
   assert ( minWordFreq != DICTIONARY_MAX_FREQ + 1 );
   
   double a = minRadius;
   double b = maxRadius;
   double max = 1.0 * maxWordFreq;
   double min = 1.0 * minWordFreq;
   
   double scaledRadius = ( ( b - a )*( freqVal - min ) );
   scaledRadius /= ( max - min );
   scaledRadius += a;
   
   return scaledRadius;
}

void buildAndDrawFullTree() {
   buildAndDrawFullTree( orthoPhraseRoot );

}


void buildAndDrawFullTree( string orthoPhrase ) {
   vector< string > fullPhrases = discoverOronymsForPhrase( orthoPhrase , true );
   getMaxAndMinFreqForAllOrthoPhrases( fullPhrases, &maxWordFreq, &minWordFreq);

   /*DEBUG
   {
    glPushMatrix();
   {  
      glTranslated( -10.0 , 0.0, 0.0 );
      for( int i = 0; i < 5; i++ ) {
         glTranslated( 6.0, 0.0, 0.0);
         materials( allMaterials.at( mat++ ) );
         drawSphere(2.0);
      }
      mat = 0;
   }
   glPopMatrix();
   
   
   }
   *///END DEBUG


   //draw the tree's seed

   glPushMatrix();
   {
      //glTranslated(0.0, -1.0* DEFAULT_BRANCH_LEN , 0.0);
      glTranslated(0.0, DEFAULT_BRANCH_LEN / 2.0 , 0.0);
      materials(GreenShiny);
      drawSphere(DEFAULT_RADIUS);
      glTranslated(0.0, DEFAULT_BRANCH_LEN / -2.0 , 0.0);

   
      materials(allMaterials.at( mat % allMaterials.size () ) );

      drawBranchesAtFork ( fullPhrases, DEFAULT_RADIUS );
     
   }
   glPopMatrix();
}


void drawBranchesAtFork( vector< string > fullPhrases, double lastRadius ) {

   drawBranchesAtFork(fullPhrases, lastRadius, deltaXOffset, deltaYOffset );
}


void drawBranchesAtFork( vector< string > fullPhrases, double lastRadius, double xOffCur, double yOffCur ) {

   if( fullPhrases.size() == 0 ) {
      return;
   }
   
   /*DEBUG
   {
   cerr << "#full Phrases:"<<endl;
   for(int i = 0; i < fullPhrases.size(); i++ ) {
      cerr << "###" << fullPhrases.at(i) <<endl;
   }
   cerr << "#" <<endl;
   
   }*///END DEBUG
     
   //use a set to ensure no duplicates
   set< string > firstWords;
   
   //cerr<<"deltaXOffset="<<deltaXOffset<<";"<<endl;
   
   //put the first word of each phrase into the set
   for(int i = 0; i < fullPhrases.size(); i++){
      if( fullPhrases.at(i).size() > 0 ) {
         string firstWord = FirstWord( fullPhrases.at(i) );
         firstWords.insert( firstWord );
      }
   }
   
   /*DEBUG
   {
   vector<string> firstWordsSetVect( firstWords.begin(), firstWords.end() );
   cerr << "all first words: "<<endl;
   for(int fw = 0; fw < firstWordsSetVect.size(); fw++ ) {
      cerr << "==="<<fw<<": '"<< firstWordsSetVect.at(fw) <<"'"<<endl;
   }
   } *///END DEBUG
   
   //calculate spread of branches for firstWord
   
   double curFarRightXOffset, curFarLeftXOffset;
   double curFarRightTiltAngle, curFarLeftTiltAngle;
   double angleDelta;
   double curDeltaXOffset, curDeltaYOffset;
   curDeltaXOffset = deltaXOffset;
   curDeltaYOffset = deltaYOffset;

   
   double totalTreeWidth = fullPhrases.size() - 1;
   double spacersNeeded = firstWords.size() - 1 ;
   
   if( firstWords.size() > 1 ) {
      curDeltaXOffset = ( deltaXOffset * totalTreeWidth ) / spacersNeeded;
      
      curFarRightXOffset =  ( deltaXOffset * totalTreeWidth ) / 2.0 ; 
      
      double halfBranch = deltaYOffset / 2.0;
      curFarRightTiltAngle = atan( curFarRightXOffset / halfBranch ) ; 
      //curFarRightTiltAngle = degreesToRadians( farRightTiltAngle );
      
      curFarLeftXOffset = curFarRightXOffset - ( deltaXOffset * totalTreeWidth );
            
      curFarLeftTiltAngle = -1.0 * curFarRightTiltAngle;
      
      angleDelta = ( fabs( curFarLeftTiltAngle * 2 ) ) / spacersNeeded;
      
      
   } else {
      curFarRightXOffset = 0;
      curFarRightTiltAngle = 0;
      angleDelta = 0;
      curFarLeftTiltAngle = 0;
      curFarLeftXOffset = 0;
   }
   
   /*DEBUG
   {
   cerr<<"((((( curFarRightXOffset="<<curFarRightXOffset<<endl;
   cerr<<"(((((((( ^= ( deltaXOffset ("<<deltaXOffset<<") *";
   cerr<<"spacersNeeded ("<<spacersNeeded<<") ) / 2.0 "<<endl;
   cerr<<"((((( farRightTiltAngle="<<farRightTiltAngle<<endl;
   cerr<<"(((((((( ^= atan( deltaYOffset ("<<deltaYOffset<<") /";
   cerr<<"curFarRightXOffset ("<<curFarRightXOffset<<") )"<<endl;
   cerr<<"((((( angleDelta="<<angleDelta<<endl;
   cerr<<"((((( farLeftTiltAngle="<<farLeftTiltAngle<<endl;
   cerr<<"((((( curFarLeftXOffset="<<curFarLeftXOffset<<endl;
   } *///END DEBUG
   
   set<string>::iterator curFirstWordIter;
   int i = 0;
   //for each firstWord in the set
   for ( curFirstWordIter = firstWords.begin(); curFirstWordIter != firstWords.end(); curFirstWordIter++) {
      string curFirstWord = *curFirstWordIter;
      
      //calculate the branch radius using the scaled frequency of curFirstWord
      int firstWordFreq = queryDBwithOrthoForFreq ( curFirstWord );
      double firstWordRadius = scaleFreqToRadius( firstWordFreq );
      //cerr <<"firstWord="<<curFirstWord<<"; freq="<<firstWordFreq<<"; radius ="<<firstWordRadius<<endl;
      
      double newAdditiveRadius = firstWordRadius;
      //double newAdditiveRadius = firstWordRadius + lastRadius;
      //draw a branch

      double curYOffset = curDeltaYOffset;  //yOffCur;//deltaYOffset;  
      double curXOffset = curFarLeftXOffset + ( i * curDeltaXOffset );
      double tiltAngle = atan ( curXOffset / curYOffset );

      /*   
      double tiltAngle = curFarLeftTiltAngle + ( angleDelta * i ); 
      double curXOffset = tan( tiltAngle ) * curYOffset;
      */
      glPushMatrix();
      {
         
         glTranslated(curXOffset, curYOffset, 0.0);
         glRotated( radiansToDegrees(-1.0*tiltAngle) , 0, 0, 1.0);

         
         //if firstWord is empty
         if( curFirstWord == "") {
            assert(0);
            
         //else if firstWord indicates a dead end ( xxx or fff, defined in wordBreakdown.h )
         } else if(curFirstWord == deadEndDelim1  || curFirstWord == deadEndDelim2 ) {
            //draw a red cube/sphere at the end of the branch
            
            cerr << "___"<<i<<curFirstWord<<";\t\t LastRadius = "<<lastRadius<<endl;
            //cerr<<"deadEND! drawSphere!"<<endl;
            glPushMatrix();
            {
               materials(RedShiny);
               //glRotated( radiansToDegrees(-1.0*tiltAngle), 0, 0, 1.0);
               glTranslated(0.0, ( (lastRadius * SPHERE_MULTIPLIER) - curYOffset ) / 2.0 , 0.0);

               //glScaled( 1.0,  SPHERE_MULTIPLIER, 1.0);
               drawSphere( lastRadius * SPHERE_MULTIPLIER );
               materials(allMaterials.at( mat % allMaterials.size () ) );
            }
            glPopMatrix();

         } else if (curFirstWord == successDelim ) {
            cerr << "___"<<i<<"END;\t\t LastRadius = "<<lastRadius<<endl;
            //cerr<<"successfulEndOfPhrase! drawSphere!"<<endl;
            glPushMatrix();
            {
               glTranslated(0.0, ( (lastRadius * SPHERE_MULTIPLIER) - curYOffset ) / 2.0 , 0.0);
               materials(GreenShiny);
               drawSphere( lastRadius * SPHERE_MULTIPLIER );
               materials(allMaterials.at( mat % allMaterials.size () ) );
            }
            glPopMatrix();
         } else {
            cerr << "___firstWord"<<i<<": "<<curFirstWord;
            cerr <<";\tcurRadius="<<newAdditiveRadius;
            //cerr <<";\tfreq="<<firstWordFreq;
            cerr <<";\tcurXOffset="<<curXOffset<<";\ttiltAngle="<<tiltAngle;
            //cerr<<";\tangleDelta="<<angleDelta<<";\tcurFarRightXOffset="<<curFarRightXOffset<<endl;
            cerr<<";"<<endl;
            
            drawBranch( radiansToDegrees( tiltAngle ), curXOffset, curYOffset, newAdditiveRadius, lastRadius );
         
            //find all phrases in fullPhrases that start with that firstWord
            vector<string> tailsVect = getAllPhrasesWithPrefix( curFirstWord, fullPhrases);
            
            //DEBUG WITH COLORSSS for each branch level
            materials(allMaterials.at( ++mat % allMaterials.size () ) );
            
            //cerr<<"%%%%%%%%%%"<<i<<"%%%%%%%%% curYOffset = "<<curYOffset<< "  %%%%%%%%%%%%%%%%%"<<endl;
            //pass those phrases to drawBranchesAtFork
            drawBranchesAtFork( tailsVect, newAdditiveRadius, curXOffset, curYOffset );
            
            //DEBUG WITH COLORSSS!
            materials(allMaterials.at( --mat % allMaterials.size () ) );
            
         }
         //glPopMatrix();
      }
      glPopMatrix();
      

      i++;
   }
   
      
}





void drawBranch(double tiltAngle, double xOffset, double yOffset, 
               double baseRadius, double topRadius ) {
   double cylinderHeight = DEFAULT_BRANCH_LEN;
   drawBranch(tiltAngle, xOffset, yOffset, cylinderHeight, baseRadius, topRadius);
}
   
void drawBranch(double tiltAngle, double xOffset, double yOffset, 
               double cylinderHeight, double baseRadius, double topRadius ) {
               
   //cerr << "Draw branch; tiltAngle = "<<tiltAngle<<" offset = ("<<xOffset<<", "<<yOffset;   
   //cerr << ")\n\tcylinderHeight="<<cylinderHeight<<" baseRadius = "<<baseRadius <<"; topRadius = "<< topRadius << endl;
   glPushMatrix();
   {
      //glTranslated(xOffset, yOffset, 0.0);
      //glRotated(-tiltAngle, 0, 0, 1.0);
      drawCylinder(baseRadius, topRadius, cylinderHeight );

   }
   glPopMatrix();
}

void drawBranches(double tiltAngle, double xOffset, double yOffset) {
    glPushMatrix();
    {
        //Draw right branch
        glTranslated(xOffset, yOffset, 0.0);
        glRotated(tiltAngle, 0, 0, 1.0);
        drawCylinder();
    }
    glPopMatrix();
    glPushMatrix();
    {
        //draw left branch
        glTranslated(-xOffset, yOffset, 0.0);
        
        glRotated(-tiltAngle, 0, 0, 1.0);
        
        drawCylinder();
    }
    glPopMatrix();
}

void drawBranchesRecursive(int countLeft, double tiltAngle, double xOffset, double yOffset) {
    //countleft==the number of levels of branches above this one.
    if( countLeft == 0) {
        return;
    }
    glPushMatrix();
    {
        //Draw right branch
        glTranslated(xOffset, yOffset, 0.0);

        glRotated(-tiltAngle, 0, 0, 1.0);
        drawCylinder();
        
        //glPushMatrix();
        //{
            drawBranchesRecursive(countLeft-1, tiltAngle * .75, xOffset, yOffset);
        //}
        //glPopMatrix();
    }
    glPopMatrix();
    glPushMatrix();
    {
        //draw left branch
        glTranslated(-xOffset, yOffset, 0.0);
        
        glRotated(tiltAngle, 0, 0, 1.0);
        
        drawCylinder();
        //glPushMatrix();
        //{
            drawBranchesRecursive(countLeft-1, tiltAngle * .75, xOffset, yOffset);
        //}
        //glPopMatrix();
    }
    glPopMatrix();
}

void drawCylinder(double topRadius, double baseRadius, double cylinderHeight ) {
    {
        double radiiTop = topRadius;
        double radiiBase = baseRadius;
        double height = cylinderHeight;
        int sliceNum = 60;
        int stackNum = 60;
        glPushMatrix();
        {
            glTranslated(0.0, -( height/2.0 ), 0);
            glRotated(-90, 1.0, 0, 0);
            GLUquadricObj *myCylinder = gluNewQuadric();
            gluQuadricDrawStyle(myCylinder, GLU_FILL);
            gluCylinder(myCylinder, radiiBase, radiiTop, height, sliceNum, stackNum);
        }
        glPopMatrix();
    } 
}

void drawCylinder() {
    drawCylinder( DEFAULT_RADIUS*.80 , DEFAULT_RADIUS, DEFAULT_BRANCH_LEN );
}

//draw a sphere
void drawSphere( double rad ) {
   //void gluSphere	(	GLUquadric* quad , GLdouble radius , GLint slices , GLint stacks );
   glPushMatrix();
   {
      gluSphere(mySphere, rad, 40, 40);
   }
   glPopMatrix();
}


//dorky way to draw a cube one face at a time
void drawcube() {
   
   //color of the cube for when lighting is disabled
   glColor3f(1.0, 0.0, 0.0);
   
   //left face: for lighting you must specify a normal for each face!
   glNormal3f(-1.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex3f(-0.5, 0.5, 0.5); //v5
   glVertex3f(-0.5, 0.5, -0.5); //v4
   glVertex3f(-0.5, -0.5, -0.5); //v1
   glVertex3f(-0.5, -0.5, 0.5); //v8
   glEnd();
   
   //right face:  for lighting you must specify a normal for each face!
   glNormal3f(1.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex3f(0.5, -0.5, -0.5); //v2
   glVertex3f(0.5, 0.5, -0.5); //v3
   glVertex3f(0.5, 0.5, 0.5); //v6
   glVertex3f(0.5, -0.5, 0.5); 
   glEnd();
   
   //bottom face:  for lighting you must specify a normal for each face!
   glNormal3f(0, -1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex3f(-0.5, -0.5, 0.5); //v8
   glVertex3f(0.5, -0.5, 0.5); //v7
   glVertex3f(0.5, -0.5, -0.5); //v2
   glVertex3f(-0.5, -0.5, -0.5); //v1
   glEnd();
   
   //top face:  for lighting you must specify a normal for each face!
   glNormal3f(0, 1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex3f(0.5, 0.5, -0.5); //v3
   glVertex3f(-0.5, 0.5, -0.5); //v4
   glVertex3f(-0.5, 0.5, 0.5); //v5
   glVertex3f(0.5, 0.5, 0.5); //v6
   glEnd();
   
   //front face:  for lighting you must specify a normal for each face!
   glNormal3f(0, 0, 1.0);
   glBegin(GL_POLYGON);
   glVertex3f(-0.5, 0.5, 0.5); //v5
   glVertex3f(0.5, 0.5, 0.5); //v6
   glVertex3f(0.5, -0.5, 0.5); //v7
   glVertex3f(-0.5, -0.5, 0.5); //v8
   glEnd();
   
   //back face:  for lighting you must specify a normal for each face!
   glNormal3f(0, 0, -1.0);
   glBegin(GL_POLYGON);
   glVertex3f(-0.5, -0.5, -0.5); //v1
   glVertex3f(0.5, -0.5, -0.5); //v2
   glVertex3f(0.5, 0.5, -0.5); //v3
   glVertex3f(-0.5, 0.5, -0.5); //v4
   glEnd();
   
}



//sets up a specific material
void materials(materialStruct materials) {
   glMaterialfv(GL_FRONT, GL_AMBIENT, materials.ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, materials.diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, materials.specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, materials.shininess);
}

//initialization calls for opengl for static light
//note that we still need to enable lighting in order for it to work
//see keyboard 'l' event
void init_lighting() {
   //turn on light0
   glEnable(GL_LIGHT0);
   //set up the diffuse, ambient and specular components for the light
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
   //specify our lighting model as 1 normal per face
   glShadeModel(GL_FLAT);
}

void pos_light() {
   //set the light's position
   glMatrixMode(GL_MODELVIEW);
   glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}


void Timer(int value) {
   
   growTreeByVal( deltaTreeGrow );  
   
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, Timer, deltaTreeGrow ); // next Timer call milliseconds later
}

void pauseMine() {
   if ( deltaTreeGrow == 0 ) {
      deltaTreeGrow = 1;
   } else {
      deltaTreeGrow = 0;
   }
}

void display() {
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   glMatrixMode(GL_MODELVIEW);
   //save current matrix
   glPushMatrix();
    
    double eyex = 0.0;   //1.0
    double eyey = 0.0;   //1.0
    double eyez = 10.0;   //1.5
   //set up the camera
   gluLookAt(eyex, eyey, eyez, //eye position
             0.0, 0.0, 0.0, //point we are looking at
             0.0, 1.0, 0.0);  //up vector
   
   //position the light in the scene
   pos_light();
   //draw the cube
   //drawcube();
   
    double halfRadius = .25;
    double cylinderHeight = 2.0;
    
    buildAndDrawFullTree();
    //drawBranchesRecursive(treeHeight, 45, halfRadius, cylinderHeight*.75);

    /*
    for (int i = 1; i < 50; i++) {
        //for (int i = 0; i < 50; i++) {
        //drawBranches(-30.0, i*halfRadius+i*halfRadius, (i+1)*(cylinderHeight) );
        drawBranches(-30.0, i*halfRadius, i*(cylinderHeight) );

    }
     */
    
   glPopMatrix();
   
   glutSwapBuffers();
   
}

void reshape(int w, int h) {
   GW = w;
   GH = h;
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //notice the change in the near and far planes - they are measure with respect to the
   //camera position
   glOrtho( -20*(float)w/h, (float)20*w/h, -5, 20, 1.0, 15.0);
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, w, h);
   
}


void keyboard(unsigned char key, int x, int y )
{
   switch( key ) {
      case 'l': case 'L':
         light = !light;
         if (light)
            glEnable(GL_LIGHTING);
         else
            glDisable(GL_LIGHTING);
         break;
         //simple way to toggle the materials
      case 'm': case 'M':
         mat++;
         materials(allMaterials.at( mat % allMaterials.size () ) );
         break;
      case 'n': case 'N':
         //int growth = calcGrowth();
         growTreeByVal( calcGrowth() );
         break;
      case 'g': case 'G':
         //printf("keypress G");
         growTreeByVal( 1 );  
         break;
      case 's': case 'S':
         //printf("keypress S");
         if ( treeHeight > 0 ) {
            growTreeByVal( -1 );   
         }
         break;
      case '>': case '.':
         //then make tempo faster!
         changeTempoBy( 1 );
         break;
      case '<': case ',':
         //then make tempo slower!
         changeTempoBy( -1 );
         break;  
      case 'p': case 'P':
         //printf("keypress P");
         pauseMine(); 
         break;  
      case 'q': case 'Q' :
         exit( EXIT_SUCCESS );
         break;
   }
   glutPostRedisplay();
}

void changeTempoBy( int val ) {
   changeRefreshRateBy( -1 * val * deltaRefreshMills );

}

void changeRefreshRateBy( int val ) {
   refreshMills += val;
   printf("Refresh every %d ms\n",refreshMills);
}

int calcGrowth() {
   //printf("entering calc growth");
   clarityVal clarval = wordClarities[lyricWordIndex];
   int length = wordClarities.size();  // establish size of array
   int max = wordClarities[0];       // start with max = first element
   
   for(int i = 1; i<length; i++)
   {
      if(wordClarities[i] > max)
         max = wordClarities[i];
   }
   int growth = max / clarval;
   return growth;
}



void growTreeByVal(int val) {
   //printf("entering growTreeByVal");

   treeHeight+=val;
   if(val >=0 ) {
      printf("Grow tree height by %d to %d\n",val,treeHeight);
   } else {
      printf("Shrink tree height by %d to %d\n",val, treeHeight);    
   }

}

void doLSystemsString(int numIterations) { //, string seedStr, string pat1, string rplc1, string pat2, string rplc2) {
    string seedString = "AB"; // = seedStr;

    
    for(int iter = 0; iter < numIterations; iter++ ) {
        
        string pattern1 = "A"; // = pat1;
        string pattern2 = "B"; // = pat2; 
        
        string replacer1 = "AB"; // = rplc1;
        string replacer2 = "BA"; // =rplc2;
        string temp = "";

        string patChar1 = "x"; 
        string patChar2 = "y";
        string repSeedStr = "";
        string finalSeedlingString = "";
        
        for(int i = 0; i < seedString.length(); i++) {
            temp += seedString[i];
            if ( temp == pattern1 ) {
                repSeedStr += patChar1;
                finalSeedlingString += replacer1;
                temp = "";
            } else if (temp == pattern2 ) {
                repSeedStr += patChar2;
                finalSeedlingString += replacer2;

                temp = "";
            } else {
                assert( temp.length() < pattern1.length() || temp.length() < pattern2.length() );
            }
        }
        
        //repSeedStr.replace(patChar1, replacer1);
        //repSeedStr.replace(patChar2, replacer2);
        printf("iter %d:  \n\t repSeedStr: %s \t finalSeedlingString: %s\n",iter, repSeedStr.c_str(), finalSeedlingString.c_str());
        seedString = finalSeedlingString;
    }

}

void initStuff() {
   buildMatVect();
   //create a sphere
   mySphere = gluNewQuadric();
   gluQuadricDrawStyle(mySphere, GLU_FILL);
   
   vector<lyricWord> lyrics;
   //dummy stub method with dummy return val
   wordClarities =  measureClarity( lyrics );
}

//* credit to Dae here: http://cboard.cprogramming.com/cplusplus-programming/118266-strings-find-replace.html *//
/*
void find_and_replace(std::string& source, std::string const& find, std::string const& replace)
{
    for(std::string::size_type i = 0; (i = source.find(find, i)) != std::string::npos;)
    {
        source.replace(i, find.length(), replace);
        i += replace.length() - find.length() + 1;
    }
}
*/

int main(int argc, char** argv) {

   if ( argc >= 2 ) {
      cerr << argv[1] <<endl;
      orthoPhraseRoot = argv[1];
   } else {
   //orthoPhraseRoot = "visual representation of the phonetic ambiguity of the written word";
   //orthoPhraseRoot = "tilt angle bonus round award";
   //orthoPhraseRoot = "tilt angle bonus round quit";
   //orthoPhraseRoot = "tilt angle break round quit";
   
      orthoPhraseRoot = "iced ink";

   //orthoPhraseRoot = "empty till is sad";
   //orthoPhraseRoot = "empty till is sadface";
   //orthoPhraseRoot = "a";
   //orthoPhraseRoot = "gray pants";
   //orthoPhraseRoot = "email";
   //orthoPhraseRoot = "our mail is late";
   //orthoPhraseRoot = "empty our email";
   //orthoPhraseRoot = "blessed hour";
   //orthoPhraseRoot = "empty hour";
   //orthoPhraseRoot = "a nice";
   //orthoPhraseRoot = "a nice cold";
   //orthoPhraseRoot = "a nice cold hour";
   }

   //set up glut window
   glutInit(&argc, argv);
   glutInitWindowSize(1200, 800);
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutCreateWindow(orthoPhraseRoot.c_str());
   glClearColor(1.0, 1.0, 1.0, 1.0); // set bg to white
   
   //set up glut callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   
   //initialize globals
   GW = 600;
   GH = 600;
   light = 1;
    
   initStuff();
   treeHeight = 0;
   
   //doLSystemsString(2);
   //printf("\n\n");
   //doLSystemsString(10);

   //enable GL features we want
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   
   
   //only do this once
   init_lighting();
   
   
   //glutTimerFunc(0, Timer, deltaTreeGrow );
   glutMainLoop();
   
}


