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
class Graph{
	int number_of_vertex;
	int number_of_edges_max;
	int number_of_edges;
	int** List_of_edges;
	int** Adjacency_matrix;
	int** Incidence_Matrix;
	node** Adjacency_List; 
public:
	Graph(int n=0);
	int** Memory(int,int);
	void Create_Graph();
	void Create_Adjacency_Matrix();
	void Show_Adjacency_Matrix();
	void Create_Incidence_Matrix();
	void Show_Incidence_Matrix();
	void Create_Adjacency_List();
	void Show_Adjacency_List();
};