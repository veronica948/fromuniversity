#include"Graph.h"
int main(){
	Graph graph("Graph.txt");
	if(!graph.Define_Coherence()){
		cout<<"Graph is not coherent\n";
		system("pause");
		exit(1);
	}
	//graph.Show_Adjacency_Matrix();
	graph.maxFlow();
	system("pause");
	return 0;
}