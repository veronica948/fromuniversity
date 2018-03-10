#include<iostream.h>
#include<math.h>
int main()
{const int N=5;
 const int M=8;
int x, a[N],b[M],c[M];
cout<<"Enter coefficients of the first; The number of them="<<N<<endl;
 for(int j=0;j<N;j++)
  cin>>a[j];
cout<<"Enter coefficients of the second polinomial; The number of them="<<M<<endl;
  for(int j=0;j<N;j++)
  cin>>b[j];
int p=M;
int i=0;
for(;p>N;p--,i++)
c[i]=b[i];

for(;i<M;i++)
    c[i]=a[i+N-M]+b[i];

for(int j=0;j<M;j++)
  switch(c[j]){
   case 1: cout<<'x'<<'^'<<(M-1-j); break;
   case -1: cout<<'-x'<<'^'<<(M-1-j); break;
   case 0:  ;
   default : cout<<c[j]<<'x'<<'^'<<(M-1-j); break;
   }

system("pause");
return 0;
}
