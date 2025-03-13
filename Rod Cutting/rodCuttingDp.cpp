#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rodCutting(vector<int> price, int n){
    vector<int> dp(n+1, 0);

    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] = max(dp[i], price[i]+dp[i-j-1]);
        }
    }

    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // prices
    int n = price.size();
    
    cout << "Maximum Obtainable Value: " << rodCutting(price, n) << endl;
    return 0;
}