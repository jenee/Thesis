#include "main.h"


using namespace std;








/*http://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
 *                     (b-a)(freqVal - min)
 *     scaledRadius = ----------------------  + a
 *                          max - min
 */
double scaleFreqToRadius( int freqVal ) {
   assert ( maxWordFreq != DICTIONARY_MIN_FREQ - 1 );
   assert ( minWordFreq != DICTIONARY_MAX_FREQ + 1 );
   
   double a = minRadius;
   double b = maxRadius;
   double max = 1.0 * maxWordFreq;
   double min = 1.0 * minWordFreq;
   
   double scaledRadius = ( ( b - a )*( freqVal - min ) );
   scaledRadius /= ( max = min );
   scaledRadius += a;
   
   return scaledRadius;
}


string FirstWord(const string& line)
{
    return line.substr(0, line.find(' ')+1 );
}

void drawBranchesAtFork( vector< string > fullPhrases, double lastRadius ) {

   if( fullPhrases.size() == 0 ) {
      return;
   }
   
   //use a set to ensure no duplicates
   set< string > firstWords;
   
   //put the first word of each phrase into the set
   for(int i = 0; i < fullPhrases.size(); i++){
      if( fullPhrases.at(i).size() > 0 ) {
         firstWords.insert( FirstWord( fullPhrases.at(i) ) );
      }
   } 
   
   double angleDelta = 90.0 / firstWords.size();
   
   double farRightXOffset = ( defaultXOffset * firstWords.size() ) / 2.0;
   double farLeftXOffset = farRightXOffset * -1.0;
   
   set<string>::iterator curFirstWordIter;
   int i = 0;
   //for each firstWord in the set
   for ( curFirstWordIter = firstWords.begin(); curFirstWordIter != firstWords.end(); curFirstWordIter++) {
      string curFirstWord = *curFirstWordIter;
      int firstWordFreq = queryDBwithOrthoForFreq ( curFirstWord );
      double firstWordRadius = scaleFreqToRadius( firstWordFreq );

      
      //draw a branch
      //TODO: this will have to be scaled, translated
      double tiltAngle = farLeftTiltAngle + ( angleDelta * i ); 
      double curXOffset = farLeftXOffset + ( defaultXOffset * i );
      double curYOffset = defaultYOffset;     

      drawBranch( tiltAngle, curXOffset, curXOffset, lastRadius, firstWordRadius );
      
      glPushMatrix();
      {
         //if firstWord indicates a dead end ( xxx or fff, defined in wordBreakdown.h )
         if( curFirstWord == deadEndDelim1  || curFirstWord == deadEndDelim2 ) {
            //draw a red cube/sphere at the end of the branch
            drawcube();
            //TODO: this will have to be scaled, translated and parameterized;
         } else {
            //find all phrases in fullPhrases that start with that firstWord
            set<string> tailPhrases;
            for (int j = 0; j < fullPhrases.size(); j++) {
               if( curFirstWord == FirstWord( fullPhrases.at(j) ) ) {
                  //remove firstWord from those phrases
                  string tempFull = fullPhrases.at(j);
                  string tempTail = tempFull.substr( tempFull.find(' ')+1 );
                  tailPhrases.insert( tempTail );
               }
            }
            //convert set to vector
            vector<string> tailsVect( tailPhrases.begin(), tailPhrases.end() );
            //pass those phrases to drawBranchesAtFork
            drawBranchesAtFork( tailsVect, firstWordRadius );
         }
      }
      glPopMatrix();
      i++;
   }
   
      
}


void buildAndDrawFullTree( string orthoPhrase ) {
   vector< string > fullPhrases = discoverOronymsForPhrase( orthoPhrase );
   getMaxAndMinFreqForAllOrthoPhrases( fullPhrases, &maxWordFreq, &minWordFreq);
   drawBranchesAtFork ( fullPhrases, DEFAULT_RADIUS );
}

void buildAndDrawFullTree() {
   buildAndDrawFullTree("a nice cold hour");
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



void drawCylinder(double baseRadius, double topRadius, double height ) {
    {
        double radiiTop = halfRadius;
        double radiiBase = halfRadius*.80;
        double height = cylinderHeight;
        int sliceNum = 30;
        int stackNum = 30;
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
    drawCylinder( halfRadius*.80 , halfRadius, cylinderHeight);
}

void drawBranch(double tiltAngle, double xOffset, double yOffset, 
               double startRadius, double endRadius ) {
   assert(0);
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
   
   drawCylinder();
    
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
         if (mat%2 == 0)
            materials(RedFlat);
         else if (mat%2 == 1)
            materials(GreenShiny);
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
   //set up glut window
   glutInit(&argc, argv);
   glutInitWindowSize(1200, 800);
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutCreateWindow("Basic Ltree");
   glClearColor(0.0, 0.0, 0.0, 1.0);
   
   //set up glut callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   
   //initialize globals
   GW = 400;
   GH = 400;
   light = 0;
    
   treeHeight = 0;
   
   doLSystemsString(2);
    printf("\n\n");
    doLSystemsString(10);

   //enable GL features we want
   glEnable(GL_DEPTH_TEST);
   //only do this once
   init_lighting();
   glutTimerFunc(0, Timer, deltaTreeGrow );
   glutMainLoop();
   
}


