#include <iostream>

using namespace std;

long int paperPieces[100][100];

void init(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            paperPieces[i][j] = 0;
        }
    }
}

int helper(int m, int n){
    if(m == n){
        paperPieces[m - 1][n - 1] = 1;
        return 1;
    }
    else if(m < n){
        if(paperPieces[m - 1][n - 1] == 0){
            paperPieces[m - 1][n - 1] = 1 + helper(m, n-m);
        }
        else{
            paperPieces[m - 1][n - 1] = 1 + paperPieces[m - 1][n - m - 1];
        }
        return paperPieces[m - 1][n - 1];
    }
    else{
        if(paperPieces[m - 1][n - 1] == 0){
            paperPieces[m - 1][n - 1] = 1 + helper(m - n, n);
        }
        else{
            paperPieces[m - 1][n - 1] = 1 + paperPieces[m - n - 1][n - 1];
        }
        return paperPieces[m - 1][n - 1];
    }
}

int main(){
    int T = 0;
    cin >> T;
    while(T--){
        int m, n;
        cin >> m >> n;
        cout << helper(m, n) << endl;
    }
}