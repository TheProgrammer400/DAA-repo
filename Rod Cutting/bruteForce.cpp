#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int> &price, int n) {
    if(n == 0) {
        return 0;
    }

    int maxProfit = 0;

    for(int i = 1; i <= n; i++) {
        maxProfit = max(maxProfit, price[i - 1] + rodCutting(price, n - i)); 
    }

    return maxProfit;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Example price array
    int n = price.size(); // Rod length
    cout << "Maximum Profit: " << rodCutting(price, n) << endl;
    return 0;
}
