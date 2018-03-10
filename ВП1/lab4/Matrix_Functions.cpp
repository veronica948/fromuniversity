#include <iostream>
#include"Matrix.h"

template<class X> void Matrix<X>:: Create_Memory(int n)
{
	A=new X*[n];
    if(!A) 
      {
		  cout<<"Error"; exit(1);
	  }
	for(int i=0;i<n;i++)
		{
			A[i]=new X [n];
		    if(!A[i]) 
			{
				cout<<"Error"; 
				exit(1);
			}
	}
}

template<class X> Matrix<X>::Matrix(int m=DEFAULT_NUMBER_OF_ELEMENTS) {
	n=m;
	Create_Memory(n);
}

template<class X>  Matrix<X>::Matrix() {
	n=DEFAULT_NUMBER_OF_ELEMENTS;
	Create_Memory(n);
}

template<class X>Matrix<X>::Matrix(const Matrix<X> &m) {
	n=m.n;
	Create_Memory(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=m.A[i][j];
}

template<class X> Matrix<X>::~Matrix() {
	for(int i=0;i<n;i++)
		delete []A[i];
	delete []A;
}

template<class X>void Matrix<X>::Create_Matrix() {
	cout<<"Enter the elements.There are "<<n*n<<"elements\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	X k; cin>>k;
			A[i][j]=k;
	    }
}

template<class X>Matrix<X> Matrix<X>::Add(Matrix<X> &b) 
	{return *this+b;};

template<class X>Matrix<X> Matrix<X>::Subtract(Matrix<X> &b) 
	{return *this-b;};

template<class X>Matrix<X> Matrix<X>::Multiply(Matrix<X> &b) 
    {return *this*b;};

template<class X>double Matrix<X>::Norm() { X t=0;
		             for (int i=0;i<n;i++)
						for(int j=0;j<n;j++)
							t+=A[i][j]*A[i][j];
					  return sqrt((double)t);
	}

template<class X> ostream& operator << (ostream&stream,Matrix<X> &M) { 
	for(int i=0;i<M.n;i++)
		{for(int j=0;j<M.n;j++)
			{stream.width(6);
			 stream<<M.A[i][j];}
			stream<<endl;
	 }
	 return stream;
}


template<class X>Matrix<X> Matrix<X>::operator * (const Matrix<X> &b) {
	Matrix<X> C(n);
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		{C.A[k][i]=0;
			for(int j=0;j<b.n;j++)
			{C.A[k][i]+=A[k][j]*b.A[j][i];}
	}
	return C;
	}

template<class X>Matrix<X> Matrix<X>::operator + (const Matrix<X> &b){
	Matrix<X> C(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C.A[i][j]=A[i][j]+b.A[i][j];
	return C;
}

template<class X>Matrix<X> Matrix<X>::operator - (const Matrix<X> &b){
	Matrix<X> C(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C.A[i][j]=A[i][j]-b.A[i][j];
	return C;
}

template<class X>Matrix<X>& Matrix<X>::operator = (const Matrix<X> &b) {
	if(this==&b) return *this;
	for(int i=0;i<n;i++)
		delete []A[i];
	delete []A;	
	n=b.n;
	Create_Memory(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			A[i][j]=b.A[i][j];
	return *this;
}