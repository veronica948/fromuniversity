#include<iostream.h>
#include<stdlib.h>
int f(int &a);
int main()

{for(int i=100;i<=999;i++)
 if(f(i)) cout<<i<<"Yes"<<" ";
 else  cout<<i<<"No"<<" ";
 system("pause");
 return 0;
}

int f(int &a) {
int x=a;
while(x)
{
int t=x%10;
if(t)
if(!(a%t)) return 1;
x=x/10;
}
return 0;
}
