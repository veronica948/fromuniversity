#include<iostream.h>
int main()
{ int const N=10;
  int a[N],x,i;
  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]="<<endl;
  cin>>a[i]; }
  for(i=0;i<N;i=i+2)
  { x=a[i];
    a[i]=a[i+1];
    a[i+1]=x;
   }
   for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]="<<a[i]<<endl;
   }
  system("pause");
  return 0;
}

