#include <iostream>
#include <cmath>
using namespace std;
//n=size of a and b[Do by "sizeof(a)/sizeof(a[0])"]
float dot(float a[], float b[],int n) //dot product
{
  float s=0;
  for(int i=0;i<n;i++)
   s+=(a[i]*b[i]);
  return(s);
} 
float *cross(float a[],float b[])  //cross product
{
  static float c[3] ;
  c[0]=(a[1]*b[2])-(b[1]*a[2]);
  c[1]=(a[2]*b[0])-(b[2]*a[0]);
  c[2]=(a[0]*b[1])-(b[0]*a[1]);
  return c;
}
float norm(float a[],int n)  //magnitude
{
  float s=0;
  for(int i=0;i<n;i++)
   s+=(a[i]*a[i]);
  return(sqrt(s));
}
float *quatMultiplyUnnorm(float v_q1[], float v_q2[])  //quaternion multiply
{
 float v_b1[3],v_b2[3];
  for(int i=0;i<3;i++)
  {
      v_b1[i]=v_q1[i];
      v_b2[i]=v_q2[i];
  } 
  float a1=v_q1[3];
  float a2=v_q2[3];
  float a=(a1*a2)-dot(v_b1,v_b2,sizeof(v_b1)/sizeof(v_b1[0]));
  float *c=cross(v_b1,v_b2);
  static float v_q[4];
  for(int i=0;i<3;i++)
   v_q[i]=(a1*v_b2[i])+(a2*v_b1[i])-c[i];
  v_q[3]=a;
  return v_q;
}
int main()
{ 
  float v_q1[]={-1.5,2,3,4};
  float v_q2[]={2.78,1.9,4.1,3};
  float *c=quatMultiplyUnnorm(v_q1,v_q2);
  for(int i=0;i<4;i++)
   cout<<c[i]<<" ";
}