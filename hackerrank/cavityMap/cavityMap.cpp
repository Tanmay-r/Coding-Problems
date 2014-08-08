#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> > inp(n, vector<int> (n));
    vector<vector<char> > outp(n, vector<char> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> outp[i][j];
            inp[i][j] = (int) outp[i][j] - 48;
        }
    }

    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(inp[i][j] > inp [i-1][j]){
                if(inp[i][j] > inp[i][j-1]){
                    if(inp[i][j] > inp[i][j+1]){
                        if(inp[i][j] > inp[i+1][j]){
                            outp[i][j] = 'X';
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << outp[i][j];
        }
        cout << endl;
    }
}