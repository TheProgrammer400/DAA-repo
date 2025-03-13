#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void naiveAlgo(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    
    for(int i=0; i<=n-m; i++){
        bool matched = true;

        for(int j=0; j<m; j++){
            if (s1[i+j] != s2[j]){
                matched = false;
                break;
            }
        }

        if (matched){
            cout<<"String found at index "<<i<<endl;
        }
    }
}

int main() {
    string text = "ABABABCABABABCABABABC";
    string pattern = "ABABC";
    naiveAlgo(text, pattern);
    return 0;
}