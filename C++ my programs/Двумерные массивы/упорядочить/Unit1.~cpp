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
cout<<endl;
int f=1;
while(f)
{ f=0;
for(int i=0;i<N-1;i++)

if(a[i][0]>a[i+1][0]) {f=1;
 for(int j=0;j<M;j++)
  {int x=a[i][j];
  a[i][j]=a[i+1][j];
  a[i+1][j]=x;
} }  }
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
//в каждой строке удалить последний максимальный элемент
//вставить в каждый столбец после первого мин элемента -1
