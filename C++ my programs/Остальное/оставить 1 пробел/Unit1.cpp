#include<iostream.h>
#include<string.h>
int main()
{ int const N=100;
  int i,p;
  char S[N];
  cout<<"Enter the text"<<endl;
  gets(S);
  p=strlen(S);

  for(i=0;i<p;i++)
  if(((S[i]==' ')&&(S[i+1]==' '))||(S[0]==' '))
   {for(int t=i;t<p;t++)
   S[t]=S[t+1];
   p--;
   i--;
   }
   if(S[p-1]==' ') {S[p-1]='\0';    p--;}


  for(int i=0;i<p;i++)
  cout<<S[i];
  

  system("pause");
  return 0;
  }

