#include<iostream.h>
int main()
{
 int n,x;
 for(x=1000;x<=9999;x++)
 { n=x;
 while(n)
 {
 if((n%10==2)|| (n%10==0)||(n%10==3)||(n%10==7)) n=n/10;
 else break;
  }
 if(!n) cout<<x<<endl;
 }
 system("pause");
 return 0;
 }