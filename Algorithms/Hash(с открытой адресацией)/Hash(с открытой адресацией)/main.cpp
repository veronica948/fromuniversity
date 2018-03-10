#include"Hash.h"
void list_menu() {
    cout<<"1-Push"<<endl;
    cout<<"2-Find"<<endl;
    cout<<"3-Delete"<<endl;
    cout<<"4-Show"<<endl;
    cout<<"5-Exit"<<endl;
}
int main(){
	Hash hash;
	hash.Push(10);
	hash.Push(10);
	hash.Push(10);
	hash.Push(13);
	hash.Push(14);
	hash.Push(13);
	hash.Push(14);
	for(int i=0;i<125;i++)
		hash.Push(rand()%128);
	hash.Show();
	int k;
	int n,result,f=1;
	while(f){
		cout<<endl;
		list_menu();
		cout<<"Choose numeral"<<endl;
		cin>>n;
	  switch(n){
	  case 1: cout<<"Enter the number to push\n";
			  cin>>k;
		      hash.Push(k);
		      hash.Show();
			  break;
	  case 2: cout<<"Enter the number to find\n";
			  cin>>k;
			  cout<<"The result of the search:\n";
			  result=hash.Search(k);
			  if(result==-1) cout<<"No element\n";
			  else
				cout<<result<<endl;
			  break;
	  case 3: cout<<"Enter the number of element to delete ";
			  cin>>k;
			  hash.Delete(k);
			  hash.Show();
			  break;
	  case 4: hash.Show();
			  break;
	  case 5: f=0;
			  break;
	  default: cout<<"Error";
			   break;
		}
	}
	system("pause");
	return 0;
}