#include "stack.h"
void List(){
	cout<<"1 -Function with text file\n";
	cout<<"2 - Function with binary file\n";
	cout<<"3 - Exit\n";
}
void Function_with_stack(){
	Stack stack;
	char s;
	ifstream fin("Expression.txt",ios::in);
	try{ 
		 if(!fin)
			throw MyException("File wasn't opened\n");
		
	while(!fin.eof()){
		fin>>s;
		if(s=='('||s=='{'||s=='[')
			stack.Paste(s);
		if(s==')'||s=='}'||s==']')
			if(!stack.Compare(s))
				break;
	}
	if(stack.Get_Element()) cout<<"Answer: wrong\n";
		else cout<<"Answer: right\n";
	fin.close();
	}
	catch(MyException e){
		e.print();
	}
}
void Function_with_vector(){
	ofstream fout("Vector",ios::out|ios::binary);
	int size;
	cout<<"Enter the size of vector\n";
	cin>>size;
	int* vector;
	try{
		vector = new int [size];
		if(size>1000)
			throw MyException("Size is too much");
	}
	catch(bad_alloc ex){
		cout<<"Memory isn't \n";
		return;
	}
	catch(MyException e){
		e.print();
		return;
	}
	for(int i=0;i<size;i++){
		cin>>vector[i];
		fout.write((char*)(vector+i),4);
	}
	fout.close();
	double length=0;
	ifstream fin("Vector",ios::in|ios::binary);
	try{ 
		 if(!fin)
			throw MyException("File wasn't opened\n");
	while(!fin.eof()){
		int curr;
		fin.read((char*)&curr,4);
		if(fin.eof()) break;
		length+=curr*curr;
	}
	fin.close();
	//cout<<length<<endl;
	length=sqrt(length);
	cout<<"Length of vector: "<<length<<endl;
	}
	catch(MyException e){
		e.print();
	
	}
}
int main() {
	int n,f=1;
	while(f){
		List();
		cin>>n;
		switch(n){
		case 1: Function_with_stack();
				break;
		case 2: Function_with_vector();
				break;
		case 3: f = 0;
				break;
		default: f = 0;
				 break;
		}
	}
	system("pause");
	return 0;
} 
