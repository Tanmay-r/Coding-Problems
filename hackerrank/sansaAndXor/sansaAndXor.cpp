#include <iostream>
#include <cstdio>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int temp;
        int output = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &temp);
            if((i+1)%2 != 0){
                if((N - i)%2 != 0){
                    output = output ^ temp;
                }
            }
        }
        printf("%d\n", output);

    } 
}