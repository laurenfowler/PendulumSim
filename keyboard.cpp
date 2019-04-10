#include "includes.h"
#include "prototypes.h"


void keyboard(unsigned char key, int x, int y){
	extern double camX, camY, camZ;
	extern double centerX, centerY, centerZ;
	extern double rot;

	switch(key){
		case 'w':
			//camX = camX + 0.1;
			//centerX = centerX + 0.1;
			forward();
			break;
		case 's':
			//camX = camX - 0.1;
			//centerX = centerX - 0.1; 
			backward();
			break;
		case 'a':
			//camY = camY + 0.1;
			//centerY = centerY + 0.1;
			left();
			break;
		case 'd':
			//camY = camY - 0.1;
			//centerY = centerY - 0.1;
			right();
			break;
		case 'q':
			exit(0);
			break; 
		case 'r':
			camX = -3.0;
			camY = 0.0;
			camZ = 1.0;
			centerX = 0.0;
			centerY = 0.0;
			centerZ = 1.0;
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
            udrot = -1.0;
            updown--;
            if(updown > -89 && updown <= 89){
                up_down();
            }
            else{
                updown = -89;
            }
            break;
        case(GLUT_KEY_DOWN):
            udrot = 1.0;
            updown++;
            if(updown >= -89 && updown < 89){
                up_down();
            }
            else{
                updown= 89;
            }
            break;    

		/*case(GLUT_KEY_UP):
			centerZ = centerZ + 1.0;
			if(centerZ > 90.0){
				centerZ = 90.0;
			}
			break;
		case(GLUT_KEY_DOWN):
			centerZ = centerZ - 1.0;
			if(centerZ < -90.0){
				centerZ = -90.0;
			}
			break;
		case(GLUT_KEY_LEFT):
			centerY = centerY - 1.0;
			if(centerY < -90.0 ){
				centerY = -90.0;
			} 
			break; 
		case(GLUT_KEY_RIGHT):
			centerY = centerY + 1.0;
			if(centerY > 90.0){
				centerY = 90.0;
			}
			break; */
		default:
			break;
	}

}

/*case 'w':
			camR = camR - 0.1;
			if(camR <= 0){
				camR = 0.0;
			}
			break;
		case 's':
			camR = camR + 0.1;
			if(camR >= 30){
				camR = 30.0;
			}
			break;
		case 'a':
			camP = camP - 1.0;
			if(camP < 0){
				camP = camP + 360.0;
			}
			break;
		case 'd':
			camP = camP + 1.0;
			if(camP > 360.0){
				camP = camP - 360.0;
			}
			break; */

