#ifndef PROTOTYPES
#define PROTOTYES

void init(void);
void reshape(int w, int h);
void display(void);
void step(double *t, double *theta, double *omega);
double thetadot(double t, double theta, double omega);
double omegadot(double t, double theta, double omega);
void call_step(void);
void checkFPS(int val);
void checkPeriodFrames();
void glutSleep(int millisecondsToWait);
void glutLockFrameRate(float desiredFrameRate);
void draw_room();
void draw_pendulum();
void draw_table();
void keyboard(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void loadTextures();
void rotateAround();
void forward();
void backward();
void left();
void right();
void lighting();
void up_down();
#endif
