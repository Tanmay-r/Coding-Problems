#include <iostream>
#include <cmath>

using namespace std;

int n;

void helper(int N){
	// /cout << "N = " << N << " start = " << start << endl;
	if(N != 1){
		n = -1*n;
		int logn = log2(N);
		if(pow(2, logn) == N){			
			helper(N/2);
		}
		else{
			helper(N - pow(2, logn));
		}

	}
}

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;
		n = 1;
		helper(N);
		if(n == 1){
			cout << "Richard" << endl;
		}
		else{
			cout << "Louise" << endl;
		}
	}
}