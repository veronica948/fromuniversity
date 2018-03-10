#include<iostream>
using namespace std;
struct vertex {
	int v;
	int label;
	int color;
	vertex() {
		label=-2;
		color=-1;
	}
	void Set_v(int v1) {v=v1;}
};
struct edge{
	int w;
	int v1,v2;
	edge(){
		v1=0;
		v2=0;
		w=0;
	}
	void Set_Edge(int _v1,int _v2,int _w){
		v1=_v1;
		v2=_v2;
		w=_w;
	}
};
class Graph{
	int number_of_vertex;
	int number_of_edges_max;
	int number_of_edges;
	edge* List_of_edges;
	int** Adjacency_matrix;
	vertex* vertexes;
	int** Array;
public:
	Graph(int n=0);
	~Graph();
	int** Memory(int,int);
	void Create_Graph();
	void Create_Adjacency_Matrix();
	void Show_Adjacency_Matrix();
	void BFS(int given_vertex_index=0);
	void Show_The_Result_Of_BFS();
	int Define_Coherence();
	void Algorithm();
	void Find_Way(int,int);
};