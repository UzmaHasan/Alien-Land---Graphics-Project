#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

 float	tx	=  9.0;
 float	ty	=  9.0;

 float dy=0.0;

 float p=-50.0;
 float p1=-100.0;
 float q=-100.0;
 float u= 20.0;
 float f= 0.0;
 float u1= 20.0;
 float f1= 0.0;

 float x=30.0;
 float y=30.0;

 static GLfloat spin = 0.0;

 static GLfloat spinhead = 0.0;

 static GLfloat spin1 = 0.0;

 static GLfloat spin2 = 90.0;

 static GLfloat spinhand = 0.0;

 GLfloat angle = 0.0f;

 void idle() {
   glutPostRedisplay();   // Post a re-paint request to activate display()
}

void circle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 200;
			//angle = 3 * PI * 5 * i / 100;
			glVertex2f (cos(angle) * radius_x+p, sin(angle) * radius_y+p);
		}
glEnd();

}
void ufocircle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 200;
			//angle = 3 * PI * 5 * i / 100;
			glVertex2f (cos(angle) * radius_x+u, sin(angle) * radius_y+f);
		}
glEnd();

}
void bomb(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 200; i++)
		{
			angle = 2 * PI * i / 200;
			//angle = 3 * PI * 5 * i / 100;
			glVertex2f (cos(angle) * radius_x+q, sin(angle) * radius_y+p1);
		}
glEnd();

}
void eyecircle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 200; i++)
		{
			angle = 2 * PI * i / 200;
			//angle = 3 * PI * 5 * i / 100;
			glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
		}
glEnd();

}

void halfcircle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 200;
			//angle = 3 * PI * 5 * i / 100;
			glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
		}
glEnd();

}

void movehead(void)
{
    //PlaySound("strings2", NULL, SND_FILENAME| SND_ASYNC);
      spin = spin + 0.009;
    if (spin > 2.99)
        spin = spin - 15.0;

       spin1 = spin1 - 0.009;
    if (spin1 < -2.99)
        spin1 = spin1 + 15.0;

        spinhead = spinhead + 0.01;
    if (spinhead > 0.1)
        spinhead = spinhead - 8.0;
   // else spinhead = spinhead + 10.0;

   spinhand = spinhand - 0.009;
    if (spinhand < -3.0)
        spinhand = spinhand + 10.0;
    //else spinhand = spinhand - 15.0;



    glutPostRedisplay();

}

void moveufo(void)

{
    u=u-4.8;
    u1=u1-4.8;
    if(u1<-3.99){
          //  glTranslatef(30.0,0.3,0);
        //u1=20.0;
        f1=1000.0;

    glutPostRedisplay();}
    PlaySound("strings3", NULL, SND_FILENAME| SND_ASYNC);
    //f=f-10.0;
}

