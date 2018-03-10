#include<iostream.h>
int main()
{ int const N=10;
  int a[N],min,max,i;
  for(i=0;i<N;i++)
  {cout<<"a["<<i<<"]="<<endl;
  cin>>a[i]; }
  min=a[0];
  max=a[0];
  for(i=0;i<N;i++)
  { if(a[i]>max) max=a[i];
    if(a[i]<min) min=a[i];
    }
  cout<<"min="<<min<<endl;
  cout<<"max="<<max<<endl;
  system("pause");
  return 0;
}

