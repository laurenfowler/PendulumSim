#include "includes.h"
#include "prototypes.h"

void draw_table(){
	glColor3f(1.0, .98431373, .09803922);
	//glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
	#ifdef LIGHTING
    glEnable(GL_COLOR_MATERIAL);
    GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_amb_diff[] = {1.0, 0.98, 0.09, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	#endif

	//draw top of table
		glRotated(45.0, 0.0, 0.0, 1.0);
		gluCylinder(gluNewQuadric(), 
				   (GLdouble) 1.0, 
				   (GLdouble) 1.0, 	
				   (GLdouble) 0.1, 
				   (GLint)      4,
				   (GLint)     20);

    glPopMatrix();

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
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

    

//	glColor3f(1.0, .98431373, .09803922);
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
    	glDisable(GL_COLOR_MATERIAL);
	#endif

}

void draw_room(){

	glColor3f(1.0, 1.0, 1.0);
	#ifdef LIGHTING
    //this declares material properties
    GLfloat mat_specular[] = {.5, .5, .5, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    //this enables already defined colors to be applied to ambient and diffuse
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
    #endif

	#ifdef TEXTURE
	extern GLuint textureID[5];
	glEnable(GL_TEXTURE_2D);
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

    #ifdef LIGHTING
        glDisable(GL_COLOR_MATERIAL);
    #endif

	
	#ifdef TEXTURE
	glDisable(GL_TEXTURE_2D);
	#endif

}

void draw_pendulum(){

	glColor3f(1.0, 1.0, 1.0);
	extern double theta;

	#ifdef LIGHTING
    //this declares material properties
    GLfloat mat_specular[] = {.5, .5, .5, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    //this enables already defined colors to be applied to ambient and diffuse
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
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
//	glColor3f(.60784314, 1.0, .85490196);
    // Changed color to green for testing
	glColor3f(0.0, 1.0, 0.0);
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

    #ifdef LIGHTING
        glDisable(GL_COLOR_MATERIAL);
    #endif

}

void draw_spotlight(){
	#ifdef LIGHTING
    glEnable(GL_COLOR_MATERIAL);
    GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_amb_diff[] = {1.0, 0.98, 0.09, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	#endif

	glColor3ub(244, 66, 119);
	gluCylinder(gluNewQuadric(),
			(GLdouble) 0.0,
			(GLdouble) 0.3,
			(GLdouble) 0.3,
			(GLint)    20,
			(GLint)    20);

	#ifdef LIGHTING
	glDisable(GL_COLOR_MATERIAL);
	#endif

}




