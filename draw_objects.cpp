#include "includes.h"
#include "prototypes.h"

void draw_table(){
	glColor3f(1.0, .98431373, .09803922);
	
	#ifdef LIGHTING
		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat diffuseMaterial[4] = {1.0, 1.0, 1.0, 1.0};

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_specular);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif

	//draw top of table
	glPushMatrix();
		glRotated(45.0, 0.0, 0.0, 1.0);
		gluCylinder(gluNewQuadric(), 
				   (GLdouble) 1.0, 
				   (GLdouble) 1.0, 	
				   (GLdouble) 0.1, 
				   (GLint)      4,
				   (GLint)     20);
	glPopMatrix();

	#ifdef LIGHTING

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif

	glColor3f(1.0, .5, 1.0);
	glPushMatrix();
		glTranslated(0.0, 0.0, 0.1);
		glScalef(.71, .71, 0.0);
		glBegin(GL_POLYGON);
			glVertex3d(1.0, 1.0, 0.0);
			glVertex3d(-1.0, 1.0, 0.0);
			glVertex3d(-1.0, -1.0, 0.0);
			glVertex3d(1.0, -1.0, 0.0);
		glEnd();
		
	glPopMatrix(); 

	#ifdef LIGHTING

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif


	glColor3f(1.0, .98431373, .09803922);
	//draw stand
	glPushMatrix();
		glTranslated(0.0, 0.0, -1.0);
		gluCylinder(gluNewQuadric(),
				   (GLdouble) 0.05,
				   (GLdouble) 0.05,
				   (GLdouble)  1.0,
				   (GLint)      20,
				   (GLint)      20);
	glPopMatrix();

	#ifdef LIGHTING

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif


	//draw base
	glPushMatrix();
		glTranslated(0.0, 0.0, -1.0);
		gluCylinder(gluNewQuadric(),
				   (GLdouble)  0.5,
				   (GLdouble) 0.05,
				   (GLdouble)  0.2,
				   (GLint)      20,
				   (GLint)      20);
	glPopMatrix();
	
	#ifdef LIGHTING
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	#endif

}

void draw_room(){

	#ifdef TEXTURE
	extern GLuint textureID[5];
	glEnable(GL_TEXTURE_2D);
	#endif

	#ifdef LIGHTING
		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat diffuseMaterial[4] = {0.5, 0.5, 0.5, 1.0};

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif

	
	glColor3ub(25, 189, 255); //blue

	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	#endif

	//back
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0,  1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f(-1.0,  1.0, -1.0);
		glEnd();
	glPopMatrix();

	glColor3ub(163, 25, 214); //purple
	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	#endif

	//front
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(1.0, -1.0,  1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f(1.0,  1.0,  1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f(1.0,  1.0, -1.0);
		glEnd();
	glPopMatrix();

	glColor3ub(156, 237, 154); //light green
	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	#endif

	//left
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, -1.0,  1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f( 1.0, -1.0,  1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
		glEnd();
	glPopMatrix();

	glColor3ub(247, 172, 42); //orange
	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	#endif

	//right
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(-1.0, 1.0,  1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f( 1.0, 1.0,  1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f( 1.0, 1.0, -1.0);
		glEnd();
	glPopMatrix();

	glColor3ub(247, 79, 42); //red orange

	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	#endif

	//top 
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(-1.0,  1.0, 1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f( 1.0,  1.0, 1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f( 1.0, -1.0, 1.0);
		glEnd();
	glPopMatrix();
		
	glColor3ub(165, 58, 90); //maroon-y

	#ifdef TEXTURE
	glColor3ub(255, 255, 255); 
	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	#endif

	//bottom
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
			glTexCoord2d(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
			glTexCoord2d(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
		glEnd();
	glPopMatrix();
}

void draw_pendulum(){

	extern double theta;

	#ifdef LIGHTING
		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat diffuseMaterial[4] = {1.0, 1.0, 1.0, 1.0};

		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseMaterial);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

	#endif

	//draw a cylinder
	glPushMatrix();
    glColor3f (0.0,0.0,1.0);
	glTranslated(0.0, 0.0, 1.0);
	glRotated(180, 0.0, 1.0, 0.0);
	glRotated((double) 180*theta/M_PI, 1, 0, 0);
	glRotated((double)180*theta/M_PI, 0, 0, 1);
    gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05,
            (GLdouble) 0.05,
            (GLdouble) 1.0,
            (GLint)    20,
            (GLint)    20 );
			//draw sphere
			glPushMatrix();
			glColor3f(.905882353, 1.0, .607843137);
			glTranslated(0.0, 0.0, 1.0);
			glScaled(0.15, 0.15, 0.15);
			gluSphere(gluNewQuadric(),
					 (GLdouble) 1.5,
					 (GLint)     10,
					 (GLint)     10);
			glPopMatrix();

    glPopMatrix();

	//draw armature 
	glPushMatrix();
	glColor3f(.88235294, .67843137, 1.0);
	glTranslated(0.0, 0.0, .95);
	glRotated(-90, 0.0, 1.0, 0.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05,
            (GLdouble) 0.05,
            (GLdouble) 1.0,
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();

	//draw stand
	glPushMatrix();
	glColor3f(.60784314, 1.0, .85490196);
	glTranslated(-1.0, 0.0, -0.55);
	//glTranslated(-.866025404, 0.0, 0.0);
	//glTranslated(0.0, 0.5, 0.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 0.05,
            (GLdouble) 0.05,
            (GLdouble) 1.5,
            (GLint)    20,
            (GLint)    20 );
	glPopMatrix();

	//draw base
	glPushMatrix();
	glColor3f(1.0, .77254902, .529411765);
	glTranslated(-.8, 0.0, -0.55);
	glRotated(45, 0.0, 0.0, 1.0);
	gluCylinder(gluNewQuadric(),
            (GLdouble) 1.0,
            (GLdouble) 1.0,
            (GLdouble) .25,
            (GLint)    4,
            (GLint)    20 );
	glPopMatrix();
 
	//draw top
	glPushMatrix();
	glTranslated(-.8, 0.0, -.3);
		glBegin(GL_POLYGON);
			glVertex3f(-.71, -.71, 0);
			glVertex3f(.71, -.71, 0);
			glVertex3f(.71, .71, 0);
			glVertex3f(-.71, .71, 0);	
		glEnd();
	glPopMatrix(); 


}
