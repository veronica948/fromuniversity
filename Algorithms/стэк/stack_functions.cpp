#include "stack.h"
void Stack::Show() {
	if(!last) {cout<<"Empty stack"<<endl; return;}
	while(last)
	{cout<<last->date<<' ';
	 Delete();
	}
}
void Stack::Delete() {
	node*a=last;
	if(last)
	last=last->prev;
	delete a;
}
void Stack::Paste(int n) {
	last=new node(last,n);
}
node* Stack::Search(int n) {
	if(!last) {return 0;}
	node* now=last;
	while(now)
	{	
		if(now->date==n) return now;
		now=now->prev;
	} 
	return 0;
}
Stack::~Stack() {
	while(last)
		Delete();
}
