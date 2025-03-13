#include<iostream>
#include<climits>
using namespace std;

int mcm(int arr[], int i, int j) {
    if(i >= j) {
        return 0; // Base case: No multiplication needed for a single matrix
    }

    int minCost = INT_MAX;

    for(int k = i; k < j; k++) {
        int cost = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        minCost = min(minCost, cost);
    }

    return minCost;
}

int main() {
    int arr[] = {1, 2, 3, 4}; // 3 matrices: A(1x2), B(2x3), C(3x4)
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Cost: " << mcm(arr, 1, n - 1) << endl;
    return 0;
}
