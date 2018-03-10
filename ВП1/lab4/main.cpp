//#include"Matrix.h"
#include <iostream>
#include"Matrix_Functions.cpp"
template<class X> void Square(Matrix<X> *m,int n) {
	for(int i=0;i<n;i++)
		m[i]=m[i]*m[i];
}

int main() {
	cout<<"Enter the number of matrix"<<' ';
	int n;
	cin>>n;
	Matrix<int>* matrix = new Matrix<int>[n];
	//Matrix<double>* matrix = new Matrix<double>[n];
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