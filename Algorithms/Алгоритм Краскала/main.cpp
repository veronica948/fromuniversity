#include"Graph.h"
int main(){
	Graph graph(5);
	graph.Create_Graph();
	if(!graph.Define_Coherence()){
		cout<<"Graph is not coherent\n";
		system("pause");
		exit(1);
	}
	graph.Algorithm();
	system("pause");
	return 0;
}