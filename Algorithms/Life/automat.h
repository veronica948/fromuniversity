#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Field{
	int n;
	int m;
	int** matrix;
	void liveCycle();
	int countNeighbours(int,int,int**);
	void showField();
public:
	Field(char* fileName);
	void fulfil();
};
