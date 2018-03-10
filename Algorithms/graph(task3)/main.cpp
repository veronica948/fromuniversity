#include"Graph.h"
int main(){
	Graph graph(5);
	graph.Create_Graph();
	graph.Create_Adjacency_Matrix();
	graph.Show_Adjacency_Matrix();
	graph.DFS();
	system("pause");
	return 0;
}

