#include"Tree.h"
int main() {
	Tree tree;
	int a,b;
	cout<<"Enter the number to add"<<endl;
	int count;
	cin>>count;
	while(count){
		cin>>a;
		b=rand()%100;
		tree.Push(tree.Get_Root(),a,b);
		count--;
	}
	tree.Print(tree.Get_Root());
	cout<<"Enter the number to find ";
	int k;
	cin>>k;
	node* c=tree.Search(tree.Get_Root(),k);
	cout<<"The result of search:"<<endl;
	if(!c) cout<<"No elements"<<endl;
	else cout<<"The date: "<<c->date<<" The key: "<<c->key<<endl;
	
	cout<<"Enter the number to delete ";
	cin>>k;
	tree.Delete(k);
	tree.Print(tree.Get_Root());
	/*tree.Push(tree.Get_Root(),a=4,b=7);
	tree.Push(tree.Get_Root(),a=5,b=3);
	tree.Push(tree.Get_Root(),a=1,b=4);
	tree.Push(tree.Get_Root(),a=0,b=6);
	tree.Push(tree.Get_Root(),a=2,b=9);
		tree.Print(tree.Get_Root());
		cout<<endl;
	tree.Rotation_Left(tree.Search(tree.Get_Root(),1));
	tree.Rotation_Right(tree.Search(tree.Get_Root(),8));
	a=4; b=9;*/
	tree.Push_In_Root(tree.Get_Root(),a=8,b=0);
	cout<<"After push in root\n";
	tree.Print(tree.Get_Root());
	cout<<endl;
	tree.Obhod(tree.Get_Root());
	cout<<endl;
	system("pause");
	return 0;
}