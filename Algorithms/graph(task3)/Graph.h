#include<iostream>
using namespace std;
struct vertex {
	int time_begin;
	int time_end;
	int color;
	int v;
	vertex() {
		time_begin=0;
		time_end=0;
		color=-1;
	}
	void Set_v(int v1) {v=v1;}
};
class Graph{
	int number_of_vertex;
	int number_of_edges_max;
	int number_of_edges;
	int** List_of_edges;
	int** Adjacency_matrix;
	vertex* vertexes;
public:
	Graph(int n=0);
	~Graph();
	int** Memory(int,int);
	void Create_Graph();
	void Create_Adjacency_Matrix();
	void Show_Adjacency_Matrix();
	void DFS();
	void Visit(vertex&, int&);
};