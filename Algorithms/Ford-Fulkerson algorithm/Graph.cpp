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
Graph::Graph(char* fileName){
	ifstream file(fileName);
	file>>number_of_vertex;
	number_of_edges_max=number_of_vertex*(number_of_vertex-1)/2;
	List_of_edges = new edge [number_of_edges_max];
	number_of_edges = 0;
	if(!List_of_edges) {
		cout<<"Error";
		exit(1);
	}
	int n1,n2,f,c,i=0;
	while(!file.eof()){
		file>>n1>>n2>>c>>f;
		if(n1>number_of_vertex || n1<0 || n2>number_of_vertex || n2<0 ||f>c)
		{	cout<<"Error.\n";
			return;
		}
		 for(int k=0;k<i;k++)
			if(((List_of_edges[k].v1==n1)&&(List_of_edges[k].v2==n2))||((List_of_edges[k].v2==n2)&&(List_of_edges[k].v1==n1)))
				{	cout<<"Error. The same edges\n";
					return;
				}
		  List_of_edges[i].Set_Edge(n1,n2,c,f);
		  number_of_edges++;
		  i++;
		  if(file.eof()){
			  break;
		  }
	}
	Adjacency_matrix=0;
	vertexes = new vertex [number_of_vertex];
	if(!vertexes) {
		cout<<"Error";
		exit(1);
	}
	for(int i=0;i<number_of_vertex;i++)
		vertexes[i].Set_vertex(i);
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
void Graph::Create_Adjacency_Matrix(){
	Adjacency_matrix=Memory(number_of_vertex,number_of_vertex);
	for(int i=0;i<number_of_vertex;i++)
		for(int j=0;j<number_of_vertex;j++)
			Adjacency_matrix[i][j]=0;
	for(int i=0;i<number_of_edges;i++)	
	{
		Adjacency_matrix[List_of_edges[i].v1][List_of_edges[i].v2]=1;
		Adjacency_matrix[List_of_edges[i].v2][List_of_edges[i].v1]=1;
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
	vertexes[given_vertex_index].color_for_BFS=0;
	Queue queue;
	queue.Paste(vertexes[given_vertex_index]);
	while(queue.first){
		vertex tmp = queue.first->date;
		queue.Delete();
		for(int i=0;i<number_of_vertex;i++)
			if(Adjacency_matrix[tmp.v][i]){
				vertex w = vertexes[i];
				if(w.color_for_BFS==-1){
					w.color_for_BFS = 0;
					w.label = tmp.label+1;
					queue.Paste(w);
				}
				vertexes[i]=w;
			}
		tmp.color_for_BFS = 1;
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
void Graph::iniFF(int*& r,int*&p,int*&col){
	r[0]=-2;
	p[0]=0;
	col[0]=-1;
	for(int i=1;i<number_of_vertex;i++){
		r[i]=0;
		p[i]=-1;
		col[i]=-1;
	}
}
bool Graph::isDirect(int vertex1,int vertex2,int &k){
	for(int i=0;i<number_of_edges;i++){
		if(List_of_edges[i].v1==vertex1 && List_of_edges[i].v2==vertex2){
			k=i;
			return 1;
		}
		if(List_of_edges[i].v1==vertex2 && List_of_edges[i].v2==vertex1){
			k=i;
			return 0;
		}
	}
}
void Graph::maxFlow(){
	int* r = new int [number_of_vertex];
	int* p = new int [number_of_vertex];
	int* col = new int [number_of_vertex];
	iniFF(r,p,col);
	int count = 0;
	while(1){
		int tmp=-1;
		for(int i=0;i<number_of_vertex;i++)
			if(col[i]==-1 && p[i]!=-1) 
			{ tmp=i;
			  break;
			}
		if(tmp==-1){
			break;
		}
		
		for(int i=0;i<number_of_vertex;i++){
			if(p[i]==-1 && Adjacency_matrix[i][tmp]){
				int j=0;
					if(isDirect(tmp,i,j) && List_of_edges[j].f<List_of_edges[j].c){
						r[i]=List_of_edges[j].c - List_of_edges[j].f;
						p[i]=tmp;
						
					}
					if(!isDirect(tmp,i,j) && List_of_edges[j].f>0){
						r[i]=List_of_edges[j].f;
						p[i]=tmp;
						
					}
				
			}
		}
		col[tmp]=1;
		if(p[number_of_vertex-1]!=-1){
			int v = p[number_of_vertex-1];
			count = 1;
			while(v){
				v=p[v];
				count++;
			}
			count++;
			int* path = new int[count];
			path[count-1] = number_of_vertex-1;
			for(int k=count-1;k;){
				path[k-1]=p[path[k]];
				k--;
			}
			
			int min=-2;
			for(int i=0;i<count;i++)
				if(min==-2 || (r[path[i]]!=-2 && r[path[i]]<min))
					min=r[path[i]];
			for(int i=0;i<count-1;i++){
				int v1=path[i];
				int v2=path[i+1];
				int j=0;
					if(isDirect(v1,v2,j)){
						List_of_edges[j].f+=min;
					} 
					if(!isDirect(v1,v2,j)){
						List_of_edges[j].f-=min;
					}

			}
			iniFF(r,p,col);
		}

}
	int flow=0;
	int countOfWhite=0;
	for(int i=0;i<number_of_vertex;i++){
		if(col[i]==-1){
			countOfWhite++;
		}
	}
	razrez2=new int [countOfWhite];	
	int countOfBlack=number_of_vertex-countOfWhite;
	razrez=new int[countOfBlack];
	for(int i=0,j=0,k=0;i<number_of_vertex;i++){
		if(col[i]==-1){
			razrez2[j]=i;
			j++;
			
		}
		else{
			razrez[k]=i;
			k++;
		}
	}
	for(int i=0;i<countOfBlack;i++){
		for(int j=0;j<countOfWhite;j++){
			int v1=razrez[i];
			int v2=razrez2[j];
			int k;
			if(Adjacency_matrix[v1][v2]){
				if(isDirect(v1,v2,k)){
							flow+=List_of_edges[k].f;
							
						}
			}
		
	}
}
	
	cout<<endl<<flow<<endl;
	cout<<"The vertices from the first :\n";
	for(int i=0;i<countOfBlack;i++){
		cout<<razrez[i]<<' ';
	}
	cout<<endl<<"The vertices from the second :\n";
	for(int i=0;i<countOfWhite;i++){
		cout<<razrez2[i]<<' ';
	}
	cout<<endl;
}
            
     



