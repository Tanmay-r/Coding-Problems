#include <iostream>
#include <iomanip>

using namespace std;

int exponential(int K, int N){
	if(K == 0){
		return 0;
	}
	else if(N == 0){
		return 1;
	}
	else if(N == 1){
		return K%100;
	}
	else if(N % 2 == 0){
		int answer = exponential(K, N/2) % 100;
		answer *= answer;
		answer %= 100;
		return answer;
	}
	else{
		int answer = exponential(K, (N-1)/2) % 100;
		answer *= answer;
		answer *= K%100;
		answer %= 100;
		return answer;
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		long long int N, K;
		int powerArray[100];
		cin >> K >> N;
		for(int i = 0; i < 100; i++){
			powerArray[i] = exponential(i, N)%100;
		}
		int sum = 0;
		int KBy100 = K/100;

		for(int i = 0; i <= K%100; i++){
			sum += ((KBy100 + 1)%100 * powerArray[i])%100;
			sum %= 100;
		}
		for(int i = K%100 + 1; i < 100; i++){
			sum += (KBy100%100 * powerArray[i])%100;
			sum %= 100;
		}
		cout << setfill('0') << setw(2) << sum << endl;
	}
}