#include<iostream.h>
#include<stdlib.h>
int main()
{int const N=10;
 int a[N],x,i,n=100,k;
   for(i=0;i<N;i++)
   a[i]=random(n);

  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }

  k=a[N-1];

  for(i=N-1;i>=0;i--)
  a[i]=a[i-1];

  a[0]=k;

  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }
   
  system("pause");
  return 0;
 }
 