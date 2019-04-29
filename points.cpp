#include "includes.h"
#include "prototypes.h"

void calc_points(vector<float> &points, float x, float y){
	float gXmin = 0.0;
	float gXmax = 1000.0;
	float gYmin = 0.0;
	float gYmax = 1000.0;

	float vXmin = 750.0;
	float vXmax = 1000.0;
	float vYmin = 0.0;
	float vYmax = 250.0;

	float fXmin = -2.0;
	float fXmax = 2.0;
	float fYmin = -5.0;
	float fYmax = 5.0;

	x = gXmin + vXmin + ((x-fXmin)/(fXmax - fXmin)) * (vXmax - vXmin);
	y = gYmin + vYmin + ((y-fYmin)/(fYmax - fYmin)) * (vYmax - vYmin);
	points.push_back(x);
	points.push_back(y);

//	cout << x << " " << y << endl;
}
