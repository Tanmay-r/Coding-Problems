#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int helper(list<int> numbers, int N){
    

    
    int comp = numbers.front();
    numbers.pop_front();
    
    list<int> min, max;
    int count = numbers.size();
    for(int i = 1; i <= count; i++){
        if(numbers.front() <= comp){
            min.push_back(numbers.front());
            numbers.pop_front();
        }
        else{
            max.push_back(numbers.front());
            numbers.pop_front();
        }
    }
    if(min.size() > N){
        return helper(min, N);
    }
    else if(min.size() == N){
        return comp;
    }
    else{
        return helper(max, N - min.size() - 1);
    }
}

int main(){
    int N;
    cin >> N;

    list<int> numbers;

    int newint;
    for(int i = 0; i < N; i++){        
        cin >> newint;
        numbers.push_back(newint);
    }
    cout << helper(numbers, floor(N/2)) << endl;
}