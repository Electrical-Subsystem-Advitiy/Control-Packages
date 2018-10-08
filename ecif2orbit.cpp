#include <iostream>
#include <cmath>
using namespace std;
float dot(float a[], float b[],int n) //dot product
{
  float s=0;
  for(int i=0;i<n;i++)
   s+=(a[i]*b[i]);
  return(s);
} 
float norm(float a[],int n)
{
  float s=0;
  for(int i=0;i<n;i++)
   s+=(a[i]*a[i]);
  return(sqrt(s));
}
float *cross(float a[],float b[])  //cross product
{
  static float c[3] ;
  c[0]=(a[1]*b[2])-(b[1]*a[2]);
  c[1]=(a[2]*b[0])-(b[2]*a[0]);
  c[2]=(a[0]*b[1])-(b[0]*a[1]);
  return c;
}
float *ecif2orbit(float v_pos_i[],float v_vel_i[],float v_x_i[])
{
  float x[3],y[3],z[3];
  float n=norm(v_pos_i,(sizeof(v_pos_i)/sizeof(v_pos_i[0])));
  for(int i=0;i<3;i++)
     z[i]=-1*v_pos_i[i]/n;
  float *c=cross(v_vel_i,v_pos_i);
  n=norm(c,sizeof(c)/sizeof(c[0]));
  for(int i=0;i<3;i++)
     y[i]=c[i]/n;
  c=cross(y,z);
  n=norm(c,sizeof(c)/sizeof(c[0]));
  for(int i=0;i<3;i++)
     x[i]=c[i]/n;
  static float v_x_o[3];
  v_x_o[0]=dot(x,v_x_i,(sizeof(x)/sizeof(x)));
  v_x_o[1]=dot(y,v_x_i,(sizeof(y)/sizeof(y)));
  v_x_o[2]=dot(z,v_x_i,(sizeof(z)/sizeof(z)));
  return v_x_o;
}
int main() {
	// your code goes here
	float v_x_i[]={-2.3,0,0.5};
	float v_pos_i[]={-2,0,0.84};
	float v_vel_i[]={-2,0.5,0};
    float *v_x_o=ecif2orbit(v_pos_i,v_vel_i,v_x_i);
	for(int i=0;i<3;i++)
	 cout<<v_x_o[i]<<" ";
}
