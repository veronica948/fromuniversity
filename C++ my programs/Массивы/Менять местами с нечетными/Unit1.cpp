#include<iostream.h>
int main()
{ int const N=9;
  int a[N],x,i,y;
  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]="<<endl;
  cin>>a[i]; }
   if(N%2) y=a[N-1];
  for(i=0;i<N;i=i+2)
  { x=a[i];
    a[i]=a[i+1];
    a[i+1]=x;
   }
   if(N%2) a[N-1]=y;
   for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]="<<a[i]<<endl;
   }
  system("pause");
  return 0;
}

