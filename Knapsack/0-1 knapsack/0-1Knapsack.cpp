#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int n, int W) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(weight[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w - weight[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 4, 5, 6};
    int W = 5;
    
    cout << "Maximum Value: " << knapsack(weight, value, weight.size(), W) << endl;
    return 0;
}
