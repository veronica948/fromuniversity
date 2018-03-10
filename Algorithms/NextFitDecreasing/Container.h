#include<iostream>
#include<list>
#include<fstream>
using namespace std;
struct node {
	double date;
	node *next;
	node(double a) {date=a; next=0;}
};

class List {
	node* first;
public:
	List() {
		first=0;
	}
	void push(double a){
		if(!first) {
		first=new node(a);
		return;
	}
	node *c=first;
	while(c->next) 
		c=c->next;
	c->next=new node(a);
	}
	void show() {
		if(!first) {
			cout<<"-"; 
			return;
		}
		node*d=first;
		while(d){
			cout<<d->date<<' '; 
			d=d->next;
		}
	}
};
struct Container {
	double currentLength;
	const static int LENGTH = 1;
	List listOfObjects;
	Container() {
		currentLength = 0;
	}
	void show() {
		cout<<"Length: "<<currentLength<<endl;
		listOfObjects.show();
	}
};