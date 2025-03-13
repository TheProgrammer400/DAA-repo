#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MCM(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if(i >= j){
        return 0; // Base case: No multiplication needed
    }

    if(dp[i][j] != -1){
        return dp[i][j]; // Return if already computed
    }

    int minCost = INT_MAX;

    for(int k = i; k < j; k++) {
        int cost = MCM(arr, i, k, dp) + MCM(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

int main() {
    vector<int> arr = {10, 30, 5, 60}; // Matrix dimensions
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table

    cout << "Minimum multiplication cost: " << MCM(arr, 1, n - 1, dp) << endl;
    return 0;
}