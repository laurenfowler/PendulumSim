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

	camX = camX + (dirX * speed);
	camY = camY + (dirY * speed);
	camZ = camZ + (dirZ * speed);

	centerX = centerX + (dirX * speed);
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

	centerX = centerX + (dirX * speed);
	centerY = centerY + (dirY * speed);
	centerZ = centerZ + (dirZ * speed);

}

void left(){
	double dirX, dirY, dirZ;
	double crossX, crossY, crossZ;
	double upX = 0.0;
	double upY = 0.0;
	double upZ = 1.0;

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

	crossX = (dirY*upZ) - (dirZ*upY);
	crossY = (dirX*upZ) - (dirZ*upX);
	crossZ = (dirX*upY) - (dirY*upX);

	camX = camX - (crossX*speed);
	camY = camY - (crossY*speed);
	camZ = camZ - (crossZ*speed);

	centerX = centerX - (crossX*speed);
	centerY = centerY - (crossY*speed);
	centerZ = centerZ - (crossZ*speed);

	cout << camX << " " << camY << " " << camZ << endl;	
}

void right(){
	double dirX, dirY, dirZ;
	double crossX, crossY, crossZ;
	double upX = 0.0;
	double upY = 0.0;
	double upZ = 1.0;

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

	crossX = (dirY*upZ) - (dirZ*upY);
	crossY = (dirX*upZ) - (dirZ*upX);
	crossZ = (dirX*upY) - (dirY*upX);

	camX = camX - (crossX*speed);
	camY = camY - (crossY*speed);
	camZ = camZ - (crossZ*speed);

	centerX = centerX - (crossX*speed);
	centerY = centerY - (crossY*speed);
	centerZ = centerZ - (crossZ*speed);

	cout << camX << " " << camY << " " << camZ << endl;
}

