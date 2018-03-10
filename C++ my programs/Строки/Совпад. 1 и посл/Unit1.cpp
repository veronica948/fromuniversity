#include<iostream.h>
#include<string.h>
#include<stdlib.h>
int main()
{int const N=100;
char s[N];
gets(s);
int p=strlen(s);
for(int i=p;i>0;i--)
s[i]=s[i-1];
s[0]=' ';
s[p+1]=' ';
s[p+2]='\0';
p=p+2;

int k,r;
for(int i=0;i<p-1;i++)
 {if((s[i]==' ')&&(s[i+1]!=' ')) k=i+1;
  if((s[i]!=' ')&&(s[i+1]==' ')) {r=i;  break;}
  }
int t,f;
for(int i=p-1;i>0;i--)
  {if((s[i]==' ')&&(s[i-1]!=' ')) t=i-1;
  if((s[i]!=' ')&&(s[i-1]==' ')) {f=i;  break;}
  }
cout<<k<<' '<<r<<' '<<f<<' '<<t;

int d=1;
for(int i=k,j=f;(i<=r)&&(j<=t);i++,j++)
 if(s[i]!=s[j]) {d=0; break;}
if(d) cout<<endl<<"Yes";
else cout<<endl<<"No";
system("pause");
return 0;

}
 