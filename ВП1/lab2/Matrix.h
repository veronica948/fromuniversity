#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

class Matrix {
	int **A;
	int n;
public:
	Matrix(int m);
	Matrix();
	Matrix(const Matrix &m);
	~Matrix();
	void Create_Matrix();
    Matrix operator * (const Matrix &b);
	friend ostream& operator << (ostream&stream,Matrix&M);
	Matrix operator + (const Matrix &b);
	Matrix operator - (const Matrix &b);
	Matrix& operator = (const Matrix &b);
	Matrix Add(Matrix &b);
	Matrix Subtract(Matrix &b);
	Matrix Multiply(Matrix &b);
	double Norm();
};
