#include<iostream.h>
int main()
{
  int f=1,n;
  cout<<"Enter positive number"<<endl;
  cin>>n;
  for(int i=1;i<=n;i++)
  f=f*i;
  cout<<"factorial="<<f<<endl;
  system("pause");
  return 0;
}
