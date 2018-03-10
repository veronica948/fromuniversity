#include<iostream>
#include<algorithm>
#include<fstream>
#include<climits>
using namespace std;
struct node {
	int date;
	node *next;
	node(int a) {date=a; next=0;}
};
class List {
	node* first;
public:
	List() {
		first=0;
	}
	void push(int a){
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

int findPosition(int* arrayOfElements,int leftBound,int rightBound, int element) {
	int currentPosition = leftBound + (rightBound - leftBound) / 2;
	if(element < arrayOfElements[currentPosition]) {
		if(element >= arrayOfElements[currentPosition - 1]) {
			return currentPosition;
		}
		return findPosition(arrayOfElements, leftBound, currentPosition - 1, element);
	}
	if(element >= arrayOfElements[currentPosition]) {
		if(element < arrayOfElements[currentPosition + 1]) {
			return currentPosition + 1;
		}
		return findPosition(arrayOfElements, currentPosition + 1, rightBound, element);
	}
}
const int INFINITY_2 = -2;
const int INFINITY = 1000;
int main() {
	ifstream file("file.txt");
	int n;
	file>>n;
	int * d = new int [n + 1];
	List* sequences = new List [n + 1];
	int * a = new int [n];
	d[0] = INFINITY_2;
	for(int i = 1; i < n + 1; i++) {
		d[i] = INFINITY;
		file>>a[i - 1];
	}
	for(int i = 0; i < n; i++) {
		int j = findPosition(d,0,n,a[i]);
		cout<<j<<' '<<a[i]<<endl;
		if(d[j - 1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
		}
	} 
	for(int i = n; i >= 0; i--) {
		if(d[i] != INFINITY) {
			cout<<"The length of sequence: "<<i<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}