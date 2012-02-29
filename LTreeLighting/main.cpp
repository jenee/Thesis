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


#include "Metrics.h"



using namespace std;


void growTreeByVal(int val);
int calcGrowth();

int lyricWordIndex = 0;
vector<clarityVal> wordClarities;

int GW;
int GH;

int light;
//globals for lighting - use a white light and apply materials
//light position
GLfloat light_pos[4] = {0.0, 0.0, 1.5, 1.0};
//light color (ambiant, diffuse and specular)
GLfloat light_amb[4] = {0.6, 0.6, 0.6, 1.0};
GLfloat light_diff[4] = {0.6, 0.6, 0.6, 1.0};
GLfloat light_spec[4] = {0.8, 0.8, 0.8, 1.0};


double halfRadius = .25;
double cylinderHeight = 2.0;

int treeHeight = 0;

int mat = 0;
//set up some materials
typedef struct materialStruct {
   GLfloat ambient[4];
   GLfloat diffuse[4];
   GLfloat specular[4];
   GLfloat shininess[1];
} materialStruct;

materialStruct RedFlat = {
{0.3, 0.0, 0.0, 1.0},
{0.9, 0.0, 0.0, 1.0},
{0.0, 0.0, 0.0, 1.0},
{0.0}
};
materialStruct GreenShiny = {
{0.0, 0.3, 0.0, 1.0},
{0.0, 0.9, 0.0, 1.0},
{0.2, 1.0, 0.2, 1.0},
{8.0}
};

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


void drawCylinder() {
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
    
    drawBranchesRecursive(treeHeight, 45, halfRadius, cylinderHeight*.75);

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
         growTreeByVal( treeHeight + 1 );  
         break;  
      case 's': case 'S':
         if ( treeHeight > 0 ) {
            growTreeByVal( treeHeight - 1 );   
         }
         break;
      case 'q': case 'Q' :
         exit( EXIT_SUCCESS );
         break;
   }
   glutPostRedisplay();
}

int calcGrowth() {
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
    
   treeHeight = 10;
   
   doLSystemsString(2);
    printf("\n\n");
    doLSystemsString(10);

   //enable GL features we want
   glEnable(GL_DEPTH_TEST);
   //only do this once
   init_lighting();
   
   glutMainLoop();
   
}


