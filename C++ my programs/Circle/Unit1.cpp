#include<iostream.h>
#include<stdlib.h>
int main()
{ const int N=4;
 int x[N],y[N],z[N],k[N],r;
 cout<<"Enter the points"<<endl;
 for(int i=0;i<N;i++)
  cin>>x[i]>>y[i]>>z[i];
  cout<<"radius=";
  cin>>r;
  for(int i=0;i<N;i++)
       { k[i]=0;
        for(int j=0;j<N;j++)
        {
        int p=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])+(z[j]-z[i])*(z[j]-z[i])-r*r;
        if(p<=0) k[i]++;
        }
        }
  int max=0,f=0;
  for(int t=0;t<N;t++)
        if(k[t]>k[max]) {max=t; f=1;}
        if(f)  cout<<"The point:"<<" "<<x[max]<<" "<<y[max]<<" "<<z[max]<<endl;
        else
  
        cout<<"All points equal or nill's point";


system("pause");
return 0;
}

