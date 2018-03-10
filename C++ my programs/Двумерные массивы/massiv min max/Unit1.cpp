#include<iostream.h>
int main()
{  const int N=3;
   const int M=3;
int a[N][M];
int max[M],min[M];
int k=0,t=0;
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}

int l=0,d=0;
for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
       {if(a[i][j]>a[i][k]) k=j;
        if(a[i][j]<a[i][t]) t=j;
        }
max[d]=a[i][k];
d++;
min[l]=a[i][t];
l++;
}

for(int i=0;i<d;i++)
cout<<max[i]<<' ';
cout<<endl;

for(int i=0;i<l;i++)
cout<<min[i]<<' ';
system("pause");
return 0;
}
