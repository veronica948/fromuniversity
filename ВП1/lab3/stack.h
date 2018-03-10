#include<iostream>
using namespace std;
struct node {
	char date;
	node *prev;
	node() {prev=0; date=0; };
	node(node* a,char n) {prev=a; date=n;}
};
class Stack {
	node *last;
public:
	Stack() {last=0;};
	~Stack();
	void Paste(char n);
	void Delete();
	void Show();
	int Compare(char s);
	node *Get_Element() {return last;}
};