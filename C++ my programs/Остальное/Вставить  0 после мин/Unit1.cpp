#include<iostream.h>
int main()
{ int const N=10;
int a[2*N],i,j;

for(i=0;i<N;i++)
cin>>a[i];

int min=a[0];
for(i=0;i<N;i++)
if(a[i]<min) min=a[i];

 int R=N;
 for(i=0;i<R;i++)
 if(a[i]==min)   {for(j=R;j>i+1;j--)
                   a[j]=a[j-1];
                   a[i+1]=0;
                   i++;
                   R++;
                   }

 for(i=0;i<R;i++)
 cout<<a[i]<<" ";

 system("pause");
 return 0;
 }
