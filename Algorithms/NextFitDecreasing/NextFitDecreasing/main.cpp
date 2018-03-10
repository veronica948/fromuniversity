#include"Container.h"
void nextFitDecreasing(double* objects,int numberOfObjects){
	Container* containers = new Container [numberOfObjects];
	int count = 1;
	for(int i = 0; i < numberOfObjects; i++) {
		if(containers[count -1].currentLength + objects[i] > Container::LENGTH){
			count++;
		}
		containers[count - 1].listOfObjects.push(objects [i]);
		containers[count - 1].currentLength += objects[i];
	}
	cout<<"count = "<<count<<endl;
	for(int i = 0; i < count; i++) {
		containers[i].show();
		cout<<endl;
	}
}
void firstFitDecreasing(double* objects,int numberOfObjects){
	Container* containers = new Container [numberOfObjects];
	int count = 1;
	for(int i = 0; i < numberOfObjects; i++) {
		int j = 0;
		for(; j < count; j++){
			if(containers[j].currentLength + objects[i] <= Container::LENGTH){
				break;
			}
		}
		if( j == count){
			count++;
		}
		containers[j].listOfObjects.push(objects [i]);
		containers[j].currentLength += objects[i];
	}
	cout<<"count = "<<count<<endl;
	for(int i = 0; i < count; i++) {
		containers[i].show();
		cout<<endl;
	}
}
void bestFitDecreasing(double* objects,int numberOfObjects){
	Container* containers = new Container [numberOfObjects];
	int count = 1;
	for(int i = 0; i < numberOfObjects; i++) {
		int j = 0;
		int index = -1;
		double maxLength = 0;
		for(; j < count; j++) {
			double newLength = containers[j].currentLength + objects[i];			
			if(newLength >= maxLength && newLength <= Container::LENGTH){
				index = j;
				maxLength = newLength;
			}
		}
		if( index == -1){
			index = count;
			count++;
		}
		containers[index].listOfObjects.push(objects [i]);
		containers[index].currentLength += objects[i];
	}
	cout<<"count = "<<count<<endl;
	for(int i = 0; i < count; i++) {
		containers[i].show();
		cout<<endl;
	}
}
int main() {
	ifstream file("file.txt");
	int numberOfObjects;
	file>>numberOfObjects;
	double* objects = new double [numberOfObjects];
	for(int i = 0; i < numberOfObjects; i++) {
		file>>objects[i];
		cout<<objects[i]<<' ';
	}
	cout<<endl<<"nextFitDecreasing"<<endl;
	nextFitDecreasing(objects,numberOfObjects);
	cout<<"firstFitDecreasing"<<endl;
	firstFitDecreasing(objects,numberOfObjects);
	cout<<"bestFitDecreasing"<<endl;
	bestFitDecreasing(objects,numberOfObjects);
	system("pause");
	return 0;
}