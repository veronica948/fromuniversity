#include"Graph.h"
int main(){
	Graph graph(4);
	graph.Create_Graph();
	graph.Create_Adjacency_Matrix();
	graph.Show_Adjacency_Matrix();
	graph.Create_Incidence_Matrix();
	graph.Show_Incidence_Matrix();
	graph.Create_Adjacency_List();
	graph.Show_Adjacency_List();
	system("pause");
	return 0;
}

