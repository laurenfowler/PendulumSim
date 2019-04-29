#include "prototypes.h"
#include "includes.h"
#include <stdio.h>
#include <math.h>
#define Nstep 1000000

// These two functions are the first and second derivative equations
// to be used in the Runge-Kutta method for the dynamical motion of the pendulum 

double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   extern double kick;
   cout << kick << endl;

   static double R = 1.00;  // Length of pendulum  (meters)
   static double g = 9.80;  // Normalized gravitational constant  (m/s^2)
   static double b = 0.1;  // Frictional damping constant
   static double m = 1.00;  // Mass in normalized gravitational units (kg)
   static double A = kick;  // Amplitude of initial driving force (kick)
   static double k = 0.10;  // Frequency parameter of initial driving force (when we kick it)

   cout << A << endl;

   double num, denom;

   num = -b*omega + A*cos(k*t);
   denom = m*R*R;
   // To test limiting case of small theta, use following line of code
   //return -g/R*theta;


   return (-g/R*sin(theta)+num)/denom; //equation accounts for damping and kicking

}


// This is the function that actually propagates the motion 

void step(double *t, double *theta, double *omega )
{
   extern long int period_frames;
   extern double curr_t, prev_t;
   extern float desired_fps;
   extern bool omega_neg;
   extern int curr_period;
   extern double prev_o, curr_o;
  // Time step variables
  double dt, h; 
  // variables for fourth-order Runge-Kutta method
  double k1, k2, k3, k4, j1, j2, j3, j4;
  extern char *desiredString;
  extern bool arg;

	period_frames++;

	h=10000.0/Nstep;   // Try changing the value of Nstep above to see what happens 

      // Fourth-Order Runge-Kutta propagation step for second order dynamical systems
        k1 = thetadot(*t, *theta, *omega); 
        j1 = omegadot(*t, *theta, *omega); 
        k2 = thetadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1); 
        j2 = omegadot(*t+h/2, *theta+h/2*k1, *omega+h/2*j1); 
        k3 = thetadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2); 
        j3 = omegadot(*t+h/2, *theta+h/2*k2, *omega+h/2*j2); 
        k4 = thetadot(*t+h, *theta+h*k3, *omega+h*j3); 
        j4 = omegadot(*t+h, *theta+h*k3, *omega+h*j3); 
        *theta = *theta + h/6*(k1+2*k2+2*k3+k4);
        *omega = *omega + h/6*(j1+2*j2+2*j3+j4);
        *t = *t + h;
	
		curr_o = *omega;	

		if((prev_o > 0.0) && (curr_o <= 0.0)){
			curr_t = *t - prev_t;
			curr_period = glutGet(GLUT_ELAPSED_TIME);
			if(!arg){
				desired_fps = period_frames/curr_t;
				sprintf(desiredString, "Desired FPS: %6.1f", desired_fps);
			}
			else{
				float tmp = period_frames/curr_t;	
				sprintf(desiredString, "Desired FPS: %6.1f", tmp);
			}	

			omega_neg = 1;
			checkPeriodFrames();
			prev_t = *t;
		}

		
		prev_o = curr_o;
}

/*int main(int argc, char** argv)
{

   double t=0.0;
   double theta=M_PI/4.0;
   double omega=0.0; //initial velocity

   for (long i=0; i<2*Nstep; i++ ) {
      printf("%f %f %f\n", t, theta, omega);
      step( &t, &theta, &omega);
   } 
}*/
