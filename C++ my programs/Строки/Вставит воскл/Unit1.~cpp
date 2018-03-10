#include<iostream.h>
#include<string.h>
int main()
{ int const N=100;
  int i,p,r,k;
  char S[N];
  cout<<"Enter the text"<<endl;
  gets(S);
  p=strlen(S);

  for(i=0;i<p-1;i++)
  if((S[i]!=' ')&&(S[i+1]==' '))
  {S[p+1]='\0';
  for(int t=p;t>i+1;t--)
  S[t]=S[t-1];
  S[i+1]='!';
  p++;
  i++;
  }

if(S[p-1]!=' ') { S[p]='!'; S[p+1]='\0'; p++;}


    for(int i=0;i<p;i++)
    cout<<S[i];
  system("pause");
  return 0;
  }

