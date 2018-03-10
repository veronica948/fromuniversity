#include"Container.h"
void withContainers(double** objects,int numberOfObjects) {
	Container * containers = new Container [numberOfObjects];
	for(int i = 0; i < numberOfObjects; i++) {
		bool flag = false;
		for(int j = 0; j < numberOfObjects; j++) {
			for(int k = 0; k < containers[j].numberOfFreeRectangles; k++) {
				double currentLength = containers[j].listOfFreeRactangles[k]->length + 0.000000001;
				double currentWidth = containers[j].listOfFreeRactangles[k]->width + 0.000000001;
				if(currentLength >= objects[i][0] && currentWidth >= objects[i][1]) {
						flag = true;
						containers[j].listOfFreeRactangles.AddObject(k + 1,currentLength - objects[i][0],currentWidth);
						containers[j].listOfFreeRactangles[k]->changeFields(objects[i][0],currentWidth - objects[i][1]);
						containers[j].listOfObjects.push(objects[i][0], objects[i][1]);
						containers[j].numberOfFreeRectangles++;
						break;
				}
			}
			if(flag == true) {
				break;
			}
		}
	}
	cout<<"Containers:\n";
	for(int i = 0; i < numberOfObjects; i++) {
		if(containers[i].listOfObjects.getFirst() != 0) {
			cout<<i + 1<<endl;
			containers[i].show();
		}
	}
}
void withStrip(double** objects,int numberOfObjects) {
	Strip strip;
	for(int i = 0; i < numberOfObjects; i++) {
		bool flag = false;
			for(int k = 0; k < strip.numberOfFreeRectangles; k++) {
				double currentLength = strip.listOfFreeRactangles[k]->length + 0.000000001;
				double currentWidth = strip.listOfFreeRactangles[k]->width + 0.000000001;
				if(currentLength >= objects[i][0] && currentWidth >= objects[i][1]) {
						flag = true;
						strip.listOfFreeRactangles.AddObject(k + 1,currentLength - objects[i][0],currentWidth);
						strip.listOfFreeRactangles[k]->changeFields(objects[i][0],currentWidth - objects[i][1]);
						strip.listOfObjects.push(objects[i][0], objects[i][1]);
						strip.numberOfFreeRectangles++;
						break;
				}
			}
			if(flag == false) {
				strip.currentLength += objects[i][0];
				strip.listOfFreeRactangles.push(objects[i][0],strip.WIDTH - objects[i][1]);
				strip.numberOfFreeRectangles++;
			}
	}
	cout<<"Length of strip: "<<strip.currentLength<<endl;
}
void withMinArea(double** objects,int numberOfObjects) {
	Quadrant quadrant;
	for(int i = 0; i < numberOfObjects; i++) {
		bool flag = false;
			for(int k = 0; k < quadrant.numberOfFreeRectangles; k++) {
				double currentLength = quadrant.listOfFreeRactangles[k]->length + 0.000000001;
				double currentWidth = quadrant.listOfFreeRactangles[k]->width + 0.00000001;
				if(currentLength >= objects[i][0] && currentWidth >= objects[i][1]) {
						flag = true;
						quadrant.listOfFreeRactangles.AddObject(k + 1,currentLength - objects[i][0],currentWidth);
						quadrant.listOfFreeRactangles[k]->changeFields(objects[i][0],currentWidth - objects[i][1]);
						quadrant.listOfObjects.push(objects[i][0], objects[i][1]);
						quadrant.numberOfFreeRectangles++;
						break;
				}
			}
			if(flag == false) {
				quadrant.currentLength += objects[i][0];
				double difference = objects[i][1] - quadrant.currentWidth;
				if(quadrant.currentWidth < objects[i][1]) {
					for(int j = 0; j < quadrant.numberOfFreeRectangles; j++) {
						quadrant.listOfFreeRactangles[j]->width += difference;
					}
					quadrant.currentWidth += objects[i][1];
				}
				else {
					quadrant.listOfFreeRactangles.push(objects[i][0],quadrant.currentWidth - objects[i][1]);
					quadrant.numberOfFreeRectangles++;
				}
			}
				
		}
	cout<<"Area: "<<quadrant.getArea()<<endl;
}
int main() {
	fstream file("file2.txt");
	int numberOfObjects;
	file>>numberOfObjects;
	double** objects = new double *[numberOfObjects];
	for(int i = 0; i < numberOfObjects; i++) {
		objects[i] = new double [2];
		for(int j = 0; j < 2; j++) {
			file>>objects[i][j];
			cout<<objects[i][j]<<' ';
		}
		cout<<endl;
	}
	withContainers(objects,numberOfObjects);
	withStrip(objects,numberOfObjects);
	withMinArea(objects,numberOfObjects);
	system("pause");
	return 0;
}