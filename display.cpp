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

	extern vector<vector<float>> graph;
	extern double theta, omega;
	extern unsigned frames;
	extern long int period_frames;
	extern char *charString, *periodString;	
	extern bool count, omega_neg;
	extern double camX, camY, camZ, centerX, centerY, centerZ;
	extern double X, Y;
	frames++;

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

	// We are going to set our position to be down the Y-Axis looking at the
	// center of the coordinate frame.  The positive Z-Axis will be up.
	
	gluLookAt(camX, camY, camZ,
			  centerX, centerY, centerZ,
			  0.0, 0.0, 1.0); 

	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0,1.0,0.0);

	#ifdef LIGHTING
	lighting();
	#endif


	//direction of light
	/*glPushMatrix();
		glBegin(GL_LINES);
		glVertex3f(1.5, -1.5, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glEnd();
	glPopMatrix(); */

	glPushMatrix();
		glTranslated(0.0, 0.0, 5.0);
		glutWireCube(0.1);
	glPopMatrix();

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
		glTranslated(0.0, 0.0, 3.8);
		glScalef(10.0, 9.0, 6.0);
		draw_room();
	glPopMatrix(); 

	//draw spotlight
	glPushMatrix();
		glTranslated(1.5, -1.5, 1.0);
		draw_spotlight();
	glPopMatrix();


	//disable lighting so it does not affect
	//ortho projection
	#ifdef LIGHTING
	glDisable(GL_LIGHTING);
	#endif

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	extern char *actualPeriod;
	extern char *desiredString;

	glColor3f(255, 255, 255);
	drawString(50, 50, GLUT_BITMAP_HELVETICA_12, charString);
	drawString(50, 40, GLUT_BITMAP_HELVETICA_12, periodString);
	drawString(50, 30, GLUT_BITMAP_HELVETICA_12, actualPeriod);
	drawString(50, 20, GLUT_BITMAP_HELVETICA_12, desiredString);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	extern bool draw_physics;

	if(draw_physics){
			glMatrixMode(GL_PROJECTION);
			//physics display
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();

				glPushMatrix();
					glColor3f(0.0, 0.0, 0.0);
					//draw axes
					glBegin(GL_LINE_STRIP);
						glVertex2d(790.0, 220.0);
						glVertex2d(790.0, 40.0);
						glVertex2d(975.0, 40.0);
					glEnd();

					vector<vector<float>> :: iterator it;
					//erase value so it keeps putting in new points
					if(graph.size() == 2500){
						it = graph.begin();
						graph.erase(it);
					}

					vector <float> points;
					calc_points(points, theta, omega);
					graph.push_back(points);

					glBegin(GL_POINTS);
					for(it = graph.begin(); it != graph.end(); it++){
						points = *it;
						glVertex2f(points.at(0), points.at(1));
					}
					glEnd();

					glColor3f(1.0, 1.0, 1.0);
					glRecti(750.0, 0.0, 1000.0, 250.0);
				glPopMatrix();
			
			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
	}


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
	extern double kick;

	float time;

	//sprintf(charString, "FPS: %6.1f", frames);
	fps = (float) frames;
	
	if( 0!= val){
		sprintf(charString, "FPS: %6.1f", fps);
	}

	//one period
	if(omega_neg){
		kick = 0.2;
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
