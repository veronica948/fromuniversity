#include<iostream.h>
#include<math.h>
int main()
{
const int N=5;
const int M=5;
int a[N]={1,2,3,5,6},b[M]={0,3,5,6,8},c[M+N];
int k=0,i=0,j=0;
 for(;(i<N)&&(j<M);k++)
  if(a[i]<b[j]) {c[k]=a[i];  i++;}
  else {c[k]=b[j]; j++;}
if(N>M)
        for(int m=i;k<(N+M);m++,k++)
        c[k]=a[m];
else    for(int t=j;k<(N+M);t++,k++)
        c[k]=b[t];

for(int n=0;n<N+M;n++)
cout<<c[n]<<' ';
system("pause");
return 0;
}
