#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int N, K;
	string S;
	
	cin >> N >> K;
	cin >> S;
	string ans(N, '0');

	for(int i = 0; i < N; i++){
		if(i == 0){
			ans[i] = S[0];
		}
		else if(i < K){
			int i1 = S[i] - '0';
			int i2 = S[i-1] - '0';
			char c = (i1 ^ i2) + '0';
			ans[i] = c;
		}
		else{
			int i1 = S[i-1] - '0';
			int i2 = ans[i-K] - '0';
			int i3 = S[i] - '0';
			char c = (i3 ^ (i1 ^ i2)) + '0';
			ans[i] = c;
		}
	}
	cout << ans << endl;
}