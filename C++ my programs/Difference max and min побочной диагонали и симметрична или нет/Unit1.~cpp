#include<iostream.h>
#include<stdlib.h>
int main()
{  const int N=5;

int a[N][N];
randomize();
for(int i=0;i<N;i++)
{       for(int j=0;j<N;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
//difference between max and min
int max=a[0][N-1];
int min=a[0][N-1];
for(int i=0;i<N;i++)
{ if(a[i][N-1-i]>max) max=a[i][N-1-i];
  if(a[i][N-1-i]<min) min=a[i][N-1-i];
}
int dif=max-min;
cout<<"difference="<<dif<<endl;

//симметрична или нет
int f=1;
for(int i=0;i<N;i++)
  for(int j=i+1;j<N;j++)
  if(a[i][j]!=a[j][i])
    { f=0; break;}
if(f) cout<<"Yes"<<endl;
else   cout<<"No"<<endl;



system("pause");
return 0;
}
 