#include<iostream>
#include<conio.h>
using namespace std;

template<class X> class Matrix {
	X **A;
	int n;
public:
	Matrix(int m);
	Matrix();
	Matrix(const Matrix<X> &m);
	~Matrix();
	void Create_Matrix();
	void Create_Memory(int n);
    Matrix<X> operator * (const Matrix<X> &b);
	friend ostream& operator << <>(ostream&stream,Matrix<X> &M);
	
	Matrix<X> operator + (const Matrix<X> &b);
	Matrix<X> operator - (const Matrix<X> &b);
	Matrix<X> Add(Matrix<X> &b);
	Matrix<X> Subtract(Matrix<X> &b);
	Matrix<X> Multiply(Matrix<X> &b);
	double Norm();

	static const int DEFAULT_NUMBER_OF_ELEMENTS = 3;
	Matrix<X>& operator = (const Matrix<X> &b);
};
