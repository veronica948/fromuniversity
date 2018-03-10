#include<iostream.h>
int main()
{
int n,x;
cout<<"Enter number"<<endl;
cin>>n;
while(n)
{
x=n%16;
n=n/16;
switch(x) {
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
case 9: cout<<x;
        break;
case 10: cout<<'a';
        break;
case 11: cout<<'b';
        break;
case 12: cout<<'c';
        break;
case 13: cout<<'d';
        break;
case 14: cout<<'e';
        break;
case 15: cout<<'f';
        break;

}
}
system("pause");
return 0;
}
