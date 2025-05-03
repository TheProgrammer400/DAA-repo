#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string LCS(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    } 

    // Now backtrack to build the actual LCS string
    int i = n, j = m;
    string lcs = "";

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs += s1[i-1]; // Add matching character
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end()); // Since we built it backwards
    return lcs;
}

int main() {
    string s1 = "ACDBE";
    string s2 = "ABCDE";
    cout<<"LCS: "<<LCS(s1, s2)<<endl;
    return 0;
}