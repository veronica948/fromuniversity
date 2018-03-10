#include "stack.h"
int main() {
	Stack stack;
	cout<<"Enter the number of elements to add\n";
	
	int number;
	cin>>number;
	cout<<"Enter the elements\n";
	while(number){
		int n;
		cin>>n;
		stack.Paste(n);
		number--;
	}
		
	cout<<"enter a number"<<endl;
	int m;
	cin>>m;
	node *a=stack.Search(m);
	if(!a) cout<<"No elements"<<endl;
	else cout<<a->date<<endl;
	
	stack.Show();
	system("pause");
	return 0;
}
