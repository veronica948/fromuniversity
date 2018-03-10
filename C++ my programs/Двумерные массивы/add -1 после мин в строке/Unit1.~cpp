#include<iostream.h>
#include<stdlib.h>
int main()
{ int const N=5;
  int const M=4;
  int a[N+1][M];
 randomize();
 for(int i=0;i<N;i++)
{       for(int j=0;j<M;j++)
        {a[i][j]=random(100);
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}
cout<<endl;

//add -1 after min;
 for(int i=0;i<M;i++)
{int k=0;
 for(int j=0;j<N;j++)
        if(a[j][i]<a[k][i]) k=j;
 for(int t=N;t>k+1;t--)
 a[t][i]=a[t-1][i];
 a[k+1][i]=-1;
}



 for(int i=0;i<N+1;i++)
{       for(int j=0;j<M;j++)
        {
        cout.width(3);
        cout<<a[i][j]<<' '; }
cout<<endl;
}

system("pause");
return 0;
}