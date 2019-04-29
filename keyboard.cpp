#include "includes.h"
#include "prototypes.h"


void keyboard(unsigned char key, int x, int y){
	extern double camX, camY, camZ;
	extern double centerX, centerY, centerZ;
	extern double rot;
	extern bool draw_physics;
	extern double kick;
    extern vector<vector<float>> graph;

	switch(key){
        case 'c':
            graph.clear();
            break;
		case 'k':
			kick = 0.5;
			break;
		case 'w':
			forward();
			break;
		case 's':
			backward();
			break;
		case 'a':
			left();
			break;
		case 'd':
			right();
			break;
		case 'q':
			exit(0);
			break; 
		case 'r':
			camX = -3.0;
			camY = 0.0;
			camZ = 1.0;
			centerX = 1.0;
			centerY = 0.0;
			centerZ = 1.0;
			break;
		case 'g':
			if(draw_physics){
				draw_physics = false;
			}
			else{
				draw_physics = true;
			}
		default:
			break;
	}

}

void processSpecialKeys(int key, int x, int y){
	extern double camX, camY, camZ;
	extern double centerX, centerY, centerZ;
	extern double rot, udrot;
    static int updown=0;


	switch(key){

		case(GLUT_KEY_LEFT):
			rot = 1.0; 
			rotateAround();
			break;
		case(GLUT_KEY_RIGHT): 
			rot = -1.0; //rot - 1.0;
			rotateAround();
			break;
		case(GLUT_KEY_PAGE_UP):
			camZ = camZ + 0.1;
			centerZ = centerZ + 0.1;
			break;
		case(GLUT_KEY_PAGE_DOWN):
			camZ = camZ - 0.1;
			centerZ = centerZ - 0.1;
			break;
        case(GLUT_KEY_UP):
			centerZ = centerZ + 0.1;
            break;
        case(GLUT_KEY_DOWN):
			centerZ = centerZ - 0.1;
            break;    
		default:
			break;
	}

}

