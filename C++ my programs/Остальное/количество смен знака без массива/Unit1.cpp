#include<iostream.h>
#include<stdlib.h>
int main()
{  int n,t=0,p=0;
   cout<<"enter the numbers, the last=100"<<endl;

   while(1)

   {cin>>n;

   if(n==100) {
   if(n*t<0) p++;
   break;}

   if(n)

   {if(n*t<0)
   p++;
   t=n;
   }
   }
   cout<<"kolichestvo smen znaka="<<p<<endl;

   system("pause");
   return 0;
 }

