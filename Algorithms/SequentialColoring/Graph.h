#include<iostream>
#include<fstream>
using namespace std;
struct vertex {
	int color;
};
class Graph {
	int numberOfVertices;
	int** adjacencyMatrix;
	vertex * vertices;
public:
	Graph(int);
	Graph(int,int);
	Graph(char*);
	int sequentialColoring();
	int independentSetsColoring();
	int* findIndependentSet(int**,int&);
	bool isEmptyGraph(int**);
	void buildNewMatrix(int**&,int*,int);
	int chooseFirstVertex(int**);
	void showColors();
	void showMatrix();
};