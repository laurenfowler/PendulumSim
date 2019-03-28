#include "includes.h"
#include "prototypes.h"


void call_step(void){

	extern double t, theta, omega;
	double t_tmp, theta_tmp, omega_tmp;

	t_tmp = t;
	theta_tmp = theta;
	omega_tmp = omega;

	step( &t_tmp, &theta_tmp, &omega_tmp);

	t = t_tmp;
	theta = theta_tmp;
	omega = omega_tmp;


	glutPostRedisplay();
}
