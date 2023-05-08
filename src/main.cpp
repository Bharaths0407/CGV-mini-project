#include<stdio.h>
#include<GL/glut.h>        //Libraries decalration

void insert();
void del();
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
            glRasterPos3f(-4.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-4.0f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==1 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-4.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-4.0f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==2 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-4.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-4.0f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==-1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-4.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-4.0f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glRasterPos3f(-4.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(2.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=1.0;blue=0.0;green=0.0;
            glPushMatrix();
            glTranslatef(-4.0f, 0.0, -5.0);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glTranslatef(2.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    
    }

void del()
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
        if(x==4 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(2.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glTranslatef(2.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(2.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glTranslatef(2.0f, 0.0f, -5.0f);
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
            glRasterPos3f(2.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=1.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(0.5f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(2.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==4 && y==3)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(2.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
            
            red=0.2;blue=0.6;green=0.5;
            glPushMatrix();
            glTranslatef(2.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==3 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(0.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
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
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==2 && y==1)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-1.0,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
            
            red=0.0;blue=1.0;green=0.0;
            glPushMatrix();
            glTranslatef(-1.0f, 0.0f, -5.0f);
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    else
        if(x==1 && y==0)
        {
            glColor3f(1.0,1.0,1.0);
            glRasterPos3f(-2.5,-0.85,0.2);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
            
            red=0.0;blue=0.0;green=1.0;
            glPushMatrix();
            glTranslatef(-2.5f, 0.0f, -5.0f);  
            cube();
            glPopMatrix();
            glutSwapBuffers();
        }
    }

void delet()
    {
        y++;
        if(y<5  && y<=x)
        {
            char d1[]="Deleted successfully";
            glColor3f(0.0,1.0,1.0);
            glRasterPos3f(-4.0,-1.2,0.2);
            for(i=0;d1[i]!='\0';i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,d1[i]);
            }
        }
    else
        if(x<y || x==-1 && y==-1)
        {
            printf("Queue Underflow\n");
            char e1[]="Queue Underflow";
            glColor3f(1.0,0.0,1.0);
            glRasterPos3f(1.0,-1.5,0.2);
            for(i=0;e1[i]!='\0';i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,e1[i]);
            }
        }
        del();
    }

void key(unsigned char key,int a,int b)
    {
        if(key == 'r')
        {
            angle+=10;
            insert();
        }
    
        if(key == 'l')
        {
            angle-=10;
            insert();
        }
    
        if(key == 'd')
        {
            delet();
            if(y<5 && y<=x)
            {
                printf("%d Deleted Successfully\n",y+1);
            }
        }
    
        if(key == 'n')
        {
            x++;
            if(x>4)
            {
                printf("Queue Overflow \n");
                char n1[]="Queue Overflow";
                glColor3f(1.0,0.0,1.0);
                glRasterPos3f(1.0,-1.5,0.2);
                for(i=0;n1[i]!='\0';i++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,n1[i]);
                }
            }
        else
            if(x<=4)
            {
                printf("%d Inserted successfully\n",x+1);
                char n2[]="Inserted successfully";
                glColor3f(0.0,1.0,1.0);
                glRasterPos3f(-4.0,-1.2,0.2);
                for(i=0;n2[i]!='\0';i++)
                {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,n2[i]);
                }
            }
            insert();
        }
        glutPostRedisplay();
    }

void display1(void)
    {
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        char str[]="Implementation Of Linear Queue";
        char str1[]="FrontEnd                                                                                                                                                                                           Rear End";
        glColor3f(1.0,1.0,0.0);
        glRasterPos3f(-2.0,1.8,0.2);
        for(i=0;str[i]!='\0';i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
        }
        glColor3f(0.0,0.0,1.0);
        glRasterPos3f(-6.2,0.04,0.2);
        for(i=0;str1[i]!='\0';i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
        }
        glEnd();
        glFlush();
    }

void mouse(int btn,int state,int x,int y)
    {
        if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
            int id=glutGetWindow();
            glutDestroyWindow(id);
            glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
            glutInitWindowSize(2000,500);
            glutInitWindowPosition(0,0);
            glutCreateWindow("Visualization of Queue");
            glutKeyboardFunc(key);
            glutDisplayFunc(display1);
            glutReshapeFunc(myReshape);
            glutCreateMenu(menu);
            glutAddMenuEntry("Insert",1);
            glutAddMenuEntry("Delete",2);
            glutAttachMenu(GLUT_RIGHT_BUTTON);
            initGL();
            glFlush();
        }
    }

void display(void)
    {
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        char str[]="Sai Vidya Institute Of Technology";
        glColor3f(1.0,0.0,0.0);
        glTranslatef(25.0,370.0,0.0);
        glScaled(0.1,0.2,0.0);
        for(i=0;str[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        char st[]="A";
        glColor3f(1.0,1.5,1.0);
        glTranslatef(190.0,351.0,0.0);
        glScaled(0.02,0.08,0.0);
        for(i=0;st[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        char st1[]="Mini Project Report On";
        glColor3f(1.0,1.5,1.0);
        glTranslatef(169.0,330.0,0.0);
        glScaled(0.02,0.08,0.0);
        for(i=0;st1[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st1[i]);
        }
        glPopMatrix();
    
        glPushMatrix();char str1[]="AN ANIMATION OF WORKING OF LINEAR QUEUE";
        glColor3f(1.0,1.0,0.0);
        glTranslatef(113.0,305.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str1[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str1[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        char st2[]="by";
        glColor3f(1.0,1.5,1.0);
        glTranslatef(189.0,285.0,0.0);
        glScaled(0.02,0.08,0.0);
        for(i=0;st2[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,st2[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        char str2[]="Aditya S Kanachi";
        char str3[]="Alfazal";
        char str4[]="Bharath S";
        char str5[]="Rohith Badrinath";
        char str6[]="USN:1VA20CS003";
        char str7[]="USN:1VA20CS007";
        char str8[]="USN:1VA20CS019";
        char str9[]="USN:1VA20CS042";
        glColor3f(1.0,0.06,0.576);
        glTranslatef(120.0,260.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str2[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str2[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(1.0,0.06,0.576);
        glTranslatef(120.0,220.0,0.0);
        glScaled(0.04,0.1,10.0);
        for(i=0;str3[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str3[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(1.0,0.06,0.576);
        glTranslatef(120.0,180.0,0.0);
        glScaled(0.04,0.1,10.0);
        for(i=0;str4[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str4[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(1.0,0.06,0.576);
        glTranslatef(120.0,140.0,0.0);
        glScaled(0.04,0.1,10.0);
        for(i=0;str5[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str5[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glTranslatef(210.0,260.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str6[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str6[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glTranslatef(210.0,220.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str7[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str7[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glTranslatef(210.0,180.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str8[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str8[i]);
        }
        glPopMatrix();
    
        glPushMatrix();
        glColor3f(0.0,0.5,1.0);
        glTranslatef(210.0,140.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str9[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str9[i]);
        }
        glPopMatrix();
    
        char str10[]="Under the guidance of";
        glPushMatrix();
        glColor3f(1.0,1.5,1.0);
        glTranslatef(169.0,100.0,0.0);
        glScaled(0.02,0.08,0.0);
        for(i=0;str10[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str10[i]);
        }
        glPopMatrix();
    
        char str11[]="Mr.Syed Matheen Pasha";
        glPushMatrix();
        glColor3f(1.0,0.5,0.3);
        glTranslatef(150.0,70.0,0.0);
        glScaled(0.04,0.1,0.0);
        for(i=0;str11[i]!='\0';i++)
        {
            glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str11[i]);
        }
        glPopMatrix();
        glutMouseFunc(mouse);
        glFlush();
    }

void myReshape(int w,int h)
    {
        glViewport(0,0,w,h);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
        if(w<=h)
        {
            glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,10.0,-10.0);
        }
    else
        {
            glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
        }
        glMatrixMode(GL_MODELVIEW);
    }

int main(int argc, char** argv)
    {
        printf("Visualization of Linear Queue\n");
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(2000,750);
        glutInitWindowPosition(0,0);
        glutCreateWindow(title);
        glutDisplayFunc(display); 
        init();
        glutMainLoop();        
        return 0;
    }
