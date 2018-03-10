#include"Graph.h"
int main(){
	Graph graph(6);
	graph.Create_Graph();
	graph.Show_Adjacency_Matrix();
	if(!graph.Define_Coherence()){
		cout<<"Graph is not coherent\n";
		system("pause");
		exit(1);
	}
	//graph.Floyd_Algorithm();
	graph.Best_Place();
	int f=1;
	while(f){
		int a,b;
		cout<<"Enter the vertexes\n";
		cin>>a>>b;	
		graph.Find_Way(a,b);
		cout<<"More - 1,exit - 0";
		cin>>f;
	}
	system("pause");
	return 0;
}