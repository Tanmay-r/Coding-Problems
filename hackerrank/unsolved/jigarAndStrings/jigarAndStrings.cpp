#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    string s;
    while(T--){
        map<char, int> hash_set;
        cin >> s;
        int i = 0;
        while(s[i] != '\0'){
            if(hash_set.find(s[i]) == hash_set.end()){
                hash_set.insert(make_pair<char,int>(s[i], 1));
            }
            else{
                hash_set[s[i]] = hash_set[s[i]] + 1;
            }
            i++;
        }
        int average_size = i/hash_set.size();
        int output = 0;
        for (map<char,int>::iterator my_iterator = hash_set.begin(); my_iterator != hash_set.end(); ++my_iterator){
            output += abs(my_iterator->second - average_size);
        }
        cout << output/2 << endl;
    }
}