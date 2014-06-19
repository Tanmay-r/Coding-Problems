#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct star{
    long x;
    long y;
    int value;
};

int main(){
    int N, output, difference;
    cin >> N;
    output = 0;

    vector<star> stars(N);

    for(int i = 0; i < N; i++){
        cin >> stars[i].x >> stars[i].y >> stars[i].value;
        difference += stars[i].value;
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int setOne = 0;
            int setTwo = 0;
            long dirx = (stars[i].x - stars[j].x);
            long diry = (stars[i].y - stars[j].y);
            for(int k = 0; k < N; k++){
                if(k != i && k != j){
                    if(dirx*(stars[k].y - stars[j].y) - diry*(stars[k].x - stars[j].x) < 0){
                        setOne += stars[k].value;
                    }
                    else{
                        setTwo += stars[k].value;
                    }
                }
            }
            if((setOne + stars[i].value) >= (setTwo + stars[j].value)){
                if(difference >= ((setOne + stars[i].value) - (setTwo + stars[j].value))){
                    output = (setTwo + stars[j].value);
                    difference = ((setOne + stars[i].value) - (setTwo + stars[j].value));
                }
            }
            if((setOne + stars[j].value) >= (setTwo + stars[i].value)){
                if(difference >= ((setOne + stars[j].value) - (setTwo + stars[i].value))){
                    output = (setTwo + stars[i].value);
                    difference = ((setOne + stars[j].value) - (setTwo + stars[i].value));
                }
            }
            if((setTwo + stars[j].value) >= (setOne + stars[i].value)){
                if(difference >= ((setTwo + stars[j].value) - (setOne + stars[i].value))){
                    output = (setOne + stars[i].value);
                    difference = ((setTwo + stars[j].value) - (setOne + stars[i].value));
                }
            }
            if((setTwo + stars[i].value) >= (setOne + stars[j].value)){
                if(difference >= ((setTwo + stars[i].value) - (setOne + stars[j].value))){
                    output = (setOne + stars[j].value);
                    difference = ((setTwo + stars[i].value) - (setOne + stars[j].value));
                }
            }
        }    
    }

    cout << output << endl;
}