#include"Graph.h"
int main(){
	Graph graph(5);
	graph.Create_Graph();
	graph.Create_Adjacency_Matrix();
	graph.Show_Adjacency_Matrix();
	graph.Create_Incidence_Matrix();
	graph.Show_Incidence_Matrix();
	graph.Create_Adjacency_List();
	graph.Show_Adjacency_List();
	graph.BFS();
	graph.Show_The_Result_Of_BFS();
	graph.Define_Coherence();
	graph.Define_Dipartition();
	system("pause");
	return 0;
}

