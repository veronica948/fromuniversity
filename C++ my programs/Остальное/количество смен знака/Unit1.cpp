#include<iostream.h>
#include<stdlib.h>
int main()
{ int const N=10;
  int a[N],x,i,k=0,p=0;
   for(i=0;i<N;i++)
   cin>>a[i];

   for(i=0;i<N;i++)
   if(a[i]) {k=i; break;}

  for(i=k+1;i<N;i++)
  if(a[i])
   if(a[k]*a[i]<0)
    { p++;
      k=i;}

  cout<<"kolichestvo smen znaka="<<p<<endl;
  system("pause");
  return 0;
  }
