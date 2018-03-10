#include<iostream.h>
int main()
{const int N=10;
int a[N]={1,3,5,3,5,8,6,3,0,4};
int p=N; 
for(int i=0;i<N;i++)
     {int f=0;
     for(int j=i+1;j<N;j++)
     if(a[i]==a[j]) f=1;
          if(f) p--;

      }    

cout<<"The number of different numbers="<<p<<endl;
system("pause");
return 0;
}
 