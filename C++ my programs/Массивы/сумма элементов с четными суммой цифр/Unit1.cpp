#include<iostream.h>
int main()
{int const N=10;
 int a[N],x,i,n=100,sum=0;
   for(i=0;i<N;i++)
   a[i]=random(n);

  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]=";
  cout<<a[i]<<" "; }

  for(i=0;i<N;i++)
  { int s=0;
   x=a[i];
  while(x)
  { s=s+x%10; x=x/10; }
  if(!(s%2))
  sum=sum+a[i];
  }

  system("pause");
  return 0;
 }
