#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct node {
	char date;
	node *prev;
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
	int Compare(char s1);
	node *Get_Element() {return last;}
};
class MyException {
	char str_what[80];
public:
	MyException(){
		*str_what = 0;
	}
	MyException(char* s1){
		strcpy(str_what,s1);
	}
	void print(){
		cout<<str_what;
	}
};
