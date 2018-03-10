#include<iostream.h>
int main()
{
 int n,k=0,r=0,s=0;
 cout<<"Enter number"<<endl;
 cin>>n;
 int t=n;
 int g=n;
 // The number of 1
 while(n)
 { int p=n&1;
   if(p)
   k++;
   n>>=1;
 }
// The number of F
while(t)
{int p=t&0x000F;
  if(p==0x000F)
   r++;
   t>>=4;
}
//The number of bites
 while(g)
 { int p=g&1;
   if(p)
   s++;
   g>>=8;
 }

cout<<"The number of 1="<<k<<endl<<"The number of F="<<r<<endl<<"The number of bites="<<s<<endl;
system("pause");
return 0;
}
