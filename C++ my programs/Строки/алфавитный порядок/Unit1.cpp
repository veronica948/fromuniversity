#include<iostream.h>
#include<string.h>
int main()
{ int const N=100;
  int i,p,r,k;
  char S[N];
  cout<<"Enter the text"<<endl;
  gets(S);
  p=strlen(S);

for(int i=p;i;i--)
  S[i]=S[i-1];
  S[0]=' ';
  S[p+1]=' ';
  S[p+2]='\0';
  p=p+2;

  for(int i=0;i<p-1;i++)
  {if((S[i]==' ')&&(S[i+1]!=' ')) k=i+1;
  if((S[i]!=' ')&&(S[i+1]==' '))
   { r=i;
   int f=1;
     for(int t=k;t<r;t++)
   { if(S[t]<S[t+1]) continue;
    f=0; break;}
  int b=r-k+1;
  if(f)
  {for(;b;b--,p--)
  {    for(int t=k;t<p;t++)
       S[t]=S[t+1];
  } i=k-1;}
  }
  }
    for(int i=0;i<p;i++)
    cout<<S[i];

  system("pause");
  return 0;
  }

