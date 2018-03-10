#include"Hash.h"
void Hash::Show(){
	for(int i=0;i<128;i++)
	{	if(a[i]==-8||a[i]==-1)
			{cout.width(4); cout<<"-";}
		else
			{cout.width(4);cout<<a[i]; }
	}
}

void Hash::Push(int n){
	if(n<0||n>127) {cout<<"Impossible\n"; return;}
	int i=n;
	int k=1;
	do
	{
		if(a[i]==-1||a[i]==-8)
			{a[i]=n;  return;}
		/*i=(i+1)%128;*/
		i=(i+k)%128;
		k++;
	} while(i!=n);
	cout<<"There is no place\n";
}

int Hash::Search(int n){
	if(n<0||n>127) return -1;
	int i=n;
	int k=1;
	do
	{
		if(a[i]==-8)
			{return -1;}
		if(a[i]==n) return i;
		/*i=(i+1)%128;*/
       i=(i+k)%128;
	   k++;
	} while(i!=n);
	return -1;
}

void Hash::Delete(int n){
	if(n<0||n>127) return;
	a[n]=-1;
}