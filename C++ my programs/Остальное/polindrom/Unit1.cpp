#include<iostream.h>
int f(int &a);
int main()
{
int const N=5;
int a[N];

for(int i=0;i<N;i++)
cin>>a[i];

for(int i=0;i<N;i++)
 if(f(a[i])) cout<<a[i]<<"-polindrom"<<endl;
  else     cout<<a[i]<<"-ne polindrom"<<endl;

system("pause");
return 0;
}

int f(int &a)
{
 int obr=0;
 int t=a;
 while(t)
 { obr=obr*10+t%10;
   t=t/10;
 }
 if(a==obr) return 1;
 else return 0;
 }

