#include<iostream.h>
int main()
{
int n,x;
cout<<"Enter number"<<endl;
cin>>n;
while(n)
{
x=n%2;
n=n/2;
cout<<x;
}
system("pause");
return 0;
}
