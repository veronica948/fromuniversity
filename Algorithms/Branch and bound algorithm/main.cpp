#include"Graph.h"
int main() {
	try {
		Graph graph("graph.txt");
		graph.showMatrix();
		graph.branchAndBoundAlgorithm();
	}
	catch(exception e) {
		cout<<e.what()<<endl;
	}
	catch(bad_alloc e){
		cout<<"Problems with allocation of memory"<<endl;
	}
	system("pause");
	return 0;
}