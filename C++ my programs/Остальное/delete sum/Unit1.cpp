#include<iostream.h>
int s(int a)
{ int s=0;
  while(a)
  { s=s+a%10;
    a/=10;
  }
  return s;
}

int main()
{ int const N=10;
  int a[N];
  for(int i=0;i<N;i++)
  cin>>a[i];

  int R=N;
   for(int i=0;i<R;i++)
   if(s(a[i])>10)   { for(int j=i;j<R-1;j++)
                      a[j]=a[j+1];
                      i--;
                      R--;
                    }

  for(int i=0;i<R;i++)
  cout<<a[i]<<" ";

  system("pause");
  return 0;
}
