#include"Graph.h"
Graph::Graph(int numberOfVertices) {
	this->numberOfVertices = numberOfVertices;
	adjacencyMatrix = new int* [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++) {  
		adjacencyMatrix[i] = new int [numberOfVertices];
		adjacencyMatrix[i][i] = 0;
		for(int j = 0; j < i; j++) {
			adjacencyMatrix[i][j] = rand()%2;
			//adjacencyMatrix[i][j] = 0;
			adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
		}
	}
	vertices = new vertex [numberOfVertices];
}
Graph::Graph(int numberOfVertices,int p) {
	this->numberOfVertices = numberOfVertices;
	adjacencyMatrix = new int* [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++) {  
		adjacencyMatrix[i] = new int [numberOfVertices];
		adjacencyMatrix[i][i] = 0;
		for(int j = 0; j < i; j++) {
			if(rand()%100 < p) {
				adjacencyMatrix[i][j] = 1;
				adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
			}
			else {
				adjacencyMatrix[i][j] = 0;
				adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
			}
		}
	}
	vertices = new vertex [numberOfVertices];
}
Graph::Graph(char* filename) {
	ifstream file(filename);
	file>>numberOfVertices;
	adjacencyMatrix = new int* [numberOfVertices];
	for(int i = 0; i < numberOfVertices; i++) {  
		adjacencyMatrix[i] = new int [numberOfVertices];
		for(int j = 0; j < numberOfVertices; j++) {
			file>>adjacencyMatrix[i][j];
		}
	}
	vertices = new vertex [numberOfVertices];
}
int Graph::sequentialColoring() {
	for(int i = 0; i < numberOfVertices; i++) {
		vertices[i].color = -1;
	}
	vertices[0].color = 1;
	int currentColor;
	int maxColor = 0;
	int* colors = new int [numberOfVertices];
	int numberOfColors = 0;
	for(int i = 0; i < numberOfVertices; i++) {
		currentColor = 1;
		numberOfColors = 0;
		for(int j = 0; j < numberOfVertices; j++) {
			if(adjacencyMatrix[i][j] == 1) {
				colors[numberOfColors] = vertices[j].color;
				numberOfColors++;
			}
		}
		for(int t = 0; t < numberOfVertices; t++) {
			int flag = true;
			for(int k = 0; k < numberOfColors; k++) {
				if(currentColor == colors[k]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				vertices[i].color = currentColor;
				break;
			}
			else {
				currentColor++;
			}
		}
		if(currentColor > maxColor) {
			maxColor = currentColor;
		}
		//cout<<i + 1<<" - "<<vertices[i].color<<endl;
	}
	return maxColor;
}
int Graph::independentSetsColoring() {
	for(int i = 0; i < numberOfVertices; i++) {
		vertices[i].color = -1;
	}
	int * independentSet;
	int** currentMatrix = adjacencyMatrix;
	int currentColor = 1;
	int numberOfVerticesInSet;
	while(1) {
		independentSet = findIndependentSet(currentMatrix, numberOfVerticesInSet);
		for(int i = 0; i < numberOfVerticesInSet; i++) {
			vertices[independentSet[i]].color = currentColor;
		}
		buildNewMatrix(currentMatrix,independentSet,numberOfVerticesInSet);
		/*
		for(int i = 0; i < numberOfVertices; i++) {
		for(int j = 0; j < numberOfVertices; j++) {
			cout<<currentMatrix[i][j]<<' ';
		}
		cout<<endl;
	}*/
		if(isEmptyGraph(currentMatrix)) {
			break;
		}
		currentColor++;
	}
	return currentColor;
}
int* Graph::findIndependentSet(int** matrix,int& numberOfVerticesInSet) {
	int firstVertex = chooseFirstVertex(matrix);
	int* result = new int [numberOfVertices];
	for(int i = 1; i < numberOfVertices; i++) {
		result[i] = -1;
	}
	result[0] = firstVertex;
	int count = 1;
	bool flag;
	for(int i = 0; i < numberOfVertices; i++) {
		flag = true;
		for(int j = 0; j < count; j++) {
			if(matrix[i][result[j]] == 1 || i == result[j] || matrix[i][result[j]] == -1) {
				flag = false;
				break;
			}
		}
		if(flag) {
			result[count] = i;
			count++;
		}
	}
	int* finalResult = new int [count];
	for(int i = 0; i < count; i++) {
		finalResult[i] = result[i];
	}
	delete [] result;
	numberOfVerticesInSet = count;
	return finalResult;
}
bool Graph::isEmptyGraph(int** matrix) {
	for(int i = 0; i < numberOfVertices; i++) {
		if(vertices[i].color == -1) {
			return false;
		}
	}
	/*
	for(int i = 0; i < numberOfVertices; i++) {
		for(int j = 0; j < numberOfVertices; j++) {
			//cout<<matrix[i][j]<<' ';
			if(matrix[i][j] != -1) {
				return false;
			}
		}
		//cout<<endl;
	}*/
	return true;
}
void Graph::buildNewMatrix(int**& matrix,int* independentSet,int numberOfVerticesInSet) {
	for(int i = 0; i < numberOfVerticesInSet; i++) {
		int k = independentSet[i];
		for(int j = 0; j < numberOfVertices; j++) {
			matrix[k][j] = -1;
			matrix[j][k] = -1;
		}
}
}
int Graph::chooseFirstVertex(int** matrix) {
	for(int i = 0; i < numberOfVertices; i++) {
		if(vertices[i].color == -1) {
			return i;
		}
	}
	/*
	for(int i = 0; i < numberOfVertices; i++) {
		for(int j = 0; j < numberOfVertices;j++) {
			if(matrix[i][j] != -1) {
				return i;
			}
		}
	}*/
}
void Graph::showColors() {
	for(int i = 0; i < numberOfVertices; i++) {
		cout<<i + 1<<" - "<<vertices[i].color<<endl;
	}
}
void Graph::showMatrix() {
		for(int i = 0; i < numberOfVertices; i++) {
		for(int j = 0; j < numberOfVertices; j++) {
			cout<<adjacencyMatrix[i][j]<<' ';
		}
		cout<<endl;
	}
}