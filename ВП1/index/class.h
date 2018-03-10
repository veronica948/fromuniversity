#include<iostream>
using namespace std;
class Archive {
	int n;
	int*a;
public:
	Archive() {n=5; a=new int [n];}
	Archive(int m) {n=m; a=new int [n];}
	void Create_Archive() {for(int i=0;i<n;i++) {a[i]=rand()%10;}}
	~Archive() {delete []a;}
	int operator [] (int i)
	{return a[i];}
};