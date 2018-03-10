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
  if((s[i]!=' ')&&(s[i+1]==' '))
   { r=i;
   int d=1;
   int b=r-k+1;
   for(int j=k,t=r;j<=k+b/2;j++,t--)
   if(s[j]!=s[t]) { d=0; break;}
   if(d)
   {for(int j=k;j<=r;j++)
   cout<<s[j];
   cout<<endl;
   }
  }
  }

system("pause");
return 0;

}
