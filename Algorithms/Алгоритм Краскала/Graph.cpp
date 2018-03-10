#include"Graph.h"
#include"queue.h"
void Queue::Paste(vertex n) {
	nodes*a=new nodes(n);
	if(!first) { last=a; first=last;}
	else
	{
		last->next=a;
		last=a;
	}
}
void Queue::Delete() {
	if(first)
	{
	nodes* a=first; 
	first=first->next;
	delete a;
	}
}
Queue::~Queue() {
	while(first)
		Delete();
}
int** Graph::Memory(int a,int b){
	int**A=new int* [a];
	  if(!A) 
      {
		  cout<<"Error"; exit(1);
	  }
	for(int i=0;i<a;i++)
	{  A[i]=new int [b];
			if(!A[i]) 
			{
				cout<<"Error"; 
				exit(1);
			}
	}
	return A;
}
Graph::Graph(int n){
	number_of_vertex=n;
	number_of_edges=0;
	number_of_edges_max=number_of_vertex*(number_of_vertex-1)/2;
	List_of_edges = new edge [number_of_edges_max];
	if(!List_of_edges) {
		cout<<"Error";
		exit(1);
	}
	Adjacency_matrix=0;
	vertexes = new vertex [number_of_vertex];
	if(!vertexes) {
		cout<<"Error";
		exit(1);
	}
	for(int i=0;i<number_of_vertex;i++)
		vertexes[i].Set_v(i);
}
Graph::~Graph(){
	delete []List_of_edges;
	delete [] vertexes;
	if(Adjacency_matrix){
		for(int i=0;i<number_of_vertex;i++)
			delete []Adjacency_matrix[i];
		delete []Adjacency_matrix;
	}
}
void Graph::Create_Graph(){
	int n,a,b,p=1;
	cout<<"Enter the number of edges.Max is "<<number_of_edges_max<<endl;
	cin>>n;
	if(n>number_of_edges_max)
		{cout<<"Error. You enter number of edges more than max\n";
		return;
	}
	cout<<"Enter the edges.Use the numbers from 1 to "<<number_of_vertex<<endl;
	for(int i=0;i<n;)
	{	 int w;
		 cin>>a>>b;
		 cout<<"w= ";
		 cin>>w;
		 for(int k=0;k<i;k++)
			if(((List_of_edges[k].v1==a)&&(List_of_edges[k].v2==b))||((List_of_edges[k].v2==b)&&(List_of_edges[k].v1==a)))
				{p=0; break;}
		 if(!p||a<1||b<1||a>number_of_vertex||b>number_of_vertex||a==b)
			 cout<<"Error. Try again\n";
		 else{
			 List_of_edges[i].Set_Edge(a,b,w);
			 i++;
			 number_of_edges++;
		 }
		 p=1;
	}
}
void Graph::Create_Adjacency_Matrix(){
	Adjacency_matrix=Memory(number_of_vertex,number_of_vertex);
	for(int i=0;i<number_of_vertex;i++)
		for(int j=0;j<number_of_vertex;j++)
			Adjacency_matrix[i][j]=0;
	for(int i=0;i<number_of_edges;i++)	
	{
		Adjacency_matrix[List_of_edges[i].v1-1][List_of_edges[i].v2-1]=1;
		Adjacency_matrix[List_of_edges[i].v2-1][List_of_edges[i].v1-1]=1;
	}
}
void Graph::Show_Adjacency_Matrix(){
	if(!Adjacency_matrix) Create_Adjacency_Matrix();
	cout<<"Adjacency Matrix:\n";
	for(int i=0;i<number_of_vertex;i++){
		for(int j=0;j<number_of_vertex;j++)
			cout<<Adjacency_matrix[i][j]<<' ';
		cout<<endl;
	}
}
void Graph::BFS(int given_vertex_index){
	if(!Adjacency_matrix) Create_Adjacency_Matrix();
	vertexes[given_vertex_index].label=0;
	vertexes[given_vertex_index].color=0;
	Queue queue;
	queue.Paste(vertexes[given_vertex_index]);
	while(queue.first){
		vertex tmp = queue.first->date;
		queue.Delete();
		for(int i=0;i<number_of_vertex;i++)
			if(Adjacency_matrix[tmp.v][i]){
				vertex w = vertexes[i];
				if(w.color==-1){
					w.color = 0;
					w.label = tmp.label+1;
					queue.Paste(w);
				}
				vertexes[i]=w;
			}
		tmp.color = 1;
	}
}
void Graph::Show_The_Result_Of_BFS(){

	for(int i=0;i<number_of_vertex;i++)
		cout<<vertexes[i].label<<' ';
	cout<<endl;
}
int Graph::Define_Coherence(){
	BFS();
	int is_coherent=1;
	for(int i=0;i<number_of_vertex;i++)
		if(vertexes[i].label==-2){
			is_coherent=0;
			return 0;
			break;
		}
	return 1;
}
void swap(edge &a, edge &b)
{
        edge tmp;
        tmp  = a;
        a = b;
        b = tmp;
}
int Findq(edge* a, int p, int r)
{
        edge x;
		int q;
        x = a[r];
        q = p;
        for (int i=p; i<=r;i++)
                {
	        if (a[i].w<=x.w)
	                {
                        swap(a[i],a[q]);
                        q++;
                	}
                }
        q--;
        return q;
}
void Quicksort(edge* a,int p, int r)
{
        int q;
        if (p < r)
                {
                q = Findq (a, p, r);
                Quicksort (a, p, q-1);
                Quicksort (a, q+1, r);
                }
}
void Graph::Algorithm(){
	Quicksort(List_of_edges,0,number_of_edges-1);
	int * Array = new int [number_of_vertex]; 
	for(int i=0;i<number_of_vertex;i++)
		Array[i] = i;

	/*cout<<"Sort"<<endl;
	for(int i=0;i<number_of_edges;i++){
		cout<<List_of_edges[i].v1<<' '<<List_of_edges[i].v2<<' ';
		cout<<endl;
	}*/

	List_of_edges_of_skillet = new edge [number_of_vertex-1];
	if(!List_of_edges_of_skillet) {
		cout<<"Error";
		exit(1);
	}
	int i=0,index=0;
	while(index!=number_of_vertex-1){
		if(Array[List_of_edges[i].v1-1] != Array[List_of_edges[i].v2-1]){
			List_of_edges_of_skillet[index] = List_of_edges[i];
			index++;
			int t = Array[List_of_edges[i].v1-1];
			int r = Array[List_of_edges[i].v2-1];
			for(int k=0;k<number_of_vertex;k++)
				if(Array[k] == r)
					Array[k] = t;			
		}
		i++;
	}
	/*cout<<endl;
	for(int i=0;i<number_of_vertex;i++)
		cout<<Array[i];*/
	cout<<endl;
	cout<<"The result:\n";
	for(int i=0;i<index;i++){
		cout<<List_of_edges_of_skillet[i].v1<<' '<<List_of_edges_of_skillet[i].v2<<' ';
		cout<<endl;
	}
	//cout<<"index = "<<index;
	delete [] Array;
}

