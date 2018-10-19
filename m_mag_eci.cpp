#include <iostream>
#include<cmath>
using namespace std;
float w_earth = 7.2921159*pow(10,-5);
float radians(float deg)
{
    float rad = deg*0.0174532925;
    return rad;
}
float dot(float a[3], float b[3])
{
    float res = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    return res;
}
float* ned2ecef(float* x, float lat, float lon)
{
    float v[3] = {-x[2], -x[0], x[1]};   // convert to spherical polar r theta phi
	float theta = -lat + 90;    // in degree, polar angle
	float phi = lon;          // in degree, azimuthal angle
	theta = radians(theta);
	phi = radians(phi);
	float DCM[3][3] = {{sin(theta)*cos(phi), cos(theta)*cos(phi), -sin(phi)}, {sin(theta)*sin(phi), cos(theta)*sin(phi), cos(phi)}, {cos(theta), -sin(theta), 0}}; //spherical to cartesian
	static float y[3];
    for(int i = 0; i<3; i++)
	    y[i] = dot(DCM[i],v);
	return y;
}
float* ecef2ecif(float* x, float t)
{
    float theta = w_earth*t;
	float DCM[3][3] = {{cos(theta), -1*sin(theta), 0}, {sin(theta), cos(theta),0}, {0,0,1}};
	static float y[3];
	for(int i = 0; i<3; i++)
	    y[i] = dot(DCM[i],x);
	return y;
}
float *m_mag_eci(float m_mag_ned[],float m_LLA[])
{
    float T=m_mag_ned[0];
    float c[3];
    for(int i=0;i<3;i++)
     c[i]=m_mag_ned[i+1];
    float *m_mag_ecef=ned2ecef(c,m_LLA[1],m_LLA[2]);
    static float m_mag_i[4];
    m_mag_i[0]=T;
    float *c1=ecef2ecif(m_mag_ecef,T);
    for(int i=1;i<4;i++)
      m_mag_i[i]=c1[i-1];
    return m_mag_i;
}
int main() {
	// your code goes here
	float m_mag_ned[5]={4E-01,1.92E04,-3.06E03,-8.64E03,2.12E04};
	float m_LLA[4]={4E-01,2.43E-02,-1.01E+01,7.0E+05};
	float* m_mag=m_mag_eci(m_mag_ned,m_LLA);
	for(int i=0;i<4;i++)
	  cout<<m_mag[i]<<" ";
}
