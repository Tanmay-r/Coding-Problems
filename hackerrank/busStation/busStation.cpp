#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> cumSum;


bool checkValidity(int busSize, int start){
    int total = 0;
    for(int i = start+1; i < people.size(); i++){
        total += people[i];
        if(total > busSize){
            return false;
        }
        else if(total == busSize){
            total = 0;
        }
    }
    if(total == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;

    people = vector<int> (n);
    cumSum = vector<int> (n);
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

    for(int i = 0; i < n; i++){
        if(sum % cumSum[i] == 0){
            if(checkValidity(cumSum[i], i)){
                cout << cumSum[i] << " ";
            }
        }
    }
}