#include<iostream.h>
int main()
{ int const N=10;
  int a[N], sum=0,pr=1,kol=0;
  for(i=0;i<N;i++)
  cout<<"a["<<i<<"]="<<endl;
  cin>>a[i];
  for(i=0;i<N;i++)
  { if(a[i]>0) pr*=a[i];
    if(a[i]<0) sum+=a[i];
    if(!(a[i]%2)) kol++;
  }
  cout<<"proizvedenie positive="<<pr<<endl;
  cout<<"summa negative="<<sum<<endl;
  cout<<"kolichestvo chetn="<<kol<<endl;
  system("pause");
  return 0;
}

