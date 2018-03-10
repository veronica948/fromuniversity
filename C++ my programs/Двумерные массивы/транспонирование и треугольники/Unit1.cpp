#include<iostream.h>
#include<stdlib.h>
int main()
{ int const N=5;
  int a[N][N];
  for(int i=0;i<N;i++)
   {for(int j=0;j<N;j++)
    {a[i][j]=random(100);
    cout.width(4);
    cout<<a[i][j];
    }
    cout<<endl;
   }
   //нижний треугольник
    for(int i=0;i<N;i++)
   {for(int j=0;j<i;j++)
     {cout.width(4);  cout<<a[i][j]; }
    cout<<endl;
   }
   cout<<endl;
   //верхний треугольник
  for(int i=0;i<N;i++)
   {for(int j=0;j<N;j++)
   { if(j>i){
    cout.width(4);
    cout<<a[i][j]; }
    else for(int b=4;b;b--)
         cout<<' ';  }
    cout<<endl;
    }

  cout<<endl;
  //транспонирование
   for(int i=0;i<N;i++)
   for(int j=i+1;j<N;j++)
    {int x=a[i][j];
    a[i][j]=a[j][i];
    a[j][i]=x;
    }

     for(int i=0;i<N;i++)
   {for(int j=0;j<N;j++)
    {
    cout.width(4);
    cout<<a[i][j];
    }
    cout<<endl;
   }

   system("pause");
   return 0;
}
