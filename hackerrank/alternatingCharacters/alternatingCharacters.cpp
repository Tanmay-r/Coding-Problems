#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin >> T;
	int count;
	char c, prev_char;
	string s;
	while(T--){
		count = 0;
		prev_char = 'c';
		cin >> s;
		int i = 0;
		while(s[i] != '\0'){
			if(s[i] == prev_char){
				count++;
			}
			else{
				prev_char = s[i];
			}
			i++;
		}
		cout << count << endl;
	}
}