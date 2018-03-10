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

  cout<<"enter the place of number"<<endl;
  cin>>k;

  for(i=0;i<N-1;i++)
  a[k]=a[k+1];

  for(i=0;i<N-1;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }
   
  system("pause");
  return 0;
 }

