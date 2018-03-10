#include<iostream.h>
#include<stdlib.h>
#include<string.h>
int main()
{char s[11];
 int n;
 cout<<"Enter number"<<endl;
 cin>>n;
 cout<<"Enter second number-string "<<endl;
 //cin>>s;
 gets(s);
  int p=strlen(s);
  int t=n;
  int k; //количество цифр в числе
  for(k=0;t;t/=10,k++);
  if(k==p)
      {for(;p;p--)
      if(s[p-1]==(n%10+48))n/=10;
      else break;
       if(n) cout<<"No";
       else cout<<"Yes";
       }
  else cout<<"No"; 

system("pause");
return 0;
}
