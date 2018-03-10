#include<iostream>
#include<stack>
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
	int n;
	int label;
	edge(){
		label=0;
	}
	void Set_e(int _e){
		n=_e;
	}
};
class Graph{
	int number_of_vertex;
	int number_of_edges_max;
	int number_of_edges;
	int** List_of_edges;
	int** Adjacency_matrix;
	int** Incidence_Matrix;
	vertex* vertexes;
public:
	Graph(int n=0);
	~Graph();
	int** Memory(int,int);
	void Create_Graph();
	void Create_Adjacency_Matrix();
	void Show_Adjacency_Matrix();
	void Create_Incidence_Matrix();
	void Show_Incidence_Matrix();
	void BFS(int given_vertex_index=0);
	void Show_The_Result_Of_BFS();
	int Define_Coherence();
	void Eulerian_cycle();
};