#include<iostream>
#include<math.h>
using namespace std;
struct node {
	int date;
	int key;
	node *next;
	node(int n,int a) {key=n; date=a; next=0;}
};

class List {
	node* first;
public:
	List() {first=0;}
	~List() {Delete_List();};
	void Paste(int n,int a);
	void Delete_L(int n);
	void Show_L();
	node* Search_L(int n);
	void Delete_List();
};

class Hash {
	List *a;
public:
	Hash() {a=new List [128];}
	void Push(int n,int b);
	node* Search(int n);
	void Delete(int n);
	void Show();
	~Hash(){
		delete []a;
	}
};