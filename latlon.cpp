#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979323846;//constant value
int sgn(float x)//sign function
{
    if(x<0)
     return -1;
    else if
     return 1;
    else
     return 0;
}
void latlon(float v_x[], float &lat,float&lon)
{
   lat=sgn(v_x[2])*(acos(sqrt(((v_x[0]*v_x[0]) + (v_x[1]*v_x[1])))/sqrt(((v_x[0]*v_x[0]) + (v_x[1]*v_x[1]) + (v_x[2]*v_x[2])))))*(180/pi); 
   if(v_x[1]==0)
		if(v_x[0]>=0)
			lon = 0.0;
		else
			lon = 180.0;
   else
		lon = sgn(v_x[1])*acos(v_x[0]/sqrt(((v_x[0]*v_x[0]) + (v_x[1]*v_x[1]))))*(180/pi);
}
int main() {
	// your code goes here
	float v_x[3]={-2,0,0};
	float lon,lat;
	lon=lat=0.0;
	latlon(v_x,lat,lon);  //implementation
	cout<<lat<<" "<<lon;
}