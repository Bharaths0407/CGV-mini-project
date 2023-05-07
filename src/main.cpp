#include<stdio.h>
#include<GL/glut.h>        //Libraries decalration

void insert();
void delet();
void myReshape(int w,int h);   //function defination

GLfloat red=1.0,green=0.0,blue=0.0;
int i=0,x=-1,y=-1;                    //global variables
GLfloat angle=-20.0,xaxis=1.0,yaxis=1.0,zaxis=0.0;
char title[] = "3D Queue Representation";

void cube()                      //function to create the cube 
    {
        glScaled(0.5,0.5,0.5);     //Size of the cube
        glRotated(angle,xaxis,yaxis,zaxis); //rotation angle
        glBegin(GL_QUADS);       //type of the cube
    
        //Top face
        glColor3f(0.0f, 1.0f,  0.0f );  
        glVertex3f(  1.0f, 1.0f, -1.0f ); 
        glVertex3f( -1.0f, 1.0f, -1.0f );
        glVertex3f( -1.0f, 1.0f,  1.0f ); 
        glVertex3f(  1.0f, 1.0f,  1.0f );
    
        // Bottom face
        glColor3f(   1.0f,  1.0f,  0.0f ); 
        glVertex3f(  1.0f, -1.0f, -1.0f ); 
        glVertex3f( -1.0f, -1.0f, -1.0f );
        glVertex3f( -1.0f, -1.0f,  1.0f ); 
        glVertex3f(  1.0f, -1.0f,  1.0f );
    
        // Front face
        glColor3f(  red,  green, blue  ); 
        glVertex3f(  1.0f,  1.0f, 1.0f );
        glVertex3f( -1.0f,  1.0f, 1.0f );
        glVertex3f( -1.0f, -1.0f, 1.0f );
        glVertex3f(  1.0f, -1.0f, 1.0f ); 
    
        // Back face
        glColor3f(  0.0f,  1.0f,  0.0f  ); 
        glVertex3f(  1.0f, -1.0f, -1.0f );
        glVertex3f( -1.0f, -1.0f, -1.0f );
        glVertex3f( -1.0f,  1.0f, -1.0f ); 
        glVertex3f(  1.0f,  1.0f, -1.0f );
    
        // Left face
        glColor3f(   0.0f,  0.0f,  1.0f);  
        glVertex3f( -1.0f,  1.0f,  1.0f);
        glVertex3f( -1.0f,  1.0f, -1.0f);
        glVertex3f( -1.0f, -1.0f, -1.0f);
        glVertex3f( -1.0f, -1.0f,  1.0f);
    
        // Right face
        glColor3f(   0.0f,  1.0f,  1.0f);  
        glVertex3f(  1.0f,  1.0f,  1.0f);
        glVertex3f(  1.0f,  1.0f, -1.0f);
        glVertex3f(  1.0f, -1.0f, -1.0f);
        glVertex3f(  1.0f, -1.0f,  1.0f);
    
        glEnd();
    }

void init()    //intialize the 2d Scene
    {
        glClearColor(0.0,0.0,0.0,0.0);   //Sets the background color to black
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();                 //This resets the projection matrix to its default state
        gluOrtho2D(0.0,400.0,0.0,400.0);  //Sets viewing volume of the 2d space
        glMatrixMode(GL_MODELVIEW);
    }

void initGL()   //intialize the 3d Scene
    {
        glClearColor(0.0f, 0.0f,0.0f, 1.0f); //first 3 components are RGB which sets to black color the last component is the alpha component which sets the opaque
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);             //Sets the shading model to smooth
        glMatrixMode(GL_PROJECTION);         //transform 3D objects from world coordinates to screen coordinates
        glLoadIdentity();
	    glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0); // the coordiantes used to centered at the origin
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutSwapBuffers();               //Swaps the buffers of the double-buffered
    }

void menu(GLint option)
    {
        switch(option)
        {
            case 1 : x++;
            if(x>4)
            {
                char r1[] = "QUEUE OVERFLOW";
                glColor3f(1.0,0.0,1.0);
                glRasterPos3f(1.0,-1.5,0.2);
                for(i=0;r1[i]!='\0';i++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,r1[i]);
                }
            }
            else
            if(x<=4)
            {
                char r2[] = "Inserted Sucessfully";
                glColor3f(0.0,1.0,1.0);
                glRasterPos3f(-4.0,-1.2,0.2);
                for(i=0;r2[i]!='\0';i++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,r2[i]);
                }
            }
            insert();
            break;
            
            case 2 : delet();
                    break;
        }
        glutPostRedisplay();
    }

void insert()
    {
        if(x==-1 && y==-1 || x==0 && y==0 || x==1 && y==1 || x==2 && y==2 || x==3 && y==3 || x==4 && y==4)
        {
            char str1[]="Queue is Empty";
            glColor3f(1.0,0.0,1.0);
            glRasterPos3f(1.0,-1.7,0.2);
            for(i=0;str1[i]!='\0';i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
            }
            glutSwapBuffers();
        }
    else
        if(x==0 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.8,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-2.8f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==1 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.8,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-2.8f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==2 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.8,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-2.8f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.8,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-2.8f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.8,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(1.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-2.8f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(1.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(1.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(1.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(1.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(1.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==2)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(1.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(1.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==3)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(1.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(1.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==2)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==2 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==2 && y==1)
        {
            glRasterPos3f(-0.6,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-0.6f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==1 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.7,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-1.7f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    }