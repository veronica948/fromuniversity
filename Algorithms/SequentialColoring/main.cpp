#include"Graph.h"
int main() {
	Graph graph("file.txt");
	cout<<"sequentialColoring"<<endl;
	cout<<graph.sequentialColoring()<<endl;
	graph.showColors();
	cout<<"independentSetsColoring"<<endl;
	cout<<graph.independentSetsColoring()<<endl;
	graph.showColors();
	int p;
	cout<<"Enter p: "<<endl;
	cin>>p;
	double sum1 = 0;
	double sum2 = 0;
	int first;
	int second;
	for(int i  = 0; i < 20; i++) {
		Graph graph3(500,p);
		first = graph3.sequentialColoring();
		second = graph3.independentSetsColoring();
		sum1 += first;
		sum2 += second;
	}
	sum1 /= 20;
	sum2 /= 20;
	cout<<sum1<<' '<<sum2<<endl;
	system("pause");
	return 0;
}