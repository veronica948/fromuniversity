#include<iostream.h>
#include<string.h>
int main()
{ int const N=100;
  int i,p,r,k;
  char S[N];
  cout<<"Enter the text"<<endl;
  gets(S);

  for(i=0;S[i]!='\0';i++) ;
  for(p=i;p;p--)
  S[p]=S[p-1];
  S[0]=' ';
  S[i+1]=' ';
  S[i+2]='\0';

  for(int j=0;S[j]!='\0';j++)
  {if((S[j]==' ')&&(S[j+1]!=' ')) k=j+1;
  if((S[j]!=' ')&&(S[j+1]==' ')) { r=j;
  if(S[k]==S[r])
    for(int t=k;t<=r;t++)
    cout<<S[t];
    cout<<' ';
  }
  }


  system("pause");
  return 0;
  }

