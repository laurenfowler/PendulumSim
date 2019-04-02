#include "includes.h"
#include "prototypes.h"

void drawString(GLuint x, GLuint y, void *font, const char* string){
	const char *c;
	glRasterPos2i(x, y);
	for(c=string; *c!='\0'; c++){
		glutBitmapCharacter(font, *c);
	}
}

void display(void){

	extern double theta;
	extern unsigned frames;
	extern long int period_frames;
	extern char *charString, *periodString;	
	extern bool count, omega_neg;
	//extern double camR, camP, camT;
	extern double centerX, centerY, centerZ;
	extern double camX, camY, camZ;
	extern double rot;
	double X, Y;
	frames++;

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

	// We are going to set our position to be down the Y-Axis looking at the
	// center of the coordinate frame.  The positive Z-Axis will be up.
	
//	gluLookAt( 8.0,   -6.0, 2.0,  // Eye

	//calculate eye
/*	float eyeX = camR*sin(camT*M_PI/180.0)*cos(camP*M_PI/180.0);
	float eyeY = camR*sin(camT*M_PI/180.0)*sin(camP*M_PI/180.0);
	float eyeZ = camR*cos(camT*M_PI/180.0);

	float hypot = 4.0;
	float X = eyeX + 4.0;
	float Y = cos(centerY*M_PI/180.0)*hypot;
	float Z = sin(centerZ*M_PI/180.0)*hypot;

	gluLookAt(eyeX, eyeY, eyeZ,
		centerX, centerY, centerZ,  // Center
		0.0,   0.0, 1.0); // Up */

	X = (centerX * cos(rot * 3.14/180.0)) + (centerY * -sin(rot * 3.14/180.0));
	Y = (centerX * sin(rot * 3.14/180.0)) + (centerY * cos(rot * 3.14/180.0));
	X = X + camX; //this is so it adds the eye position and rotates around it properly
	Y = Y + camY;

	double cX = camX + cos(rot);
	double cY = camY + sin(rot);

	gluLookAt(camX, camY, camZ,
			  X, Y, 1.0,
			  0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0,1.0,0.0);


	glBegin(GL_LINES);
	glVertex3f(0.0, -4.0, 0.0); //y - green
	glVertex3f(0.0, 4.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -4.0); //z - red
	glVertex3f(0.0, 0.0, 4.0);

	glColor3f(0.0, 0.0, 1.0);   // x - blue
	glVertex3f(4.0, 0.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glEnd(); 

	//draw pendulum
	glPushMatrix();
		draw_pendulum();
	glPopMatrix();

	//draw table
	glPushMatrix();
		glTranslated(-0.7, 0.0, -0.7);
		glScalef(1.5, 1.5, 1.5);
		draw_table();
	glPopMatrix();

	//draw room
	glPushMatrix();
		glTranslated(0.0, 0.0, 1.6);
		glScalef(5.0, 6.0, 4.0);
		draw_room();
	glPopMatrix(); 


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	extern char *actualPeriod;
	extern char *desiredString;

	glColor3f(255, 255, 0);
	drawString(50, 50, GLUT_BITMAP_HELVETICA_12, charString);
	drawString(50, 40, GLUT_BITMAP_HELVETICA_12, periodString);
	drawString(50, 30, GLUT_BITMAP_HELVETICA_12, actualPeriod);
	drawString(50, 20, GLUT_BITMAP_HELVETICA_12, desiredString);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glFlush();

	extern float desired_fps; //caculated in physics
	glutLockFrameRate(desired_fps); 
	glutSwapBuffers();
}

void glutLockFrameRate(float desiredFrameRate){

	int millisecondsToWait = (int) (1.0/desiredFrameRate * 1000);
	int startTime = glutGet(GLUT_ELAPSED_TIME);

	do{
		
	}
	while((glutGet(GLUT_ELAPSED_TIME)-startTime)<millisecondsToWait);


}

void checkFPS(int val){
	//cout << "in checkFPS" << endl;
	extern unsigned frames;
	extern long int period_frames;
	extern char *charString, *periodString, *actualPeriod; 
	static float fps; 
	extern bool omega_neg;
	extern int prev_period;
	extern int curr_period;
	extern double prev_o, curr_o;
	extern double curr_t;

	float time;

	//sprintf(charString, "FPS: %6.1f", frames);
	fps = (float) frames;
	
	if( 0!= val){
		sprintf(charString, "FPS: %6.1f", fps);
	}

	if(omega_neg){
		extern bool count;
		count = 1;
		time = curr_period - prev_period;
		time = (time/1000);
		sprintf(actualPeriod, "Actual: %6.1f", (float) curr_t);
		omega_neg = 0;
	}

	frames = 0;
	glutTimerFunc(1000, checkFPS, 1);

}

void checkPeriodFrames(){
	extern char *periodString;
	extern long int period_frames;

        sprintf(periodString, "FPP: %6.1f", (float) period_frames);
		period_frames = 0;

}
