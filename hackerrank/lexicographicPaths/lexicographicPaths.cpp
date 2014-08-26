#include <iostream>
#include <cstdio>

int nchoosem[21][21];

void initNchooseM(){
    for(int i = 0; i < 21; i++){
        nchoosem[0][i] = 0;
    }
    for(int i = 0; i < 21; i++){
        nchoosem[i][0] = 1;
    }
    for(int i = 1; i < 21; i++){
        for(int j = 1; j < 21; j++){
            nchoosem[i][j] = nchoosem[i-1][j-1] + nchoosem[i-1][j];
        }
    }
}

int main(){
    initNchooseM();
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int tempN, tempM, tempK;
        tempN = N;
        tempM = M;
        tempK = K + 1;
        for(int i = 0; i < N + M; i++){
            if(tempK <= nchoosem[tempN + tempM -1][tempM]){
                printf("H");
                tempN = tempN - 1;
            }
            else{
                printf("V");
                tempK = tempK - nchoosem[tempN + tempM -1][tempM];
                tempM = tempM - 1;                
            }            
        }
        printf("\n");
    }
}