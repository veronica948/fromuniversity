#include "queue.h"
void Queue::Paste(int n) {
	node*a=new node(n);
	if(!first) { last=a; first=last;}
	else
	{
		last->next=a;
		last=a;
	}
}
void Queue::Delete() {
	if(first)
	{
	node* a=first; 
	first=first->next;
	delete a;
	}
}

void Queue::Show() {
	if(!first) {cout<<"Empty queue"<<endl; return;}
	while(first)
	{
		cout<<first->date<<' ';
	    Delete();
	}
}

node* Queue::Search(int n) {
	node* now=first;
	while(now)
	{	
		if(now->date==n) return now;
		now=now->next;
	} 
	return 0;
}
Queue::~Queue() {
	while(first)
		Delete();
}	