#include<iostream.h>
int main()
{
 int n,m,x=1,k=1,sum=0,d=1;
 cout<<"Enter two numbers"<<endl;
 cin>>n>>m;
      while(n<=m)
       {
        while(x<=n/2)
         if(n%x==0) { sum=sum+x; x++;}
        sum=sum+n;
        if(sum>m) { m=sum; d=k;}
            k++;
            n++;
            sum=0;
          }
 cout<<"max summa delitelej y chisla s nomerom ="<<d<<endl;
 system("pause");
 return 0;
 }
