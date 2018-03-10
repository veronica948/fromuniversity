#include<iostream.h>
#include<stdlib.h>
int main()
{  const int N=5;
   const int M=6;
int a[N][M];
randomize();
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
for(int i=0;i<M;i++)
{a[2][i]=0; a[N-1][i]=0;}
cout<<endl;
int K=N;
for(int i=0;i<K;i++)
{int f=1;
{for(int p=0;p<M;p++)
if(a[i][p]!=0) f=0;
 if(f)
 {for(int j=0;j<M;j++)
  {int x=a[i][j];
  a[i][j]=a[K-1][j];
  a[K-1][j]=x;
}
K--;i--;
}
}
}
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}

system("pause");
return 0;
}
