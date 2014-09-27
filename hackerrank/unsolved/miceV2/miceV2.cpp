#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long int goToHole(vector<long long int> &mouse, vector<long long int> &holes, vector<vector<long long int> > &mouseHoles, int mouseStart, int holeStart){
    int origMouseStart = mouseStart;
    int origHoleStart = holeStart;
    if(mouseHoles[origMouseStart][origHoleStart] != -5){
        return mouseHoles[origMouseStart][origHoleStart];
    }
    if(holes.size() - holeStart < mouse.size() - mouseStart){
        mouseHoles[origMouseStart][origHoleStart] = -1;
        return -1;
    }
    else if(mouseStart == mouse.size() - 1){
        long long int diff = abs(mouse[mouseStart] - holes[holeStart]);
        while(holeStart < holes.size()){
            if(mouse[mouseStart] - holes[holeStart] < diff){
                diff = abs(mouse[mouseStart] - holes[holeStart]);
            }
            holeStart++;
        }
        mouseHoles[origMouseStart][origHoleStart] = diff;
        return diff;
    }
    else{
        long long int min = 200000000;
        long long int number = abs(mouse[mouseStart] - holes[holeStart]);
        long long int numberRest;
        if(mouseHoles[mouseStart+1][holeStart+1] != -5){
            numberRest = mouseHoles[mouseStart+1][holeStart+1];
        }
        else{
            numberRest = goToHole(mouse, holes, mouseHoles, mouseStart+1, holeStart+1);
        }
        while(numberRest > -1){
            long long int val;
            if(numberRest > number){
                val = numberRest;
            }
            else{
                val = number;
            }
            if(val < min){
                min = val;
            }
            holeStart += 1;
            if(holeStart < holes.size()){
                number = abs(mouse[mouseStart] - holes[holeStart]);
                if(mouseHoles[mouseStart+1][holeStart+1] != -5){
                    numberRest = mouseHoles[mouseStart+1][holeStart+1];
                }
                else{
                    numberRest = goToHole(mouse, holes, mouseHoles, mouseStart+1, holeStart+1);
                }
            }
            else{
                numberRest = -1;
            }            
        }
        mouseHoles[origMouseStart][origHoleStart] = min;
        return min;
    }
}

int main(){
    int T = 0;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        
        vector<long long int> mouse(n);
        vector<long long int> holes(m);
        vector<vector<long long int> > mouseHoles(n, vector<long long int>(m, -5));
        for(int i = 0; i < n; i++){
            cin >> mouse[i];
        }
        for(int i = 0; i < m; i++){
            cin >> holes[i];
        }

        sort(mouse.begin(), mouse.end());
        sort(holes.begin(), holes.end());

        long long int output = goToHole(mouse, holes, mouseHoles, 0, 0);

        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mouseHoles[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << output << endl;
    }
}