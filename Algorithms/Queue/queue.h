#include<iostream>
using namespace std;
struct node {
	int date;
	node *next;
	node(int n) {date=n; next=0;}
};
class Queue {
	node* first;
	node* last;
public:
	Queue() {first=0; last=0;}
	~Queue();
	void Paste(int n);
	node* Get_Element() {node* a=first; first=first->next; return a;}
	void Delete();
	void Show();
	node* Search(int n);
};