#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> people(n);
    vector<int> cumSum(n);

    int max = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> people[i];
        sum += people[i];
        cumSum[i] = sum;
        if(people[i] > max){
            max = people[i];
        }
    }

    vector<vector<int> > busSizes(n);

    for(int i = 0;i < n; i++){
        busSizes[i].push_back(cumSum[i]);
        if(i > 0){
            for(int j = 0; j < i; j++){
                int sumji = cumSum[i] - cumSum[j];

                bool flag = true;
                for(int k = 0; k < busSizes[i].size(); k++){
                    if(busSizes[i][k] == sumji){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int k = 0; k < busSizes[j].size(); k++){
                        if(busSizes[j][k] == sumji){
                            busSizes[i].push_back(sumji);
                        }
                    }
                }
            }
        }
    }

    for(int j = busSizes[n-1].size() - 1; j >= 0; j--){
       cout << busSizes[n-1][j] << " ";
    }
}