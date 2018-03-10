#include"Matrix.h"
int** Create_Memory(int n)
{int **A=new int*[n];
if(!A) 
{cout<<"Error"; exit(1);}
	for(int i=0;i<n;i++)
		{A[i]=new int [n];
		if(!A[i]) 
			{cout<<"Error"; exit(1);
			}
		}
return A;
}

Matrix::Matrix(int m=5) {
	n=m;
	A=Create_Memory(n);
}

Matrix::Matrix() {
	n=5;
	A=Create_Memory(n);
}

Matrix::Matrix(const Matrix &m) {
	n=m.n;
	A=Create_Memory(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=m.A[i][j];
}

Matrix::~Matrix() {
	for(int i=0;i<n;i++)
		delete []A[i];
	delete []A;
}

void Matrix::Create_Matrix() {
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=rand()%100;
}

Matrix Matrix::Add(Matrix &b) 
	{return *this+b;};
Matrix Matrix::Subtract(Matrix &b) 
	{return *this-b;};
Matrix Matrix::Multiply(Matrix &b) 
    {return *this*b;};
double Matrix::Norm() { int t=0;
		             for (int i=0;i<n;i++)
						for(int j=0;j<n;j++)
							t+=A[i][j]*A[i][j];
					  return sqrt((double)t);
	}

ostream& operator << (ostream&stream,Matrix&M) { 
	for(int i=0;i<M.n;i++)
		{for(int j=0;j<M.n;j++)
			{stream.width(6);
			 stream<<M.A[i][j];}
			stream<<endl;
	 }
	 return stream;
}

Matrix Matrix::operator * (const Matrix &b) {
	Matrix C(5);
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		{C.A[k][i]=0;
			for(int j=0;j<b.n;j++)
			{C.A[k][i]+=A[k][j]*b.A[j][i];}
	}
	return C;
	}

Matrix Matrix::operator + (const Matrix &b){
	Matrix C(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C.A[i][j]=A[i][j]+b.A[i][j];
	return C;
}

Matrix Matrix::operator - (const Matrix &b){
	Matrix C(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C.A[i][j]=A[i][j]-b.A[i][j];
	return C;
}

Matrix& Matrix::operator = (const Matrix &b) {
	if(this==&b) return *this;
	for(int i=0;i<n;i++)
		delete []A[i];
	delete []A;	
	n=b.n;
	A=Create_Memory(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=b.A[i][j];
	return *this;
}