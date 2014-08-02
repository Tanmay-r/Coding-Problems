#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		int count = 0;
		int num = 0;
		for(int i = 0; i < n; i++){
			cin >> num;
			if(num % 2 == 0){
				count++;
			}
		}
		if(k == 0 && count == n){
			cout << "NO" << endl;
		}
		else if(count >= k){
			cout << "YES" << endl;
 		}
 		else{
 			cout << "NO" << endl;
 		}

	}
}