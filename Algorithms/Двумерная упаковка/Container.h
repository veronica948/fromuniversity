#include<iostream>
#include<list>
#include<fstream>
using namespace std;
struct Rectangle {
	double length;
	double width;
	Rectangle(double length,double width) {
		this->length = length;
		this->width = width;
	}
	void changeFields(double length,double width) {
		this->length = length;
		this->width = width;
	}
};
struct Node {
	Rectangle* date;
	Node *next;
	Node(double length,double width, Node* next= 0) {
		date = new Rectangle(length, width);
		this->next = next;
	}
};
class List {
	Node* first;
public:
	List() {
		first=0;
	}
	void push(double length, double width){
		if(!first) {
		first=new Node(length,width);
		return;
	}
	Node *c=first;
	while(c->next) 
		c=c->next;
	c->next=new Node(length,width);
	}
	void show() {
		if(!first) {
			cout<<"-"; 
			return;
		}
		Node*d=first;
		while(d){
			cout<<d->date->length<<' '<<d->date->width<<endl; 
			d=d->next;
		}
	}
	void AddObject(int i, double length, double width) {
		Node* d = first;
		while(i - 1){
			d=d->next;
			i--;
		}
		d->next = new Node(length, width, d->next);
	}
	Rectangle*& operator [] (int i) {
		Node* d=first;
		while(i){
			d=d->next;
			i--;
		}
		return d->date;
	}
	Node* getFirst() {
		return first;
	}
};
struct Container {
	const static int LENGTH = 1;
	const static int WIDTH = 1;
	List listOfObjects;
	List listOfFreeRactangles;
	int numberOfFreeRectangles;
	Container() {
		listOfFreeRactangles.push(LENGTH,WIDTH);
		numberOfFreeRectangles = 1;
	}
	void show() {
		//cout<<"Length: "<<currentLength<<endl;
		listOfObjects.show();
	}
};
struct Strip {
	const static int WIDTH = 1;
	double currentLength;
	List listOfObjects;
	List listOfFreeRactangles;
	int numberOfFreeRectangles;
	Strip() {
		currentLength = 0;
		numberOfFreeRectangles = 0;
	}
};
struct Quadrant {
	double currentLength;
	double currentWidth;
	List listOfObjects;
	List listOfFreeRactangles;
	int numberOfFreeRectangles;
	Quadrant() {
		currentLength = 0;
		currentWidth = 0;
		numberOfFreeRectangles = 0;
	}
	double getArea() {
		return currentLength * currentWidth;
	}
};