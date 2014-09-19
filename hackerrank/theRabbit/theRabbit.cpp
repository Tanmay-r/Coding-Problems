#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    
    while(T--){
        long long int p;
        float nlower, nhigher;
        cin >> p;
        nlower = (sqrt(9 + 8*p) - 3)/2;
        cout << ceil(nlower) << endl;
    }
}