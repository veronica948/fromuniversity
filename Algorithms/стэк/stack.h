#include<iostream>
using namespace std;
struct node {
	int date;
	node *prev;
	node(node* a,int n) {prev=a; date=n;}
};
class Stack {
	node *last;
public:
	Stack() {last=0;};
	void Paste(int n);
	void Delete();
	void Show();
	node *Search(int n);
	~Stack();
};
