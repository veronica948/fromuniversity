#include<iostream>
#include<fstream>
#include<exception>
//#include<list>
//#include"Tree.h"
using namespace std;
const static int INFINITY = -1;
struct node {
	int* edge;
	int** matrix;
	int value;
	bool hasEdge;
	node* previous;
	node* right;
	node* left;
	node(int**  matrix,node* prev,int value,int* edge,bool hasEdge) {
		this->edge = new int [2]; 
		right=0; 
		left=0; 
		//key=n;
		this->matrix = matrix;
		this->hasEdge = hasEdge; 
		this->value =value;
		this->previous = prev;
		if(!edge){
			this->edge = 0;
			return;
		}
		this->edge[0] = edge[0];
		this->edge[1] = edge[1];
		
	}
	node(){
		edge = new int [2];
	}
};
struct element {
	node* date;
	element* next;
	element(node* a) {date=a; next=0;}
};

class List {
	element* first;
public:
	List() {
		first=0;
	}
	void push(node* a){
		if(!first) {
		first = new element(a);
		return;
	}
	element *c=first;
	while(c->next) 
		c=c->next;
	c->next=new element(a);
	}
	void show() {
		if(!first) {
			cout<<"-"; 
			return;
		}
		element* d = first;
		while(d){
			cout<<d->date<<' '; 
			d=d->next;
		}
	}
	node* findMin(){
		element* minElement = first;
		element* current = minElement;
		while(current->next){
			current =current->next;
			if(current->date->value < minElement->date->value || minElement->date->value == INFINITY){
				minElement = current;
		}
		}
		return minElement->date;
	}
};
class Tree {
	node* root;
public:
	Tree() {root=0;}
	//~Tree() {Delete_Tree(root);}
	void Push(node* &root1,int** & matrix,int value,int* edge = 0,bool hasEdge =1);
	void Delete(int n);
	node* Search(node*root1,int n);
	node* findLeaveWithMinValue();
	node*& Get_Root() {return root;}
	node* Find_Parent(node* y,node* x);
	void Rotation_Left(node*y);
	void Rotation_Right(node*y);
	void Push_In_Root(node* &root1,int n,int a);
	void Obhod(node* root1, List & l);
	void Print(node*root1,int t=2);
	void Delete_Tree(node*root1);
};

class Graph {
	int numberOfVertices;
	int** matrixOfWeights;
	int* cycle;
	int weight;
	Tree tree;
	
public:
	Graph(char* fileName);
	void showMatrix();
	int buildNewMatrix(int**);
	int countFine(int, int,int** &);
	int findMaxFine(int&, int &, int** &);
	int** buildMatrixWithEdge(int**&, int*); 
	int** buildMatrixWithoutEdge(int**&, int*); 
	void branchAndBoundAlgorithm();
	void showResult();
};