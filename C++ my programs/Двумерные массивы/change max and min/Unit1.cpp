#include<iostream.h>
#include<stdlib.h>
int main()
{  const int N=3;
   const int M=3;
int a[N][M];
randomize();
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
int r=0,k=0,s=0,t=0;
for(int i=0;i<N;i++)
       for(int j=0;j<M;j++)
       {if(a[i][j]>a[r][k]) {r=i; k=j;}
        if(a[i][j]<a[s][t]) {s=i; t=j;}
        }
int x=a[r][k];
    a[r][k]=a[s][t];
    a[s][t]=x;

for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}


system("pause");
return 0;
}
