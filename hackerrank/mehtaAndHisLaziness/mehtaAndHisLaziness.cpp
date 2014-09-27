#include <iostream>
#include <set>

using namespace std;

int q[1000001];
int gcd(int m, int n){
	if(m == 1 || n == 1){
		return 1;
	}
	else if(n  == m){
		return m;
	}
	else if(m < n){
		return gcd(m, n - m);
	}
	else{
		return gcd(m - n, n);
	}
}

void preProcess(){
	for(int i = 0; i < 1000001; i++){
		q[i] = 0;
	}
	q[1] = 1;
	for(int i = 2; i < 1000001; i++){
		if(q[i] == 0){
			q[i] = 1;
			for(int j = 2*i; j < 1000001; j += i){
				q[j] += 1 + q[j/i];
			}
		}
	}
}

int main(){
	preProcess();
	int even_perfect_squares[1003];
	for(int i = 2, j = 0; j < 1003; i += 2, j++){
		even_perfect_squares[j] = i*i;
	}
	
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		int p = 0;
		for(int i = 0; even_perfect_squares[i] < N; i++){
			if(N%even_perfect_squares[i] == 0){
				p++;
			}
		}
		if(p == 0){
			cout << p << endl;
		}
		else{
			int gcdPQ = gcd(p, q[N]);
			cout << p/gcdPQ << "/" << q[N]/gcdPQ << endl;
		}
	}

}