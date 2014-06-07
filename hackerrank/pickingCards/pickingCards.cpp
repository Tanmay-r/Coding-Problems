#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;
        vector<int> C(N);
        long output = 1;

        for(int i = 0; i < N; i++){
        	cin >> C[i];
        }

        sort(C.begin(), C.end());
        int prevNumber = 0;
        int prevNumberCount = 0;


        for(int i = 0; i < N; i++){
            if(C[i] > i){
                output = 0;
            }

            else if(C[i] < i){
                output *= (i - C[i] + 1);
            }

            else if(C[i] == i){
                output *= 1;
            }
            output %= 1000000007;

        }
        cout << output << endl;
    }
}