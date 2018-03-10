#include<iostream.h>
int main()
{ int x,s=0,k=0,p=0;
/*while(1)
{
cout<<"vvedi chislo"<<endl;
cin>>x;
if(x==-1)
{cout<<"x=-1"<<endl;
break;
}
if(x%2==0) s++;
else k++;
if((x%2==0)&&(x%3==0))
p++;
} */

 /*do
{
cout<<"vvedi chislo"<<endl;
cin>>x;
if(x==-1)
{cout<<"x=-1"<<endl;
break;
}
if(x%2==0) s++;
else k++;
if((x%2==0)&&(x%3==0))
p++;
} while(1);  */

for(;;)
{
cout<<"vvedi chislo"<<endl;
cin>>x;
if(x==-1)
{cout<<"x=-1"<<endl;
break;
}
if(!(x%2)) {s++; if(!(x%3)) p++;}
else k++;
p++;
}

 cout<<"kol chetn="<<s<<endl;
 cout<<"kol nechetn="<<k<<endl;
 cout<<"kol kratn 6="<<p<<endl;
 system("pause");
 return 0;
 }


