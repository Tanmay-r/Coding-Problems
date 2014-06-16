#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K, unfairness;
    cin >> N >> K;
    vector<long> candies(N);

    unfairness = 0;
    for(int i = 0; i < N; i++){
        cin >> candies[i];
        if(unfairness < candies[i]){
            unfairness = candies[i];
        }
    }

    sort(candies.begin(), candies.end());

    for(int i = 0; (i + K - 1) < N; i++){
        if(unfairness > (candies[i + K - 1] - candies[i])){
            unfairness = (candies[i + K - 1] - candies[i]);
        }
    }

    cout << unfairness << endl;
}