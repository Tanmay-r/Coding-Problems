#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct order{
	int sum;
	int rank;
};

bool compareOrder(const order &a, const order &b)
{
    if(a.sum == b.sum){
    	return a.rank < b.rank;
    }
    else{
    	return a.sum < b.sum;
    }
}

int main(){
    int N;
    cin >> N;
    vector<order> my_orders(N);

    int temp1, temp2;
    for(int i = 0; i < N; i++){
    	cin >> temp1 >> temp2;
    	my_orders[i].sum = temp1 + temp2;
    	my_orders[i].rank = i;
    }

    sort(my_orders.begin(), my_orders.end(), compareOrder);
    for(int i = 0; i < N; i++){
    	cout << my_orders[i].rank + 1<< " ";
    }
    cout << endl;
}