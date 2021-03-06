#include<iostream.h>

void merge(int* a, int l, int r, int m){
	int l1 = m-l+1;
	int l2 = r-m;
	int*m1 = a+l;
	int*m2 = a+m+1;
	int* b = new int[l1+l2];
	int i=0;
	while(l1 && l2) {
		if(*m1<*m2) {
			b[i]=*m1;
			m1++;
			l1--;
		} else {
			b[i]=*m2;
			m2++;
			l2--;
		}
		i++;
	}
	if(!l1)
		for(int j=0;j<l2;j++)
			b[i++]=*m2++;
	else
		for(int j=0;j<l1;j++)
			b[i++]=*m1++;
	for(int p=l;p<=r;p++)
		a[p]=b[p-l];
}
void MergeSort(int* a, int l, int r){
		if(l<r) {
		int m=(l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		merge(a,l,r,m);  }
}
int main() {
	int *a;
        int n;
        cout<<"Input the number of array elements: "; cin>>n;
        a=new int [n];
        rand();
        for(int i=0;i<n;i++)
                {
                a[i]=rand()%100;
                //cout<<" "<<a[i];
                }
		//cout<<endl;
		MergeSort(a,0,n-1);
		for(int i=0;i<n;i++)
                {
                cout<<" "<<a[i];
                }
		cout<<endl;
		delete[]a;
		system("pause");
                return 0;

}