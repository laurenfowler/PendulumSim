#include "includes.h"
#include "prototypes.h"

void lighting(){
	glColor3f(1.0, 1.0, 1.0);
	//glDisable(GL_COLOR_MATERIAL);

	GLfloat light_position[] = {0.0, 0.0, 5.0, 1.0}; 
    GLfloat ambient[] = {.4, .4, .4, 1.0}; //adjust this to adjust intensity of light

	//glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		

   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ambient);

	//add a spotlight
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 30.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);

	float *light1 = (float *) malloc(4*sizeof(float));
	light1[0] = 1.5; light1[1] = -1.5; light1[2] = 1.0; light1[3] = 1.0;
	glLightfv(GL_LIGHT1, GL_POSITION, light1);

	light1[0]= 0.0; light1[1] = 0.0; light1[2]=0.0; light1[3] = 1.0;
   	glLightfv(GL_LIGHT1, GL_AMBIENT, light1);
   	light1[0]= 0.5; light1[1] = 0.5; light1[2]= 0.5; light1[3] = 1.0;
   	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1);
   	glLightfv(GL_LIGHT1, GL_SPECULAR, light1);

	float *direction = (float *) malloc(4*sizeof(float));
	direction[0] = -1.5; direction[1] = 1.5; direction[2] = -1.0;
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);


	glEnable(GL_LIGHTING);
   	//glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);



}
