#include"automat.h"
Field::Field(char* fileName) {
	ifstream file(fileName);
	file>>n;
	file>>m;
	matrix=new int* [n];
	for(int j=0;j<n;j++){
		matrix[j]=new int [m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			file>>matrix[i][j];
		}
	file.close();
}
void Field::liveCycle(){
	int** A;
	A=new int* [n];
	for(int j=0;j<n;j++){
		A[j]=new int [m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			A[i][j]=matrix[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int number = countNeighbours(i,j,A);
			if(matrix[i][j]==1 && (number>3 || number<2)){
				matrix[i][j]=0;
			}
			if(matrix[i][j]==0 && number==3){
				matrix[i][j]=1;
			}
		}
	for(int j=0;j<n;j++)
		delete [] A[j];
	delete []A;
	
}
void Field::fulfil(){
	cout<<"Finish - 0.\n";
	showField();
	int count = 0;
	char v;
	cin>>v;
	while(v!='0'){
		system("cls");
		cout<<"Finish - 0.\n";
		liveCycle();
		count++;
		showField();
		cin>>v;		
	}
	cout<<endl<<count<<endl;
}
void Field::showField(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
			
}
int Field::countNeighbours(int _i,int _j,int**A){
	
	int count=0;
	for(int i=_i-1;i<=_i+1;i++){
		for(int j=_j-1;j<=_j+1;j++){
			if(i==_i && j==_j){
				continue;
			}
			int x =(n+i)%n;
			int y =(m+j)%m;
			if(A[x][y]==1)
				count++;
		}
	}
	return count;
}

