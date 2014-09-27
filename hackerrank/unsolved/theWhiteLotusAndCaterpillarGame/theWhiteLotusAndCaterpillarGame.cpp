#include <iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;

	float answer = 0;
	if(N >= M){
		answer  = N - 1;
	}
	else{
		answer += (3*N*(N+1))/2;
		answer += (N*(N+1)*(2*N+1))/12;
		answer += 3*N;
		answer += M*N*N;
		answer += M*M*N;
		answer += -2*M*N;
		answer += -N*N;
		answer += N;
		answer += -(M*N*(M+1))/2;
		answer += -(M*N*(N+1))/2;

		answer = 2*answer;

		if(M >= 2*N){
			answer += M*N;
			answer += -M;
			answer += M*N;
			answer += (M*M*(M-2*N))/2;
			answer += (-M*(M-2*N))/2;
			answer += (M-2*N);
			answer += ((M-N)*(M-N+1)*(2*M-2*N+1))/6;
			answer += -((M-N)*(M-N+1)*(M+1))/2;
			answer += -(N*(N+1)*(2*N+1))/6;
			answer += (N*(N+1)*(M+1))/2;
		}
		else{
			answer -= ((N-1)*(M-N+1)*(M-N+4))/2;
			answer -= (M+N-1)*(M-1)*(M-N+1);
			answer -= -((M+N-1)*(M-N+1)*(M-N+2))/2;
			answer -= -(M*(M+1)*(M-N+1))/2;
			answer -= ((M-N+1)*(M-N+2)*(2*M-2*N+1))/12;
			answer -= ((M-N+1)*(M-N+2))*6;
			answer -= (M-N+1)*3;

		}
		answer /= M;
		answer /= M;
	}
	cout << answer << endl;
}