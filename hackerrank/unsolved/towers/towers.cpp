#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


stack<long long int> sum_stack;
stack<int> K_stack;
stack<int> start_stack;

int * block_pointer;

long long int my_function(){
	long long int return_count = 0;
	while (!sum_stack.empty()){
		long long int sum = sum_stack.top();
		sum_stack.pop();
		int  K = K_stack.top();
		K_stack.pop();
		int start = start_stack.top();
		start_stack.pop();

		//excluding
		if(start + 1 < K){
			sum_stack.push(sum);
			K_stack.push(K);
			start_stack.push(start + 1);
		}

		//including
		if(sum - block_pointer[start] == 0){
			return_count += 1;
			return_count %= 1000000007;
		}
		if(sum - block_pointer[start] > 0){
			sum_stack.push(sum - block_pointer[start]);
			K_stack.push(K);
			start_stack.push(0);
		}
	}
	return return_count;
}

int main(){
	long long int N;
	int K;
	cin >> N >> K;
	int blocks[K];
	for(int i =0; i < K; i++){
		cin >> blocks[i];
	}

	block_pointer = blocks;

	sum_stack.push(N);
	K_stack.push(K);
	start_stack.push(0);
	long long int count = my_function();

	count %= 1000000007;
	cout << (count*2)% 1000000007 << endl;

    return 0;
}