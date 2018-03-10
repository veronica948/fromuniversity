#include "queue.h"
int main() 
{
	Queue queue;
	cout<<"Enter the number of elements to add\n";
	
	int number;
	cin>>number;
	cout<<"Enter the elements\n";
	while(number){
		int n;
		cin>>n;
		queue.Paste(n);
		number--;
	}
		
	cout<<"enter a number"<<endl;
	int m;
	cin>>m;
	node *a=queue.Search(m);
	if(!a) cout<<"No elements"<<endl;
	else cout<<a->date<<endl;
	queue.Delete();
	queue.Delete();
	queue.Show();
	system("pause");
	return 0;
}
