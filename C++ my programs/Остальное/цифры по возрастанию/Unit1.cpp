#include<iostream.h>
#include<stdlib.h>
int f(int a);
int main()
{ int const N=10;
  int n=10000;
  int a[N];

  for(int i=0;i<N;i++)
  {a[i]=random(n);
  cout<<a[i]<<' ';
  }
  cout<<endl;

  for(int i=0;i<N;i++)
  {a[i]=f(a[i]);
  cout<<a[i]<<' ';}

  system("pause");
  return 0;
  }

int f(int a)
{ int A[100],k=0,n=0,x,p;

for(int i=0;a!=0;i++,a/=10)
{ A[i]=a%10; k++;}

int t=k;
while(t)
{ p=0;

for(int j=0;j<t-1;j++)
if(A[j]>A[p]) p=j;
 x=A[p];
 A[p]=A[t-1];
 A[t-1]=x;
 t--;
 }

 for(int i=0;i<k;i++)
 n=n*10+A[i];
 return n;
 }




