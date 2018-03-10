#include<iostream.h>
int main()
{ const int N=10;
 int a[N]={1,4,4,5,5,5,1,4,8,1};
 int r,t,p,s;
 int k=0;
  for(int i=0;i<N;i++)
   cout<<a[i]<<' ';
   cout<<endl;


 for(int i=0;i<N;i++)
  {if((a[i]!=a[i-1])&&(a[i]==a[i+1])) t=i;
  if((a[i]==a[i-1])&&(a[i]!=a[i+1])) {r=i;

  if((r-t)>k)  {k=r-t;
                p=t;
                s=r;
                }
  }
  }
  int b=s-p+1;
  int d=b;
for(;b;b--)
for(int j=p;j<N;j++)
a[j]=a[j+1];

 for(int i=0;i<N-d;i++)
   cout<<a[i]<<' ';
system("pause");
return 0;
}
