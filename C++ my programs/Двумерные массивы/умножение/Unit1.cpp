#include<iostream.h>
#include<stdlib.h>
int main()
{ int const N=5,M=3,K=4;
  int a[N][M],b[M][K],c[N][K];
  for(int i=0;i<N;i++)
   {for(int j=0;j<M;j++)
    {a[i][j]=random(10);
    cout.width(4);
    cout<<a[i][j];
    }
    cout<<endl;
   }
   cout<<endl;

  for(int i=0;i<M;i++)
   {for(int j=0;j<K;j++)
    {b[i][j]=random(10);
    cout.width(4);
    cout<<b[i][j];
    }
    cout<<endl;
   }
   cout<<endl;


   for(int i=0;i<N;i++)
     for(int j=0;j<K;j++)
       {c[i][j]=0;
       for(int t=0;t<M;t++)
       c[i][j]+=a[i][t]*b[t][j];
       }

    for(int i=0;i<N;i++)
   {for(int j=0;j<K;j++)
    {
    cout.width(4);
    cout<<c[i][j];
    }
    cout<<endl;
   }






   system("pause");
   return 0;
}
