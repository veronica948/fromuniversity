#include<iostream.h>
#include<stdlib.h>
int main()
{int const N=10;
 int a[N+1],x,i,n=100,k=0;
   for(i=0;i<N;i++)
   a[i]=random(n);

  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }

  for(i=0;i<N;i++)
  if(a[i]>a[k]) k=i;

  for(i=N;i>=k+1;i--)
  a[i]=a[i-1];

  a[k+1]=100;

  for(i=0;i<N+1;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }
   
  system("pause");
  return 0;
 }
 