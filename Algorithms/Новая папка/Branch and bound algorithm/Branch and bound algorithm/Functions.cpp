#include"Graph.h"
//#include"Tree.h"
void Tree::Push(node* &root1,int** & matrix, int value,int* edge,bool hasEdge){
	if(!root1) {
		root1=new node(matrix,0,value,edge,hasEdge); 
		return;
	}
	/*
	if(edge == 0){
		root1=new node(matrix,value,edge,hasEdge); 
		return;
	}*/
	//if(n>=root1->key) 
	//if(root1->edge == 0){
		if(hasEdge){
			//Push(root1->left,matrix,value,edge,hasEdge);
			root1->left = new node(matrix,root1,value,edge,hasEdge);
			return;
		}
		else{
			//Push(root1->right,matrix,value,edge,hasEdge);
			root1->right = new node(matrix,root1,value,edge,hasEdge);
			return;
		}
	//}
		/*
	if(matrix[edge[0]][edge[1]] == INFINITY)
		Push(root1->right,matrix,value,edge,hasEdge);
	else
		Push(root1->left,matrix,value,edge,hasEdge);
}*/
}
void Tree::Print(node*root1,int t){
	if(!root1) {return;}
	Print(root1->right,2*t);
	cout.width(t);
	cout<<root1->value;
	if(root1->edge)
	cout<<' '<<root1->edge[0]+1<<' '<<root1->edge[1]+1;
	//cout<<' '<<root1->left<<' '<<root1->right;

	cout<<endl;
	/*
	for(int i = 0; i<5;i++){
		for(int j = 0; j<5;j++){
			cout.width(3);
			cout<<root1->matrix[i][j];
		}
		cout<<endl;
	}*/
	Print(root1->left,2*t);
}
Graph::Graph(char* fileName) {
	ifstream file(fileName);
	if(!file){
		throw exception("File cannot be opened");
	}
	if(file.eof()){
		throw exception("The end of file");
	}
	file>>numberOfVertices;
	if(numberOfVertices < 0){
		throw exception("number of vertices must be positive");
	}

	matrixOfWeights = new int * [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++){
		matrixOfWeights[i] = new int [numberOfVertices];
	}
	for(int i = 0; i < numberOfVertices; i++) {
		for(int j = 0; j < numberOfVertices; j++){
			if(file.eof()){
				throw exception("The end of file");
			}
			file>>matrixOfWeights[i][j];
			if(matrixOfWeights[i][j] < 0){
				throw exception("Weights must be positive");
			}
			if(i == j) {
				matrixOfWeights[i][j] = INFINITY;
			}
		}
	}
}
void Graph::showMatrix(){
	for(int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++){
			cout.width(4);
			cout<<matrixOfWeights[i][j];
		}
		cout<<endl;
	}
}
int Graph::buildNewMatrix(int** matrix) {
	int * minInLine = new int [numberOfVertices];
	int * minInColumn = new int [numberOfVertices];
	for( int i = 0; i < numberOfVertices; i++){
		int min = INFINITY;
		for(int j = 0; j < numberOfVertices; j++){
			if((min == INFINITY || matrix[i][j] < min) && i!=j && matrix[i][j] != INFINITY){
				min = matrix[i][j];
			}
		}
		minInLine[i] = min;
	}
	for( int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++){
			if( i != j && matrix[i][j] != INFINITY && minInLine[i] != INFINITY){
				matrix[i][j] -= minInLine[i];
				}
		}
	}
	for( int i = 0; i < numberOfVertices; i++){
		int min = INFINITY;
		for(int j = 0; j < numberOfVertices; j++){
			if((min == INFINITY || matrix[j][i] < min) && i!=j && matrix[j][i] != INFINITY) {
				min = matrix[j][i];
			}
		}
		minInColumn[i] = min;
	}
	for( int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++){
			if( i != j && matrix[j][i] != INFINITY && minInColumn[i] != INFINITY){
				matrix[j][i] -= minInColumn[i];
			}
		}
	}
	int r = 0;
	for(int i = 0; i <numberOfVertices; i++){/*
		if(minInLine[i] == INFINITY || minInColumn[i] == INFINITY ){
				return INFINITY;
			}*/
		if(minInLine[i] != INFINITY)
			r += minInLine[i];
		if( minInColumn[i] != INFINITY)
			r += minInColumn[i];
	}
	return r;
}
int Graph::countFine(int firstIndex, int secondIndex, int** & matrix){
	int minInColumn = INFINITY;
	for(int i = 0; i < numberOfVertices; i++) {
		if((minInColumn == INFINITY || matrix[i][secondIndex] < minInColumn) && i != firstIndex && i != secondIndex && matrix[i][secondIndex] != INFINITY)
			minInColumn = matrix[i][secondIndex];
	}
	int minInLine = INFINITY;
	for(int i = 0; i < numberOfVertices; i++) {
		if((minInLine == INFINITY || matrix[firstIndex][i] < minInLine) && i != secondIndex && i != firstIndex && matrix[firstIndex][i] != INFINITY)
			minInLine = matrix[firstIndex][i];
	}
	if(minInLine == INFINITY || minInColumn == INFINITY)
		return INFINITY;
	return (minInLine + minInColumn);
}
int Graph::findMaxFine(int& firstIndex, int & secondIndex, int** & matrix){
	int maxFine = -1;
	int fine;
	for( int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++){
			if(matrix[j][i] == 0){
				fine = countFine(j,i,matrix);
				if(fine > maxFine) {
					firstIndex = j;
					secondIndex = i;
					maxFine = fine;
				}
			}
		}
	}
	return maxFine;
}
int** Graph::buildMatrixWithEdge(int**& matrix, int* edge) {
	int** newMatrix = new int* [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++){
		newMatrix[i] = new int [numberOfVertices];
	}
	for(int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++) {
			if( i == edge[0]){
				newMatrix[i][j] = INFINITY;
				continue;
			}
			if( j == edge[1]){
				newMatrix[i][j] = INFINITY;
				continue;
			}
			if( i == edge[1] && j == edge[0]){
				newMatrix[i][j] = INFINITY;
				continue;
			}
		newMatrix[i][j] = matrix[i][j];
		}
	}
	return newMatrix;
}
int** Graph::buildMatrixWithoutEdge(int**& matrix, int* edge) {
	int** newMatrix = new int* [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++){
		newMatrix[i] = new int [numberOfVertices];
	}
	for(int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++) {
			if( i == edge[0] && j == edge[1]){
				newMatrix[i][j] = INFINITY;
				continue;
			}
		newMatrix[i][j] = matrix[i][j];
		}
	}
	return newMatrix;
}
void Graph::branchAndBoundAlgorithm(){
	int value = buildNewMatrix(matrixOfWeights);
	showMatrix();
	tree.Push(tree.Get_Root(),matrixOfWeights,value);
	//int * edge = new int [2];
	//findMaxFine(edge[0],edge[1],matrixOfWeights);
	//cout<<edge[0]<<edge[1]<<endl;
	int i=0;
	while(i!=6) {
		node* leaveWithMinValue = tree.findLeaveWithMinValue();
		int firstIndex, secondIndex;
		int fine = findMaxFine(firstIndex, secondIndex, leaveWithMinValue->matrix);
		int edge[2] = {firstIndex,secondIndex};
		cout<<edge[0]<<edge[1]<<endl;
		int** matrixWithEdge = buildMatrixWithEdge(leaveWithMinValue->matrix,edge);
		int value = buildNewMatrix(matrixWithEdge) + leaveWithMinValue->value;
		tree.Push(leaveWithMinValue,matrixWithEdge,value,edge,true);
		int** matrixWithoutEdge = buildMatrixWithoutEdge(leaveWithMinValue->matrix,edge);
		value = leaveWithMinValue->value + fine;
		buildNewMatrix(matrixWithoutEdge);
		tree.Push(leaveWithMinValue,matrixWithoutEdge,value,edge,false);
		i++;
	}
	tree.Print(tree.Get_Root());
	showResult();
}
node* Tree::findLeaveWithMinValue() {
	List l;
	Obhod(root,l);
	return  l.findMin();	
}
void Tree::Obhod(node*root1, List & l){
	if(!root1) return;
	if(root1->left == 0 && root1->right == 0){
		l.push(root1);
	}
	Obhod(root1->left,l);
	Obhod(root1->right,l);
}
void Graph::showResult(){
	node* current = tree.findLeaveWithMinValue();
	while(current->previous) {
		if(current->hasEdge) {
			cout<<current->edge[0]+1<<' '<<current->edge[1]+1;
		}
		cout<<endl;
		current = current->previous;
	}
}
