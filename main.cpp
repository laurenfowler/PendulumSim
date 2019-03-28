#include "includes.h"
#include "prototypes.h"
#include "globals.h"

int main(int argc, char** argv)
{
	extern bool arg;
	extern float desired_fps;
	if(argc > 1){
		arg = 1;
		desired_fps = atoi(argv[1]);
	}

    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
	glewInit();
    init ();
	loadTextures();
	glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutIdleFunc(call_step); 
    glutTimerFunc(0, checkFPS, 0);
	glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 300.0);
   glMatrixMode(GL_MODELVIEW);
}

