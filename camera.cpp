#include "includes.h"
#include "prototypes.h"

extern double camX, camY, camZ, centerX, centerY, centerZ;
extern double rot;
extern double speed;
extern double X, Y;

void rotateAround(){	
	double dirX, dirY, dirZ, rotX, rotY;
	dirX = centerX - camX;
	dirY = centerY - camY;
	dirZ = centerZ - camZ;

	//cout << dirX << " " << dirY << " " << dirZ << endl;

	dirX = (dirX * cos(rot * 3.14/180.0)) + (dirY * -sin(rot * 3.14/180.0));
	dirY = (dirX * sin(rot * 3.14/180.0)) + (dirY * cos(rot * 3.14/180.0));

	X = X + camX;
	Y = Y + camY;
	//Z = Z + camZ;

	centerX = dirX + camX;
	centerY = dirY + camY;
	centerZ = dirZ + camZ;

}

void forward(){
	double dirX, dirY, dirZ;
	
	//calculate directional vector
	dirX = centerX - camX;
    dirY = centerY - camY;
    dirZ = centerZ - camZ;

	//normalize the vector
    double magnitude = sqrt((dirX*dirX) + (dirY*dirY) + (dirZ*dirZ));
    if(magnitude != 0){
        dirX = dirX/magnitude;
        dirY = dirY/magnitude;
        dirZ = dirZ/magnitude;
    }

	camX = camZ + (dirX * speed);
	camY = camY + (dirY * speed);
	camZ = camZ + (dirZ * speed);

	centerX = centerZ + (dirX * speed);
	centerY = centerY + (dirY * speed);
	centerZ = centerZ + (dirZ * speed);

}

void backward(){
	double dirX, dirY, dirZ;
	
	//calculate directional vector
	dirX = centerX - camX;
    dirY = centerY - camY;
    dirZ = centerZ - camZ;

	//normalize the vector
    double magnitude = sqrt((dirX*dirX) + (dirY*dirY) + (dirZ*dirZ));
    if(magnitude != 0){
        dirX = dirX/magnitude;
        dirY = dirY/magnitude;
        dirZ = dirZ/magnitude;
    }

	camX = camX - (dirX * speed);
	camY = camY - (dirY * speed);
	camZ = camZ - (dirZ * speed);

	centerX = centerZ + (dirX * speed);
	centerY = centerY + (dirY * speed);
	centerZ = centerZ + (dirZ * speed);

}


/*void calc_camera(char key, double &camX, double &camZ, double &camY, double &centerX, double &centerY, double &centerZ){

	extern double rot;
	double X, Y, Z;

	X = (centerX * cos(rot * 3.14/180.0)) + (centerY * -sin(rot * 3.14/180.0));
    Y = (centerX * sin(rot * 3.14/180.0)) + (centerY * cos(rot * 3.14/180.0));
    X = X + camX; //this is so it adds the eye position and rotates around it properly
    Y = Y + camY;
    Z = 1.0;

	//calculate directional vector
	double dirX = X - camX;
    double dirY = Y - camY;
    double dirZ = Z - camZ;

	//normalize the vector
    double magnitude = sqrt((dirX*dirX) + (dirY*dirY) + (dirZ*dirZ));
    if(magnitude != 0){
        dirX = dirX/magnitude;
        dirY = dirY/magnitude;
        dirZ = dirZ/magnitude;
    }

    double speed = 0.3;
	double crossX = (dirY*1.0) - (dirZ*0.0);
    double crossY = (dirX*1.0) - (dirZ*0.0);
    double crossZ = (dirX*0.0) - (dirY*0.0);

    camX = camX + (dirX * speed) + (crossX * speed);
    camY = camY + (dirY * speed) + (crossY * speed);
    camZ = camZ + (dirZ * speed) + (crossZ * speed);

    X = X + (dirX * speed) + (crossZ * speed);
    Y = Y + (dirY * speed) + (crossY * speed);
    Z = Z + (dirZ * speed) + (crossZ * speed);

	centerX = X;
	centerY = Y;
	centerZ = Z;

}*/



