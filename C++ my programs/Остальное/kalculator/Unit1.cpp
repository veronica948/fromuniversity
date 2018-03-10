#include<iostream.h>
int main()
{ double n,x,y;
  char c;
  int f=1;
 while(f==1)
 {
 cout<<"enter numbers" <<endl;
 cout<<"x=";
 cin>>x;
  cout<<"y=";
 cin>>y;

 cout<<"Enter operation +  -  *  /"<<endl;
 cin>>c;

 switch(c)
 {   case '+':  n=x+y;
                cout<<"x+y="<<n<<endl;
                break;
 case '-':
                n=x-y;
                cout<<"x-y="<<n<<endl;
                break;
 case '*' :     n=x*y;
                cout<<"x*y="<<n<<endl;
                break;
 case '/':      if(y==0) cout<<"Nelzya delit na 0"<<endl ;
                else { n=x/y;
                cout<<"x/y="<<n<<endl; }
                break;
default: cout<<"error"<<endl;
         f=-1;
 }
 }
 system("pause");
 return 0;
 }

