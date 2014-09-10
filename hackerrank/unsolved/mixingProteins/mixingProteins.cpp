#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char transform[4][4];

void init(){
    transform[0][0] = 'A';
    transform[0][0] = 'B';
    transform[0][0] = 'C';
    transform[0][0] = 'D';

    transform[0][0] = 'B';
    transform[0][0] = 'A';
    transform[0][0] = 'D';
    transform[0][0] = 'C';

    transform[0][0] = 'C';
    transform[0][0] = 'D';
    transform[0][0] = 'A';
    transform[0][0] = 'B';

    transform[0][0] = 'D';
    transform[0][0] = 'C';
    transform[0][0] = 'B';
    transform[0][0] = 'A';
}

void transformFunc(int N, string s, int K){
    cout << s << endl;
    string s1 = s;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N-1; j++){
            int row, column;
            if(s[j] == 'A'){
                row = 0;
            }
            if(s[j] == 'B'){
                row = 1;
            }
            if(s[j] == 'C'){
                row = 2;
            }
            if(s[j] == 'D'){
                row = 3;
            }

            if(s[j+1] == 'A'){
                column = 0;
            }
            if(s[j+1] == 'B'){
                column = 1;
            }
            if(s[j+1] == 'C'){
                column = 2;
            }
            if(s[j+1] == 'D'){
                column = 3;
            }
            s1[j] = transform[row][column];
            cout << s1 << endl;
        }
        int row, column;
        if(s[N-1] == 'A'){
            row = 0;
        }
        if(s[N-1] == 'B'){
            row = 1;
        }
        if(s[N-1] == 'C'){
            row = 2;
        }
        if(s[N-1] == 'D'){
            row = 3;
        }

        if(s[0] == 'A'){
            column = 0;
        }
        if(s[0] == 'B'){
            column = 1;
        }
        if(s[0] == 'C'){
            column = 2;
        }
        if(s[0] == 'D'){
            column = 3;
        }
        s1[N-1] = transform[row][column];
        s = s1;
        cout << "K = " << i << " " << s << endl;
    }
    cout << s;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    string protein;

    cin >> protein;

    transformFunc(N, protein, K);
    cout << endl;
}