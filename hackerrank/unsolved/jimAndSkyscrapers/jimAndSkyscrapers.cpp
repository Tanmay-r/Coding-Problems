#include <iostream>
#include <stack>
using namespace std;

int main(){
	int N, answer = 0;
	cin >> N;

	int skyscrapers[N];
	for(int i = 0; i < N; i++){
		cin >> skyscrapers[i];
	}
	stack<int> s;
	int top = 0;
	stack<int> currentCount;
	for(int i = 0; i < N; i++){
		if(s.empty()){
			s.push(skyscrapers[i]);
			currentCount.push(0);
		}
		else{
			top = s.top();			
			if(skyscrapers[i] < top){
				s.push(skyscrapers[i]);
				currentCount.push(0);
			}
			else if(skyscrapers[i] == top){
				s.push(skyscrapers[i]);
				int temp = currentCount.top();
				currentCount.pop();
				currentCount.push(temp);
				currentCount.push(temp+1);
				answer += currentCount.top();
			}
			else{
				s.pop();
				while(s.empty() == false && skyscrapers[i] > s.top()){
					currentCount.pop();
					s.pop();
				}
				i--;
			}
		}
	}
	cout << answer*2 << endl;
}