void doggy(void)
{
    dy=dy+2.1;
    if(dy>36.5)
        dy=100.0;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


      //sky
      glPushMatrix();
      glTranslatef(0.0,-18.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
       //Yellow
      glColor3f(0.3f, 0.20f, 0.25f);
      glVertex2f(-25.0f, 10.0f);
       glColor3f(0.0f, 0.38f, 0.59f);
      //glColor3f(0.44f, 0.44f, 0.99f);
      glVertex2f( 25.0f, 10.0f);

      glColor3f(0.0f, 0.0f, 0.0f);

      glVertex2f( 25.0,  50.0f);
      glColor3f(0.0f, 0.0f, 0.0f);

      glVertex2f( -25.0f,  50.0f);
      glEnd();
	  glPopMatrix();
	  //***************************************
      //mati
      glPushMatrix();
      glTranslatef(0.0,-18.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.86f, 0.0f, 0.79f); //Yellow
      glVertex2f(-25.0f, 10.0f);
      glColor3f(0.02f, 0.01f, 0.22f);
      glVertex2f( 25.0f, 10.0f);
      glColor3f(0.01f, 0.0f, 0.1f);
      glVertex2f( 25.0,  -10.0f);
      glColor3f(0.02f, 0.05f, 0.08f);
      glVertex2f( -25.0f,  -10.0f);
      glEnd();
	  glPopMatrix();

	  	  //******************************************

	  //>>>>>>>>>>>>>>>>>>>>

	  //rightmost building

	  //body
      glPushMatrix();
      glTranslatef(20.0,20.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.77f, 0.0f, 0.22f);
      glVertex2f( 6.0,  11.0f);
      glColor3f(0.33f, 0.0f, 0.44f);
      glVertex2f( 1.0f,  11.0f);
      glColor3f(0.9f, 0.6f, 0.99f); //Yellow
      glVertex2f(1.5f, 29.0f);
      glColor3f(1.0f, 0.4f, 0.99f);
      glVertex2f( 5.5f, 29.0f);
      glEnd();
	  glPopMatrix();


	  //innerbody
      glPushMatrix();
      glTranslatef(19.5,20.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.55f, 0.22f);
      glVertex2f( 4.0,  13.0f);
      glColor3f(0.0f, 0.0f, 0.44f);
      glVertex2f( 2.0f,  13.0f);
      glColor3f(0.0f, 0.7f, 0.88f); //Yellow
      glVertex2f(2.0f, 29.0f);
      glColor3f(0.0f, 0.0f, 0.99f);
      glVertex2f( 4.0f, 29.0f);
      glEnd();
	  glPopMatrix();



	  //pasher left baby
      glPushMatrix();
      glTranslatef(16.2,16.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.77f, 0.0f, 0.22f);
      glVertex2f( 6.0,  11.0f);
      glColor3f(0.33f, 0.0f, 0.44f);
      glVertex2f( 2.0f,  9.0f);
      glColor3f(0.9f, 0.6f, 0.99f); //Yellow
      glVertex2f(1.5f, 25.0f);
      glColor3f(1.0f, 0.4f, 0.99f);
      glVertex2f( 5.5f, 25.0f);
      glEnd();
	  glPopMatrix();

	  //innerbodyleft
      glPushMatrix();
      glTranslatef(16.5,20.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.55f, 0.22f);
      glVertex2f( 4.0,  13.0f);
      glColor3f(0.0f, 0.0f, 0.44f);
      glVertex2f( 2.0f,  13.0f);
      glColor3f(0.0f, 0.7f, 0.88f); //Yellow
      glVertex2f(2.0f, 29.0f);
      glColor3f(0.0f, 0.0f, 0.99f);
      glVertex2f( 4.0f, 29.0f);
      glEnd();
	  glPopMatrix();

	   //pasher right baby
      glPushMatrix();
      glTranslatef(23.9,16.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.77f, 0.0f, 0.22f);
      glVertex2f( 5.0,  9.0f);
      glColor3f(0.33f, 0.0f, 0.44f);
      glVertex2f( 1.0f,  11.0f);
      glColor3f(0.9f, 0.6f, 0.99f); //Yellow
      glVertex2f(1.5f, 25.0f);
      glColor3f(1.0f, 0.4f, 0.99f);
      glVertex2f( 5.5f, 25.0f);
      glEnd();
	  glPopMatrix();

	   //innerbodyright
      glPushMatrix();
      glTranslatef(22.5,20.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.55f, 0.22f);
      glVertex2f( 4.0,  13.0f);
      glColor3f(0.0f, 0.0f, 0.44f);
      glVertex2f( 2.0f,  13.0f);
      glColor3f(0.0f, 0.7f, 0.88f); //Yellow
      glVertex2f(2.0f, 29.0f);
      glColor3f(0.0f, 0.0f, 0.99f);
      glVertex2f( 4.0f, 29.0f);
      glEnd();
	  glPopMatrix();

	  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    //drone

      glPushMatrix();
      glTranslatef(0.0,dy,0);
     // glRotatef(spinhead, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.59f, 1.0f, 0.0f); //Yellow
      glVertex2f(9.5f, -20.0f);
      glVertex2f( 11.5f, -20.0f);
      glVertex2f( 11.5,  -23.0f);
      glVertex2f( 7.5f,  -23.0f);
      glEnd();
	  glPopMatrix();


      glPushMatrix();
      glTranslatef(0.0,dy,0);
	  glBegin(GL_POLYGON);
      glColor3f(0.05f, 0.66f, 0.77f); //Yellow
      glVertex2f(11.5f, -19.0f);
      glVertex2f( 13.5f, -19.0f);
      glVertex2f( 13.5,  -23.0f);
      glVertex2f( 9.5f,  -23.0f);
      glEnd();
	  glPopMatrix();


      glPushMatrix();
      glTranslatef(0.0,dy,0);
	 // glRotatef(180.0, 0.0, 0.0, 1.0);
	  glBegin(GL_POLYGON);
      glColor3f(0.59f, 1.0f, 0.0f); //Yellow
      glVertex2f(13.5f, -20.0f);
      glVertex2f( 15.5f, -20.0f);
      glVertex2f( 15.5,  -21.0f);
      glVertex2f( 11.5f,  -21.0f);
      glEnd();
	  glPopMatrix();

	  //##############################################

	   //leftmostbuilding

	   //matha
	    glPushMatrix();
      glTranslatef(-4.5,-19.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);

      glColor3f(0.9f, 0.0f, 0.93f);
      glVertex2f( -18.0,  25.0f);
     // glColor3f(1.0f, 0.4f, 0.78f);
      //glVertex2f( -20.0f,  12.0f);
      glColor3f(0.3f, 0.6f, 0.99f); //Yellow
      glVertex2f(-18.5f, 20.0f);
      glColor3f(1.0f, 0.4f, 0.99f);
      glVertex2f( -17.5f, 20.0f);

      glEnd();
	  glPopMatrix();

	  //body
      glPushMatrix();
      glTranslatef(-4.5,-19.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.3f, 0.6f, 0.99f); //Yellow
      glVertex2f(-18.5f, 20.0f);
      glColor3f(1.0f, 0.4f, 0.99f);
      glVertex2f( -17.5f, 20.0f);
      glColor3f(0.9f, 0.0f, 0.93f);
      glVertex2f( -16.0,  12.0f);
      glColor3f(1.0f, 0.4f, 0.78f);
      glVertex2f( -20.0f,  12.0f);
      glEnd();
	  glPopMatrix();


	  //square nicher
      glPushMatrix();
      glTranslatef(-4.0,-22.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.3f, 0.6f, 0.99f); //Yellow
      glVertex2f(-20.5f, 15.0f);
      glColor3f(0.0f, 0.4f, 0.99f);
      glVertex2f( -16.5f, 15.0f);
      glColor3f(0.9f, 0.0f, 0.93f);
      glVertex2f( -16.5,  12.0f);
      glColor3f(0.0f, 0.4f, 0.99f);
      glVertex2f( -20.5f,  12.0f);
      glEnd();
	  glPopMatrix();


	  //lower quad
      glPushMatrix();
      glTranslatef(-41.0,2.0,0);
      glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);

      glColor3f(0.0f, 0.22f, 0.93f);
      glVertex2f( -16.5,  12.0f);
      glColor3f(0.0f, 0.33f, 0.99f);
      glVertex2f( -20.5f,  12.0f);
      glColor3f(0.0f, 0.99f, 0.99f); //Yellow
      glVertex2f(-21.5f, 15.0f);
      glColor3f(0.0f, 0.99f, 0.99f);
      glVertex2f( -15.5f, 15.0f);
      glEnd();
	  glPopMatrix();

      //############################################

      //holes

    glPushMatrix();
	glTranslatef(16.5,9.2,0);
    glColor3f(0.5f, 0.1f, 0.9f);
	eyecircle(0.9,0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.5,7.2,0);
    glColor3f(0.5f, 0.1f, 0.9f);
	eyecircle(0.9,0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.5,7.2,0);
    glColor3f(0.5f, 0.1f, 0.9f);
	eyecircle(0.9,0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-22.5,6.2,0);
    glColor3f(0.8f, 0.1f, 0.6f);
	eyecircle(0.3,0.9);
	glPopMatrix();

		glPushMatrix();
	glTranslatef(-22.5,-1.2,0);
    glColor3f(0.8f, 0.1f, 0.6f);
	eyecircle(0.3,0.9);
	glPopMatrix();

		glPushMatrix();
	glTranslatef(-22.5,-5.2,0);
    glColor3f(0.8f, 0.1f, 0.6f);
	eyecircle(0.3,0.9);
	glPopMatrix();

		glPushMatrix();
	glTranslatef(-22.6,-11.2,0);
    glColor3f(0.8f, 0.1f, 0.6f);
	eyecircle(0.3,0.9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-24.3,-11.2,0);
    glColor3f(0.8f, 0.1f, 0.2f);
	eyecircle(0.3,0.9);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.7,-11.2,0);
    glColor3f(0.6f, 0.1f, 0.3f);
	eyecircle(0.3,0.9);
	glPopMatrix();


	//$$$$$$$$$$$$$$$$$$$$4

	  //leftbuilding

	   //matha
	    glPushMatrix();
      glTranslatef(1.0,-16.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);

      glColor3f(1.0f, 0.0f, 0.22f);
      glVertex2f( -18.0,  25.0f);
     // glColor3f(1.0f, 0.4f, 0.78f);
      //glVertex2f( -20.0f,  12.0f);
      glColor3f(1.0f, 0.0f, 0.22f); //Yellow
      glVertex2f(-18.5f, 20.0f);
      glColor3f(1.0f, 0.1f, 0.99f);
      glVertex2f( -17.5f, 20.0f);

      glEnd();
	  glPopMatrix();

	  //body
      glPushMatrix();
      glTranslatef(0.0,-16.0,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.34f); //Yellow
      glVertex2f(-18.0f, 22.0f);
      glColor3f(1.0f, 0.0f, 0.32f);
      glVertex2f( -16.0f, 22.0f);
      glColor3f(0.7f, 0.0f, 0.93f);
      glVertex2f( -13.0,  12.0f);
      glColor3f(0.7f, 0.0f, 0.99f);
      glVertex2f( -21.0f,  12.0f);
      glEnd();
	  glPopMatrix();

	  //inner body

	  glPushMatrix();
      glTranslatef(-0.5,-15.9,0);
     // glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.22f, 0.0f, 0.74f); //Yellow
      glVertex2f(-17.0f, 20.0f);
      glColor3f(0.22f, 0.0f, 0.92f);
      glVertex2f( -16.0f, 20.0f);
      glColor3f(0.33f, 0.02f, 0.55f);
      glVertex2f( -15.0,  14.0f);
      glColor3f(0.55f, 0.22f, 0.44f);
      glVertex2f( -18.0f,  14.0f);
      glEnd();
	  glPopMatrix();

	  //building er nicher dome
    glPushMatrix();
	glTranslatef(-16.96,-3.9,0);
	 glRotatef(180.0, 0.0, 0.0, 1.0);
    glColor3f(0.38f, 0.16f, 0.86f);
	halfcircle(4.0,4.0);
	glPopMatrix();

	//nicher square

	 glPushMatrix();
      glTranslatef(-33.5,10.5,0);
     glRotatef(180.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.2f, 0.0f, 0.74f); //Yellow
      glVertex2f(-17.0f, 20.0f);
      glColor3f(0.5f, 0.0f, 0.92f);
      glVertex2f( -16.0f, 20.0f);
      glColor3f(0.3f, 0.02f, 0.55f);
      glVertex2f( -15.0,  18.0f);
      glColor3f(0.1f, 0.22f, 0.44f);
      glVertex2f( -18.0f,  18.0f);
      glEnd();
	  glPopMatrix();

	  //final quad nicher

	  glPushMatrix();
      glTranslatef(0.0,-27.52,0);
      glRotatef(0.0, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.5f, 0.0f, 0.34f); //Yellow
      glVertex2f(-17.5f, 18.0f);
      glColor3f(0.5f, 0.0f, 0.32f);
      glVertex2f( -16.5f, 18.0f);
      glColor3f(0.5f, 0.0f, 0.3f);
      glVertex2f( -15.0,  14.0f);
      glColor3f(0.2f, 0.0f, 0.78f);
      glVertex2f( -19.0f,  14.0f);
      glEnd();
	  glPopMatrix();

	  //***************************************

	//Alien er head
      glPushMatrix();
      glTranslatef(0.0,1.0,0);
      glRotatef(spinhead, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.7f, 1.0f, 0.0f); //Yellow
      glVertex2f(-3.5f, 4.0f);
      glVertex2f( 3.5f, 4.0f);
      glVertex2f( 2.3,  -3.0f);
      glVertex2f( -2.3f,  -3.0f);
      glEnd();
	  glPopMatrix();

