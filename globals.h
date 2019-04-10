#ifndef GLOBALS
#define GLOBALS

double t = 0.0;
double theta = M_PI/4.0;
double omega = 0.0; //initial velocity
unsigned frames = 0;
char *charString = (char*) malloc(12*sizeof(char));
bool omega_neg = 0;
double curr_o;
char *periodString = (char*) malloc(12*sizeof(char));
char *desiredString = (char*) malloc(12*sizeof(char));
double prev_o = -0;
int prev_period = 0;
int curr_period;
long int period_frames;
bool count = 1;
char *actualPeriod = (char*) malloc(12 * sizeof(char));
double prev_t = 0;
double curr_t;
float desired_fps;
bool arg = 0;

double camX = -3.0;
double camY = 0.0;
double camZ = 1.0;
double rot = 0.0;
double udrot = 0.0;

double centerX = 1.0;
double centerY = 0.0;
double centerZ = 1.0;
double speed = 0.3;
double X = 0.0;
double Y = 0.0;

GLuint textureID[5];

#endif
