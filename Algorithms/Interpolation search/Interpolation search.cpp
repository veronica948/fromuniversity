#include<iostream>
using namespace std;

int Interp(int* a,int l,int r,int p) {
	if(p<a[l]||p>a[r]) return -1;
	if(a[r]==a[l]) 
		if(a[l]==p) return l;
		else return -1;
	int k=(r-l)*(p-a[l])/(a[r]-a[l])+l;
	if(a[k]==p) return k;
		else if(a[k-1]<p && a[k+1]>p) return -1;
			else if(a[k]<p) Interp(a,k+1,r,p);
				else Interp(a,l,k-1,p);
}
int main() {
		int *a;
        int n;
        cout<<"Input the number of array elements: "; cin>>n;
        a=new int [n];
		a[0]=rand()%4;
        for(int i=1;i<n;i++)
                {int k=rand()%4;
				 a[i]=a[i-1]+k;
				//a[i]=a[0];
                }		
		for(int i=0;i<n;i++)
                {
                cout<<" "<<a[i];
                }
		cout<<endl;
		int f=1;
		while(f){
			cout<<"Input the element: ";
			int p;
			cin>>p;
			cout<<"It's position: ";
			int k = Interp(a,0,n-1,p);
			if(k==-1) cout<<"No such element."<<endl;
			else cout<<k<<endl;
			cout<<"More - 1, Stop - 0"<<endl;
			cin>>f;
		}
		delete[]a;
		system("pause");
		return 0;
}