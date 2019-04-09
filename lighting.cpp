#include "includes.h"
#include "prototypes.h"

GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };

void lighting(){

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = {1.0, 1.0, 2.0, 1.0}; 
    GLfloat ambient[] = {.5, .5, .5, .5};
    GLfloat white[] = {1.0, 1.0, 1.0, 1.0};

	glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_SMOOTH);
   	glEnable(GL_DEPTH_TEST);
   	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
   	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   	glMaterialf(GL_FRONT, GL_SHININESS, 20.0);

   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glEnable(GL_LIGHTING);
   	glEnable(GL_LIGHT0);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
   	glEnable(GL_COLOR_MATERIAL);


}
