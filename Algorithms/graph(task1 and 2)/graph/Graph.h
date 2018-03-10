#include<iostream>
using namespace std;
struct node {
	int v;
	node* next;
	node(){};
	node(int v1){
		v=v1;
		next=0;
	}
};
struct vertex {
	int label;
	int color;
	int v;
	vertex() {
		label=-2;
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
	int** Incidence_Matrix;
	node** Adjacency_List; 
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
	void Create_Adjacency_List();
	void Show_Adjacency_List();
	void BFS(int given_vertex_index=0);
	void Show_The_Result_Of_BFS();
	void Define_Coherence();
	void Define_Dipartition();
};