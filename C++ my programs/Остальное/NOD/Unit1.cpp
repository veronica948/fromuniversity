#include<iostream.h>
int main()
{
 int n,m,NOD=1,x=1,k;
 cout<<"Enter two numbers"<<endl;
 cin>>n>>m;
 if(n<m) {k=n; n=m; m=k;}
 if(n%m==0) NOD=m;
 else
        while((x<=n/2)&&(x<=m/2))
        { if((n%x==0)&&(m%x==0))
           { NOD=x;
            x++;
            }
          }
 cout<<"NOD="<<NOD<<endl;
 system("pause");
 return 0;
 }
