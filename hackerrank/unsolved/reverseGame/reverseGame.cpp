#include <cstdio>

using namespace std;

int main(){
    int T = 0;
    scanf("%d", &T);
    
    while(T--){
    	int N, K;
    	scanf("%d %d", &N, &K);

    	if(N %2 == 0){
    		if(K < N/2){
    			printf("%d\n", 2*K+1);
    		}
    		else{
    			printf("%d\n", 2*N - 2*K - 2);
    		}
    	}
    	else{
			if(K < (N-1)/2){
    			printf("%d\n", 2*K+1);
    		}
    		else{
    			printf("%d\n", 2*N - 2*K - 2);
    		}
    	}
    }
}