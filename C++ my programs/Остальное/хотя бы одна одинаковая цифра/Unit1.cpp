#include<iostream.h>
int main()
{
int n,t,x,a,f=1;
cout<<"enter number"<<endl;
cin>>n;
while((n)&&(f))
{       x=n%10;
        n=n/10;
        a=n;
        while(a)
        {t=a%10;
        if(t==x)
        {
        cout<<"yes"<<endl;
        f=0;
        break;
        }
        a=a/10;
        }
       }
if(f) cout<<"No"<<endl;
system("pause");
return 0;
}
