#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Ladder{
    int start;
    int end;
};

struct Snake{
    int head;
    int tail;
};

bool operator< (const Ladder &i, const Ladder &j){
    return i.start <  j.start;
}

bool isSnake(int position, vector<Snake> snakes){
    for(int i = 0; i < snakes.size(); i++){
        if(snakes[i].head == position){
            return true;
        }
    }
    return false;
}

int minSteps(int start, vector<Snake> snakes, vector<Ladder> ladders, int startLadder){
    if(start == 100){
        return 0;
    }
    else if(start > 100){
        return -1;
    }
    else if(start + 6 >= 100){
        return 1;
    }
    else if(start >= ladders[startLadder].start){
        int minimumSteps = 100;
        if(startLadder >= ladders.size() - 1){
            for(int i = 6; i > 0; i--){
                if(isSnake(start + i, snakes) == false){
                    return (1 + minSteps(start + i, snakes, ladders, startLadder));
                }
            }
        }
        else{
            for(int k = startLadder+1; k < ladders.size(); k++){
                int steps = minSteps(start, snakes, ladders, k);
                if(steps < minimumSteps){
                    minimumSteps = steps;
                }
            }
            return minimumSteps; 
        }                
    }
    else{
        if(start + 6 >= ladders[startLadder].start){
            return (1 + minSteps(ladders[startLadder].end, snakes, ladders, startLadder + 1));
        }
        else{
            for(int i = 6; i > 0; i--){
                if(isSnake(start + i, snakes) == false){
                    return (1 + minSteps(start + i, snakes, ladders, startLadder));
                }
            }
        }
    }
    return -5;
}

int main(){
    int T = 0;
    cin >> T;
    
    while(T--){
        char temp;
        int numLadders, numSnakes;

        //Input number of ladders and snakes
        cin >> numLadders;
        cin >> temp;
        cin >> numSnakes;
        
        vector<Snake> snakes(numSnakes);
        vector<Ladder> ladders(numLadders);
        
        //Input ladders
        for(int i = 0; i < numLadders; i++){
            cin >> ladders[i].start;
            cin >> temp;
            cin >> ladders[i].end;
        }

        //Input snakes
        for(int i = 0; i < numSnakes; i++){
            cin >> snakes[i].head;
            cin >> temp;
            cin >> snakes[i].tail;
        }

        //Sort ladders according to start
        sort(ladders.begin(), ladders.end());

        int minimumSteps = 100;
        for(int k = 0; k < ladders.size(); k++){
            int steps = minSteps(0, snakes, ladders, k);
            if(steps < minimumSteps){
                minimumSteps = steps;
            }
        }
        cout << minimumSteps << endl;
    }
}