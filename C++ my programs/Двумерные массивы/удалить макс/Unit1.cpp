#include<iostream.h>
#include<stdlib.h>
int main()
{ int const N=5;
  int const M=4;
  int a[N][M];

 for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
cout<<endl;

for(int i=0;i<N;i++)
{int k=0;
for(int j=0;j<M;j++)
        if(a[i][j]>=a[i][k]) k=j;
for(int t=k;t<M-1;t++)
a[i][t]=a[i][t+1];
}
 for(int i=0;i<N;i++)
{       for(int j=0;j<M-1;j++)
        {
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
system("pause");
return 0;
}