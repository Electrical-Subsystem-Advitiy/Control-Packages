#include <iostream>
#include<cmath>
using namespace std;
const float initialdelay=1208719.0;//The time from equinox and the initial time (launch) in seconds
const float pi=3.14159265359;
float norm(float a[],int n)  //magnitude
{
  float s=0;
  for(int i=0;i<n;i++)
   s+=(a[i]*a[i]);
  return(sqrt(s));
}
float *sunmodel(float T)
{
float t_day=(T+initialdelay)/86400;//The time passed from equinox till each point in orbit in days
float theta=(2*pi*t_day)/365.256363;//Angle between intermediate frame (s) and (epsilon) frame about common z-axis
float epsilon=23.45*pi/180;//Angle between rotation axis and orbital plane normal
float x,y,z;
x=cos(theta);//#components as got from document referred
y=sin(theta)*cos(epsilon);
z=sin(theta)*sin(epsilon);
static float v_sun_i[3]={x,y,z};
float n=norm(v_sun_i,sizeof(v_sun_i)/sizeof(v_sun_i[0]));
for(int i=0;i<3;i++)
  v_sun_i[i]=v_sun_i[i]/n;
return v_sun_i;//sun vector in ECI Frame
}
int main() {
	// your code goes here
	float T=6.00E-01;
	float* v_sun_i=sunmodel(T);
	for(int i=0;i<3;i++)
	  cout<<v_sun_i[i]<<" ";
}
