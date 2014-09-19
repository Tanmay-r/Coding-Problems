#include <iostream>

using namespace std;

int gcd(int m, int n){
    if(m > n){
        return gcd(m - n, n);
    }
    else if(n > m){
        return gcd(n - m, m);
    }
    else{
        return m;
    }
}

int main(){
    int T = 0;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        int output = 0;
        int product = 1;
        int number;

        for(int i = 0; i < m; i++){
            cin >> number;
            product = (product*number)/gcd(product, number);
        }
        output = n/product;
        cout << output << endl;
    }
}