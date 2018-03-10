#include"Matrix.h"
void Square(Matrix *m,int n) {
	for(int i=0;i<n;i++)
		m[i]=m[i]*m[i];
}

int main() {
	cout<<"Enter the number of matrix"<<' ';
	int n;
	cin>>n;
	Matrix* matrix=new Matrix [n];
	for(int i=0;i<n;i++) 
		matrix[i].Create_Matrix();
	for(int i=0;i<n;i++) 
		cout<<"Matrix:"<<endl<<matrix[i];
	cout<<"New matrix"<<endl;
	Square(matrix,n);
	for(int i=0;i<n;i++) 
		cout<<"Matrix:"<<endl<<matrix[i];
	delete []matrix;
	system("pause");
	return 0;
}