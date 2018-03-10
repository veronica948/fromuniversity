#include<iostream.h>
#include<math.h>
double exp(double x,double eps)
{int n=2;
 double s=0;
 double sl=1,f=-1;
 while(fabs(sl)>eps)
 {s+=sl;
 sl=sl*x*x*f/n;
 n+=2;
 f*=-1;
 }
 return s;
}
int main()
{double a,b,hx,eps;
cout<<"Enter a,b,hx and eps"<<endl;
cin>>a>>b>>hx>>eps;
for(double x=a;x<=b+hx;x=x+hx)
 cout<<x<<':'<<exp(x,eps)<<endl;


system("pause");
return 0;
}
 