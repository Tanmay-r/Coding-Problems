#include <iostream>

using namespace std;

int main(){
    int T = 0;
    cin >> T;

    string word, output;
    
    while(T--){
        cin >> word;
        char largest = '\0';
        int largestIndex = -1;
        int i = 0;
        while(word[i] != '\0'){
            if(word[i] > largest){
                largestIndex = i;
                largest = word[i];
            }
            else if(word[i] == largest){
                int j = largestIndex + 1;
                int k = i + 1;
                if(word[k] == '\0'){
                    k = 0;
                }
                while(word[k] == word[j]){
                    j++;
                    k++;
                    if(word[k] == '\0'){
                        k = 0;
                    }
                }
                if(word[k] > word[j]){
                    largest = word[i];
                    largestIndex = i;
                }
            }
            i++;
        }
        for(int j = largestIndex; word[j] != '\0'; j++){
            cout << word[j];
        }
        for(int j = 0; j < largestIndex; j++){
            cout << word[j];
        }
        cout << endl;
    }
}