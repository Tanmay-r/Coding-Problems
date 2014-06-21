#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int N;
	cin >> N;

	vector<list <string>> lines(N);

	for(int i = 0; i < N; i++){
		string word;
		cin >> word;
		lines[i].push_back(word);
	}
}