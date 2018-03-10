#include<string>
#include<iostream>
#include<fstream>
using namespace std;
void RabinKarpAlgorithm(string text, string substring) {
	int q = 1000000;
	int m = substring.length();
	int n = text.length();
	int hash_s = 0;
	for(int i = 0; i < m; i++)
		hash_s += substring[i] * pow(2.0,(double)(m - i - 1));
	hash_s %= q;
	int dimOfHash_t = n - m + 1;
	int * hash_t = new int [dimOfHash_t];
	hash_t[0] = 0;
	for(int i = 0; i < m; i++)
		hash_t[0] += text[i] * pow(2.0,(double)(m - i - 1));
	hash_t[0] %= q;
	for(int i = 1; i <= n - m; i++) {
		hash_t[i] = ((hash_t[i - 1] - text[i - 1] * pow(2.0,(double)(m - 1))) * 2 + text[i - 1 + m]);
		hash_t[i] %= q;
	} 
	for(int i = 0; i <= n - m; i++) {
		if(hash_t[i] == hash_s) {
			if(text.substr(i,m - 1) == substring.substr(0,m - 1)) {
				cout<<i<<" ";
			}
		}
	}
}
int main() {
	RabinKarpAlgorithm("tefdfdststrtfstrghdstrfdsstrstrg","str");
	system("pause");
	return 0;
}