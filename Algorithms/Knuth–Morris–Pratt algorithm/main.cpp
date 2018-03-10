#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int* prefixFunction(string text) {
	int length = text.length();
	int* result = new int [length];
	result[0] = 0;
	int j;
	for(int i = 1; i < length; i++) { 
		for(j = result[i - 1]; j >= 0; j = result[j - 1]) {
			if(text[j] == text[i]) {
				result[i] = ++j;
				break;
			}
		}
		if(j <= 0) {
			result[i] = 0;
		}
	}
	return result;
}
void Knuth–Morris–PrattAlgorithm(string text, string substr) {
	string newString = substr + '#' + text;
	int length = substr.length();
	int* p = prefixFunction(newString);
	for(int i = length + 1; i < newString.length(); i++) {
		if(p[i] == length) {
			cout<<(i - 2*length)<<' ';
		}
	}
}
int main() {
	Knuth–Morris–PrattAlgorithm("tefdfdststrtfstrghdstrfdsstrstrg","str");
	system("pause");
	return 0;
}