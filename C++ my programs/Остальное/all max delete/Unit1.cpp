#include<iostream.h>
#include<stdlib.h>
int main()
{int const N=10;
 int a[N],x,i,n=100,k=0,max,p;

   for(i=0;i<N;i++)
   a[i]=random(n);
    a[3]=86;
  for(i=0;i<N;i++)
  cout<<a[i]<<" ";
  cout<<endl;

  max=a[0];
  for(i=0;i<N;i++)
  if(a[i]>max) max=a[i];

  int R=N;
  for(i=0;i<R;i++)
  if(a[i]==max) {
  p=i;  i--;
  for(int j=p;j<R;j++)
  a[j]=a[j+1];
  R--; }

  for(i=0;i<R;i++)
  cout<<a[i]<<" ";
   
  system("pause");
  return 0;
 }
