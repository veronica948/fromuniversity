#include"Tree.h"
void Tree::Push(node* &root1,int &n,int &a){
	if(!root1) {root1=new node(n,a); return;}
	if(n>=root1->key) 
		Push(root1->right,n,a);
	else
		Push(root1->left,n,a);
}

void Tree::Delete(int n){
	node* x=Search(root,n);

	if(!x) {return;}

	node* y=Find_Parent(root,x);
	if(!x->right&&!x->left&&y) {
		if(x->key>=y->key) y->right=0;
		else y->left=0;
		delete x; return;}
	if(!x->right&&!x->left&&!y) {delete x; root=0; return;}
	  	
	if(y) {
		if(!x->right&&x->key>=y->key) {y->right=x->left; return;}
		if(!x->right&&x->key<y->key) {y->left=x->left; return;}
		if(x->key>=y->key) y->right=x->right;
		else y->left=x->right; 
	}
	if(!y&&!x->right) {root=x->left; return;}
	if(!y) {root=x->right;}
	node* a=x->right;
	while(a->left)
			a=a->left;
	a->left=x->left;
	delete x;
}

node* Tree::Search(node* root1,int n) {
	if(!root1) return 0;
	if(root1->key==n) return root1;
	if(n>root1->key) return Search(root1->right,n);
	else return Search(root1->left,n);
}

node* Tree::Find_Parent(node* y,node* x){
	if(x==root) return 0;
	if(y->right==x||y->left==x) return y;
	if(x->key>=y->key) return Find_Parent(y->right,x);
	else return Find_Parent(y->left,x);
	
}

void Tree::Rotation_Left(node*y){
	if(!y) return;
	node* parent_y=Find_Parent(root,y);
	node* x=y->right;
	if(!x) return;
	if(!parent_y) root=y->right;
	if(parent_y)
	if(y->key>=parent_y->key) parent_y->right=x;
	else parent_y->left=x;
	node* temp=x->left;
	x->left=y;
	y->right=temp;
}

void Tree::Rotation_Right(node*y){
	if(!y) return;
	node* parent_y=Find_Parent(root,y);
	
	node* x=y->left;
	if(!x) return;
	if(!parent_y) root=y->left;
	if(parent_y)
		if(y->key>=parent_y->key) parent_y->right=x;
		else parent_y->left=x;
	node* temp=x->right;
	x->right=y;
	y->left=temp;
}

void Tree::Push_In_Root(node* &root1,int n,int a){
	if(root1==0) {root1=new node(n,a); return;}
	if(n>=root1->key) {Push_In_Root(root1->right,n,a); Rotation_Left(root1);}
	else {Push_In_Root(root1->left,n,a); Rotation_Right(root1);}
}

void Tree::Obhod(node*root1){
	if(!root1) return;
	Obhod(root1->left);
	cout<<root1->key<<' ';
	Obhod(root1->right);
}

void Tree::Print(node*root1,int t){

	if(!root1) {return;}
	Print(root1->right,2*t);
	cout.width(t);
	cout<<root1->key;
	cout<<endl;
	Print(root1->left,2*t);
}

void Tree::Delete_Tree(node*root1) {
	if(!root1) return;
	
	if(root1->right) {Delete_Tree(root1->right); }
	
	if(root1->left) { Delete_Tree(root1->left);}
	if(!root1->left&&!root1->right) { node* y=Find_Parent(root,root1); 
										if(!y) {delete root1; root=0;}
										else{
										if(root1->key>=y->key)
											y->right=0;
										else y->left=0;
										delete root1;}return;}
}
