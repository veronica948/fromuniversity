#include<iostream>
#include<math.h>
using namespace std;
class Hash {
	int *a;
public:
	Hash() {a=new int [128];
			for(int i=0;i<128;i++)
				a[i]=-8;
	
	}
	void Push(int n);
	int Search(int n);
	void Delete(int n);
	void Show();
	~Hash(){
		delete []a;
	}
};