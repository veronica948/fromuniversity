#include<iostream.h>
#include<string.h>
int main()
{ int const N=100;
  int i,k=0;
  char S[N];
  cout<<"Enter the text"<<endl;
  gets(S);
  for(i=0;S[i]!='\0';i++)
  if(S[i]==' ') k++;
  if(S[i-1]!=' ') k++;
  if(S[0]==' ') k--;
  cout<<"k="<<k<<endl;
  system("pause");
  return 0;
  }

