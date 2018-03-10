#include"Graph.h"
int main(){
	Graph graph(6);
	graph.Create_Graph();
	graph.Create_Adjacency_Matrix();
	if(!graph.Define_Coherence()){
		cout<<"Graph is not coherent\n";
		system("pause");
		exit(1);
	}
	graph.Eulerian_cycle();
	system("pause");
	return 0;
}
