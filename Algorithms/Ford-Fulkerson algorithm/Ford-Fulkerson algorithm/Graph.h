#include<iostream>
#include<fstream>
using namespace std;
struct vertex {
	int v;
	int firstLabel;
	int secondLabel;
	int label;
	int color;
	int color_for_BFS;
	vertex() {
		firstLabel=-2;
		color_for_BFS=-1;
		color=0;
		label=-2;
	}
	void Set_vertex(int v1) {v=v1;}
};
struct edge{
	int c;
	int f;
	int v1,v2;
	edge(){
		v1=0;
		v2=0;
		c=0;
		f=0;
	}
	void Set_Edge(int _v1,int _v2,int _c,int _f){
		v1=_v1;
		v2=_v2;
		f=_f;
		c=_c;
	}
};
class Graph{
	int number_of_vertex;
	int number_of_edges_max;
	int number_of_edges;
	int** Adjacency_matrix;
	vertex* vertexes;
	edge* List_of_edges;
	int* razrez;
	int* razrez2;
public:
	Graph(char*);
	~Graph();
	int** Memory(int,int);
	void Create_Adjacency_Matrix();
	void Show_Adjacency_Matrix();
	void BFS(int given_vertex_index=0);
	void Show_The_Result_Of_BFS();
	int Define_Coherence();
	void maxFlow();
	void iniFF(int*&,int*&,int*&);
	bool isDirect(int,int,int&);	
};