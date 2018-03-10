#include<iostream>
using namespace std;
struct nodes {
	vertex date;
	nodes *next;
	nodes(vertex n) {date=n; next=0;}
};
class Queue {
	public:
	nodes* first;
	nodes* last;
	Queue() {first=0; last=0;}
	~Queue();
	void Paste(vertex n);
	void Delete();
};