
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLint b=300;
float  counter=600.0;
void initOpenGl()
{
    glClearColor(0.5, 0.8, 0.8,1); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
    glMatrixMode(GL_MODELVIEW);
}

void eye(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+2*cos(th),y+2*sin(th));
   }

   glEnd();

}



void fish()
{


   //Bottom Part
   glLoadIdentity();
   counter=counter-0.05;
   //glTranslated(counter,100,0.0);
   //glScaled(0.1,0.1,0.0);

   //body
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(480,160);
   glVertex2f(480,100);

   //tail

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(480, 140);
   glVertex2f(480, 60);

   glEnd();

   eye(120,120);

}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.2,0.2,0.2);
  fish();
  glutSwapBuffers();
  glFlush();


}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Fish Static");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}

 
