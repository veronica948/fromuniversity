#include<iostream>
using namespace std;
struct node {
	int date;
	int key;
	node* right;
	node* left;
	node(int n,int a) {right=0; left=0; key=n; date=a;}
};

class Tree {
	node* root;
public:
	Tree() {root=0;}
	~Tree() {Delete_Tree(root);}
	void Push(node *&root1,int &n,int &a);
	void Delete(int n);
	node* Search(node*root1,int n);
	node*& Get_Root() {return root;}
	node* Find_Parent(node* y,node* x);
	void Rotation_Left(node*y);
	void Rotation_Right(node*y);
	void Push_In_Root(node* &root1,int n,int a);
	void Obhod(node* root1);
	void Print(node*root1,int t=2);
	void Delete_Tree(node*root1);
};