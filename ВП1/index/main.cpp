#include"class.h"

int main() {
	int n;
	cout<<"n=";
	cin>>n;
	Archive archive(n);
	archive.Create_Archive();
	for(int i=0;i<n;i++)
	cout<<archive[i]<<' ';
	system("pause");
	return 0;
}
