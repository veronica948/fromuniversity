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
void Stack::Paste(char n) {
	last = new node(last,n);
}
int Stack::Compare(char s1){
	const int different_between_brackets_1 = 2;
	const int different_between_brackets_2 = 1;
	if(!last) return 0;
	if(last->date==s1-different_between_brackets_1||last->date==s1-different_between_brackets_2)
		{ Delete(); return 1;}
	else
		return 0;
}
Stack::~Stack() {
	while(last)
		Delete();
}
