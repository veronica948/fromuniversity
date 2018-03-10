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
int sum1=0,sum2=0;
 for(int i=0;i<N;i++)
 sum1+=a[i][i];
 cout<<"sum gl="<<sum1<<endl;

 for(int i=0;i<N;i++)
 sum2+=a[N-1-i][i];
  cout<<"sum pob="<<sum2<<endl;

 int sum3=0;
 for(int i=0,j=0;j<M;j++)
 sum3+=a[i][j];
 cout<<"sum 0str="<<sum3<<endl;

system("pause");
return 0;
}
