#include <iostream>
#include <cmath>

using namespace std;

struct PairType{
	int time;
	int count;
};

PairType combine(int weights[], int numbers[], int start, int end, int N){
	int t = 0;
	PairType retPairType;
	if(start == end){
		retPairType.time = 0;
		retPairType.count = 0;
	}
	else{
		int newNumber1[N], newWeights1[N];
		int newNumber2[N], newWeights2[N];
		for(int i = 0; i < N; i++){
			newNumber1[i] = numbers[i];
			newWeights1[i] = weights[i];
			newNumber2[i] = numbers[i];
			newWeights2[i] = weights[i];
		}

		int t1 = newNumber1[start]*newWeights1[start] + newNumber1[start+1]*newWeights1[start+1];
		

		newNumber1[start+1] += newNumber1[start];
		newWeights1[start+1] += newWeights1[start];
		PairType p1 = combine(newWeights1, newNumber1, start+1, end, N);
		p1.time += t1;
		p1.count += 1;

		int t2 = newNumber2[end]*newWeights2[end] + newNumber2[end-1]*newWeights2[end-1];
		newNumber2[end-1] += newNumber2[end];
		newWeights2[end-1] += newWeights2[end];
		PairType p2 = combine(newWeights2, newNumber2, start, end-1, N);
		p2.time += t2;
		p2.count += 1;	

		if(p1.time < p2.time){
			retPairType.time = p1.time;
			retPairType.count = p1.count;
		}
		else if(p2.time < p1.time){
			retPairType.time = p2.time;
			retPairType.count = p2.count;
		}
		else{
			retPairType.time = p1.time;
			retPairType.count = p1.count<p2.count?p1.count:p2.count;
		}
	}
	return retPairType;
}

int main(){
    int N,T;
    cin >> N >> T;

    int weights[N];
    int numbers[N];

    for(int i = 0; i < N; i++){
    	cin >> weights[i];
    	numbers[i] = 1;
    }
    PairType t = combine(weights, numbers, 0, N-1, N);
    if(t.time < T){
    	cout << 0 << endl;
    }
    else{
    	cout << ceil((t.time - T)/t.count) << endl;
    }
}