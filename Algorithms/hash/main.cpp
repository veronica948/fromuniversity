#include"hash.h"

int main(){
	Hash hash;
	cout<<"Enter the number of element to add ";
	int count,k;
	cin>>count;
	cout<<"Enter the elements\n";
	while(count){
		cin>>k;
		hash.Push(k,rand()%10);
		count--;
	}
	cout<<"Enter the number of element to delete ";
	cin>>k;
	hash.Delete(k);
	hash.Show();
	cout<<"Enter the number to find\n";
	cin>>k;
	cout<<"The result of the search:\n";
	node* result=hash.Search(k);
	if(!result) cout<<"No element\n";
	else
	cout<<result->key<<' '<<result->date;
	system("pause");
	return 0;
}