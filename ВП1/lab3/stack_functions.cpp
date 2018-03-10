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
	last=new node(last,n);
}

int Stack::Compare(char s){
	if(last->date==s-2||last->date==s-1)
		{ Delete(); return 1;}
	else
		return 0;

}
Stack::~Stack() {
	while(last)
		Delete();
}


