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
Graph::Graph(int n){
	number_of_vertex=n;
	number_of_edges=0;
	number_of_edges_max=number_of_vertex*(number_of_vertex-1)/2;
	List_of_edges=Memory(number_of_edges_max,2);
	Adjacency_matrix=0;
	Incidence_Matrix=0;
	Adjacency_List=0;
	vertexes = new vertex [number_of_vertex];
	for(int i=0;i<number_of_vertex;i++)
		vertexes[i].Set_v(i);
}
Graph::~Graph(){
	for(int i=0;i<2;i++)
		delete []List_of_edges[i];
	delete []List_of_edges;
	delete [] vertexes;
	if(!Adjacency_matrix){
		for(int i=0;i<number_of_vertex;i++)
			delete []Adjacency_matrix[i];
		delete []Adjacency_matrix;
	}
	if(!Incidence_Matrix){
		for(int i=0;i<number_of_edges;i++)
			delete []Incidence_Matrix[i];
		delete []Incidence_Matrix;
	}
	if(!Adjacency_List)
		for(int i=0;i<number_of_vertex;i++){
			node* first=Adjacency_List[i];
			while(first){
				node* a=first; 
				first=first->next;
				delete a;
			}
		}
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
void Graph::Create_Graph(){
	int n,a,b,p=1;
	cout<<"Enter the number of edges.Max is "<<number_of_edges_max<<endl;
	cin>>n;
	if(n>number_of_edges_max)
		cout<<"Error. You enter number of edges more than max\n";
	cout<<"Enter the edges.Use the numbers from 1 to "<<number_of_vertex<<endl;
	for(int i=0;i<n;)
	{
		 cin>>a>>b;
		 for(int k=0;k<i;k++)
			if(((List_of_edges[k][0]==a)&&(List_of_edges[k][1]==b))||((List_of_edges[k][0]==b)&&(List_of_edges[k][1]==a)))
				{p=0; break;}
		 if(!p||a<1||b<1||a>number_of_vertex||b>number_of_vertex||a==b)
			 cout<<"Error. Try again\n";
		 else{
			 List_of_edges[i][0]=a;
			 List_of_edges[i][1]=b;
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
		Adjacency_matrix[List_of_edges[i][0]-1][List_of_edges[i][1]-1]=1;
		Adjacency_matrix[List_of_edges[i][1]-1][List_of_edges[i][0]-1]=1;
	}
}
void Graph::Show_Adjacency_Matrix(){
	if(!Adjacency_matrix){
		cout<<"It wasn't created\n";
		return;
	}
	cout<<"Adjacency Matrix:\n";
	for(int i=0;i<number_of_vertex;i++){
		for(int j=0;j<number_of_vertex;j++)
			cout<<Adjacency_matrix[i][j]<<' ';
		cout<<endl;
	}
}
void Graph::Create_Incidence_Matrix(){
	Incidence_Matrix=Memory(number_of_vertex,number_of_edges);
	for(int i=0;i<number_of_vertex;i++)
		for(int j=0;j<number_of_edges;j++)
			Incidence_Matrix[i][j]=0;
	for(int i=0;i<number_of_edges;i++){
		int p=List_of_edges[i][0];
		int t=List_of_edges[i][1];
		Incidence_Matrix[p-1][i]=1;
		Incidence_Matrix[t-1][i]=1;
	}
}
void Graph::Show_Incidence_Matrix(){
	if(!Incidence_Matrix){
		cout<<"It wasn't created\n";
		return;
	}
	cout<<"Incidence Matrix:\n";
	for(int i=0;i<number_of_vertex;i++){
		for(int j=0;j<number_of_edges;j++)
			cout<<Incidence_Matrix[i][j]<<' ';
		cout<<endl;
	}
}
void Graph::Create_Adjacency_List(){
	Adjacency_List = new node * [number_of_vertex];
	for(int i=0;i<number_of_vertex;i++)
		Adjacency_List[i]=0;
	for(int i=0;i<number_of_edges;i++){
		int p=List_of_edges[i][0];
		int t=List_of_edges[i][1];
		if(Adjacency_List[p-1]){
			node* find_last=Adjacency_List[p-1];
			while(find_last->next)
				find_last=find_last->next;
			find_last->next=new node (t);
		}
		if(!Adjacency_List[p-1]){
			Adjacency_List[p-1] = new node(t);
		}
		
		if(Adjacency_List[t-1]){
			node* find_last=Adjacency_List[t-1];
			while(find_last->next)
				find_last=find_last->next;
			find_last->next=new node (p);
		}
		if(!Adjacency_List[t-1]){
			Adjacency_List[t-1] = new node(p);
		}
	}
}
void Graph::Show_Adjacency_List(){
	cout<<"Adjacency List:\n";
	for(int i=0;i<number_of_vertex;i++){
		if(!Adjacency_List[i])
			cout<<'-';
		else{
			node* now = Adjacency_List[i];
			while(now){
				cout<<now->v<<' ';
				now=now->next;
			}
		}
		cout<<endl;
	}
}
void Graph::BFS(int given_vertex_index){
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
void Graph::Define_Coherence(){
	BFS();
	int is_coherent=1;
	for(int i=0;i<number_of_vertex;i++)
		if(vertexes[i].label==-2){
			is_coherent=0;
			break;
		}
	if(is_coherent)
		cout<<"Graph is coherent\n";
	else 
		cout<<"Graph is not coherent\n";
}
void Graph::Define_Dipartition(){
	for(int i=0;i<number_of_vertex;i++)
		if(vertexes[i].label==-2) BFS(i);
	int is_dip=1;
	for(int i=0;i<number_of_vertex;i++)
		for(int j=0;j<number_of_vertex;j++)
		if(Adjacency_matrix[i][j]==1){
			if((vertexes[i].label%2 && vertexes[j].label%2)||(!vertexes[i].label%2 && !vertexes[j].label%2))
				{is_dip=0; break;}
		}
	if(is_dip)
		cout<<"True";
	else
		cout<<"False";
	cout<<endl;
}


