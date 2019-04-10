#include "includes.h"
#include "prototypes.h"

void lighting(){


	GLfloat light_position[] = {0.0, 0.0, 5.0, 1.0}; 
    GLfloat ambient[] = {.5, .5, .5, 1.0}; //adjust this to adjust intensity of light

	glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ambient);

	glEnable(GL_LIGHTING);
   	glEnable(GL_LIGHT0);



}