//alien er left eye
    glPushMatrix();
	glTranslatef(-1.4,2.2,0);
    glColor3f(0.1f, 0.6f, 0.9f);
	eyecircle(0.7,0.7);
	glPopMatrix();

	//alien er right eye
    glPushMatrix();
	glTranslatef(1.4,2.2,0);
    glColor3f(0.1f, 0.6f, 0.9f);
	eyecircle(0.7,0.7);
	glPopMatrix();

    //alien er shing
     glPushMatrix();
    glColor3f(0.1, 0.6, 0.9);
    glTranslatef(-17.0,-10.09,0);
   // glRotatef(spinhead, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(19, 20);
    glVertex2i(15, 20);
    glVertex2i(17, 17);
    glEnd();
    glPopMatrix();

     //alien er lej
    glPushMatrix();
    glTranslatef(-14.99,-12.0,0);
    //glRotatef(spinhead, 0.0, 0.0, 1.0);
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(15, 17.0);
    glVertex2i(15, 19.23);
    //glVertex2i(330, 273);
    //glVertex2i(450, 273);
    glEnd();
    glPopMatrix();

    //points

    glPushMatrix();
    glColor3f(0.3, 0.7, 0.9);
    glTranslatef(-33.0,-28.0,0);
    glPointSize(12);
    glBegin(GL_POINTS);
    glVertex2i(16, 16);
    glEnd();
    glPopMatrix();


	  //alien er lips
	  glPushMatrix();
      glTranslatef(0.0,-0.5,0);
      glRotatef(spinhead, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.5f, 0.0f); //Yellow
      glVertex2f(-1.0f, 0.9f);
      glVertex2f( 1.0f, 0.9f);
      glVertex2f( 1.0,  -0.9f);
      glVertex2f( -1.0f,  -0.9f);
      glEnd();
	  glPopMatrix();

      //alien er neck
	  glPushMatrix();
      glTranslatef(0.0,1.0,0);
      glRotatef(spinhead, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.88f, 0.77f);
     // glColor3f(0.8f, 0.4f, 0.7f); //Yellow
      glVertex2f(-0.8f, -3.0f);
      glVertex2f( 1.0f, -3.0f);
      glVertex2f( 1.0f,  -8.0f);
      glVertex2f( -0.8f,  -8.0f);
      glEnd();
	  glPopMatrix();

	   //left leg
	  glPushMatrix();
      glTranslatef(1.2,1.0,0);
       glRotatef(spin1, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.2f, 1.0f, 0.9f); //Yellow
      glVertex2f(-4.3f, -12.0f);
      glColor3f(0.0f, 0.33f, 0.77f);
      glVertex2f( -2.0f, -12.0f);
      glColor3f(0.0f, 0.88f, 0.77f);
      glVertex2f( -2.3f,  -20.0f);
      glColor3f(0.0f, 0.66f, 0.77f);
      glVertex2f( -4.0f,  -20.0f);
      glEnd();
	  glPopMatrix();

	   //right leg
	  glPushMatrix();
      glTranslatef(-1.2,1.0,0);
       glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      // glColor3f(0.7f, 1.0f, 0.0f);
      glColor3f(0.2f, 1.0f, 0.9f); //Yellow
      glVertex2f(4.3f, -12.0f);
      glColor3f(0.0f, 0.33f, 0.77f);
      glVertex2f( 2.0f, -12.0f);
      glColor3f(0.0f, 0.88f, 0.77f);
      glVertex2f( 2.3f,  -20.0f);
      glColor3f(0.0f, 0.66f, 0.77f);
      glVertex2f( 4.0f,  -20.0f);
      glEnd();
	  glPopMatrix();

	    //left toe
	  glPushMatrix();
      glTranslatef(1.2,1.0,0);
       glRotatef(spin1, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
       //glColor3f(0.9f, 0.8f, 0.5f);
      glColor3f(0.9f, 1.0f, 0.0f);
     // glColor3f(0.1f, 0.6f, 0.9f); //Yellow
      glVertex2f( -2.3f,  -20.0f);
      glVertex2f( -4.0f,  -20.0f);
      glVertex2f(-4.8f, -22.0f);
      glVertex2f( -2.8f, -22.0f);
      glEnd();
	  glPopMatrix();

	    //right toe
	  glPushMatrix();
      glTranslatef(-1.2,1.0,0);
       glRotatef(spin, 0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.9f, 1.0f, 0.0f);
     // glColor3f(0.1f, 0.6f, 0.9f); //Yello
      glVertex2f( 2.3f,  -20.0f);
      glVertex2f( 4.0f,  -20.0f);
      glVertex2f(4.8f, -22.0f);
      glVertex2f( 2.8f, -22.0f);
      glEnd();
	  glPopMatrix();

	   //left arm
	  glPushMatrix();
      glTranslatef(0.4,0.8,0);
      glRotatef(spinhand, 0.0, 0.0, 1.0);
      //glRotatef(spin1, 0.0, 1.0, 0.0);
      //glRotatef(spin2, 1.0, 1.0, 1.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.88f, 0.77f);
      //glColor3f(0.0f, 1.0f, 0.5f); //Yellow
      glVertex2f(-6.0f, -9.0f);
      glColor3f(0.0f, 0.66f, 0.77f);
      glVertex2f( 0.0f, -7.0f);
      glColor3f(0.0f, 0.44f, 0.87f);
      glVertex2f( -1.0f,  -9.0f);
      glVertex2f( -6.0f,  -11.0f);
      glEnd();
	  glPopMatrix();

	  //left kobzi
     glPushMatrix();
     glRotatef(spinhand, 0.0, 0.0, 1.0);
    // glColor3f(0.9f, 1.0f, 0.0f);
    glColor3f(0.1, 0.4, 0.7);
    glTranslatef(11.4,0.8,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-19, -10);
    glVertex2i(-17, -9);
    glVertex2i(-17, -11);
    glEnd();
    glPopMatrix();


      //right arm
      glPushMatrix();
      glTranslatef(-2.9,-12.6,0);
      glRotatef(spinhand, 0.0, 0.0, 1.0);
    //  glRotatef(spin, 0.0, 0.0, 1.0);
     // glRotatef(180.0, 0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);
      glColor3f(0.0f, 0.88f, 0.77f); //Yellow
      glVertex2f(4.0f, 4.0f);
      glColor3f(0.0f, 0.33f, 0.77f);
      glVertex2f( 9.0f, 6.0f);
      glColor3f(0.0f, 0.55f, 0.77f);
      glVertex2f( 10.3f,  9.0f);
      glColor3f(0.0f, 0.88f, 0.77f);
      glVertex2f( 4.0f,  5.5f);

      glEnd();
	  glPopMatrix();

	/*    //right kobzi
     glPushMatrix();
     glRotatef(spinhand, 0.0, 0.0, 1.0);
    // glRotatef(180.0, 0.0, 0.0, 1.0);
    glColor3f(0.1, 0.4, 0.7);
     glTranslatef(-2.5,-12.6,0);
   // glTranslatef(20.9,4.7,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(9, 6);
    glVertex2i(11, 9);
    glVertex2i(7.8, 7.9);
    glEnd();
    glPopMatrix();*/

	    //body
	  glPushMatrix();
      glTranslatef(0.0,1.0,0);
      glBegin(GL_POLYGON);
      glColor3f(0.99f, 0.11f, 0.22f); //Yellow
      glVertex2f(-1.5f, -5.0f);
      glColor3f(0.99f, 0.11f, 0.5f);
      glVertex2f( 1.5f, -5.0f);
      glColor3f(0.55f, 0.11f, 0.5f);
      glVertex2f( 5.0f,  -15.0f);
      glColor3f(0.55f, 0.11f, 0.99f);
      glVertex2f( -5.0f,  -15.0f);
      glEnd();
	  glPopMatrix();

	    //inner square
	  glPushMatrix();
      glTranslatef(0.0,-0.7,0);
      glBegin(GL_POLYGON);
      glColor3f(0.02f, 0.6f, 0.9f); //Yello
      glVertex2f( -1.9f,  -6.8f);
      glVertex2f( 1.7f,  -6.8f);
      glColor3f(0.02f, 0.2f, 0.9f);
      glVertex2f(1.7f, -11.5f);
      glVertex2f( -1.9f, -11.5f);
      glEnd();
	  glPopMatrix();

	   if(p<=8.0)
        p=p+0.00233;

    else
        p=-20;
        p=p+0.007;

     /*    if(p1<=8.0)
        p1=p1+0.00233;

   else
        p1=-20;
        p1=p1+0.007;

          if(q<=8.0)
        q=q+0.00233;

    else
        q=-20;
        q=q+0.007;*/

    //glutPostRedisplay();

	  //spaceship er halfcircle

    glPushMatrix();
	glTranslatef(-18.0,17.0,0);
    glColor3f(0.5f, 0.6f, 0.9f);
	circle(3,4);
	glPopMatrix();

	//innerhalfcircle
	glPushMatrix();
	glTranslatef(-18.0,17.0,0);
    glColor3f(1.0f, 0.6f, 0.9f);
	circle(2,2);
	glPopMatrix();

	//bomb
	glPushMatrix();
	//glTranslatef(-18.0,16.0,0);
	glTranslatef(-19.5,-35.0,0);
    glColor3f(0.1f, 0.53f, 0.77f);
	bomb(2.3,1.8);
	glPopMatrix();

    glColor3f(0.9, 0.8, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(20.0+x, 20.0+y);
    glVertex2f(20.0+x, 18.0+y);
    glVertex2f(20.0+x,19.0+y);
    glVertex2f(20.5+x, 19.0+y);
    glVertex2f(20.5+x, 20.0+y);
    glVertex2f(20.5+x, 18.0+y);
    glVertex2f(21.0+x, 20.0+y);
    glVertex2f(21.0+x, 18.0+y);
    glEnd();

	//space ship er body

	  glPushMatrix();
      glTranslatef(-2.0,0.3,0);
      glBegin(GL_POLYGON);
      glColor3f(0.5f, 0.1f, 0.6f); //Yello
      glVertex2f( -19.0f+p,  17.0f+p);
      glColor3f(0.6f, 0.1f, 0.6f);
      glVertex2f( -13.0f+p,  17.0f+p);
      glColor3f(0.7f, 0.1f, 0.6f);
      glVertex2f(-11.5f+p, 14.0f+p);
      glColor3f(0.8f, 0.1f, 0.6f);
      glVertex2f( -20.5f+p, 14.0f+p);
      glEnd();
	  glPopMatrix();

//uuuuuuuuuuuuuuuuuuuuffffffffffffffffffffooooooooooooo

  //spaceship er halfcircle

    glPushMatrix();
    glTranslatef(13.99,17.0,0);
    glColor3f(0.8f, 0.6f, 0.9f);
	ufocircle(3,4);
	glPopMatrix();

	//space ship er body

	  glPushMatrix();
      glTranslatef(30.0,0.3,0);
      glBegin(GL_POLYGON);
      glColor3f(0.5f, 0.1f, 0.6f); //Yello
      glVertex2f( -19.0f+u,  17.0f+f);
      glColor3f(0.6f, 0.1f, 0.6f);
      glVertex2f( -13.0f+u,  17.0f+f);
      glColor3f(0.7f, 0.1f, 0.6f);
      glVertex2f(-11.5f+u, 14.0f+f);
      glColor3f(0.8f, 0.1f, 0.6f);
      glVertex2f( -20.5f+u, 14.0f+f);
      glEnd();
	  glPopMatrix();

      glPushMatrix();
      glTranslatef(30.0,0.3,0);
      glBegin(GL_POLYGON);
      glColor3f(0.7f, 0.5f, 0.0f); //Yello
      glVertex2f( -19.0f+u1,  14.0f+f1);
      glColor3f(0.6f, 0.5f, 0.0f);
      glVertex2f( -13.0f+u1,  14.0f+f1);
      glColor3f(0.99f, 0.22f, 0.0f);
      glVertex2f(-12.5f+u1, -8.0f+f1);
      glColor3f(0.99f, 0.22f, 0.0f);
      glVertex2f( -19.5f+u1, -8.0f+f1);
      glEnd();
	  glPopMatrix();




	glFlush();
}
void spinDisplay_left(void)
{
   spin = spin + 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reset(void)

{
    spin=0.0;
    spin1=0.0;
    spinhead=0.0;
    spinhand=0.0;
    glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
	//glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

void throwlight()
{
     //glColor3f(0.0f, 1.0f, 0.0f);
    spin1 = spin1 + 1;
   if (spin1 > 360.0)
      spin1 = spin1 - 360.0;
   glutPostRedisplay();
}

void throwbomb()
{

        p1=34.5;
        q=26.5;
        x=-13.7;
        y=-19.2;
        PlaySound("strings2", NULL, SND_FILENAME| SND_ASYNC);

   glutPostRedisplay();
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'b':
             throwbomb();
			//spinDisplay_left();
			break;

		case 'r':

			reset();
			break;

        case 'd':

			doggy();
			break;

        case 'f':

			moveufo();
			break;
        case 's':
             glutIdleFunc(NULL);
			 break;


	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(movehead);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(reset);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}

int main()
{
   // PlaySound("strings3", NULL, SND_FILENAME| SND_ASYNC);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Alien Dance");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutMouseFunc(my_mouse);
    glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}
