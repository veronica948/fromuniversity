#include"hash.h"
int h1(int n) {
	return n%128;
}

int h2(int n){
	double m;
	double k=modf((sqrt(5.0)-1)/2*n,&m);
	return floor(128*k);
}

void List::Delete_List(){
	node* d=first;
	while(d){
		d=d->next;
		delete first;
		first=d;
	}

}

void List::Paste(int n,int a){
	if(!first) {first=new node(n,a); return;}
	node *c=first;
	while(c->next) 
		c=c->next;
	c->next=new node(n,a);
}

node* List::Search_L(int n){
	node *c=first;
	while(c)
	{
		if(c->key==n) return c;
		c=c->next;
	}
	return 0;
}

void List::Delete_L(int n) {
	if(!first) return;
	if(!first->next) {node *h=first; first=0; delete h; return;}
	node* d=first;
	while(d->next->key!=n&&d)
		d=d->next;
	if(!d) return;
	node* f=d->next;
	d->next=f->next;
	delete f;
}

void List::Show_L(){
	if(!first) {cout<<"-"; return;}
	node*d=first;
	while(d)
	{cout<<d->key<<' '; d=d->next;}
}

void Hash::Push(int n,int b){
	int k=h2(n);
	a[k].Paste(n,b);
}

node* Hash::Search(int n){
	int k=h2(n);
	return a[k].Search_L(n);
}

void Hash::Delete(int n){
	int k=h2(n);
	a[k].Delete_L(n);
}

void Hash::Show(){
	for(int i=0;i<128;i++)
	{ a[i].Show_L(); cout<<endl;}
}