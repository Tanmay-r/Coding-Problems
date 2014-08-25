#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int T = 0;
    scanf("%d", &T);
    
    while(T--){
    	long long int a, b, c, d, xm, ym;
        cin >> a >> b >> c >> d >> xm >> ym;
    	//scanf("%ld %ld %ld %ld %ld %ld", &a, &b, &c, &d, &xm, &ym);

        float denom = xm*(b - d) - ym*(a - c);
        float nums = b*c - a*d;
        float numr = b*xm - a*ym;

        float s, r;
        if(denom != 0){
            s = nums/denom;
            r = numr/denom;
        }
        else{
            long long int dista = a*a + b*b;
            long long int distc = c*c + d*d;
            long long int distm = xm*xm + ym*ym;
            printf("%d %d %d\n",  dista, distc, distm);
            if(distm <= dista && distm <= distc){                
                s = 0.5;
                r = 0.5;
            }
            else{
                s = 7;
                r = 7;
            }            
        }

    	if(s >= 0 && s <= 1){
    		
            if(r >= 0 && r <= 1){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
    	}
    	else{
			printf("YES\n");
    	}
    }
}