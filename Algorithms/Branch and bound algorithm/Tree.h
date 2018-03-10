#include<iostream>
using namespace std;
struct node {
	int* edge;
	int** matrix;
	int value;
	bool hasEdge;
	node* right;
	node* left;
	node(int**  matrix,int value,int* edge,bool hasEdge) {
		this->edge = new int [2]; 
		right=0; 
		left=0; 
		//key=n;
		this->matrix = matrix;
		this->hasEdge = hasEdge; 
		this->value =value;
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
	bool operator < (const node &y ){
		if(this->value <= y.value)
			return true;
		else return false;
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