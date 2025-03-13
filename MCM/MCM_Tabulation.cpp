#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

void printParenth(vector<vector<int>> bracket, int i, int j, char &matrixName){
    if (i == j){
        cout<<matrixName++;
        return ;
    }

    cout<<"(";
    printParenth(bracket, i, bracket[i][j], matrixName);
    printParenth(bracket, bracket[i][j] + 1, j, matrixName);
    cout<<")";
}

void MCM(vector<int> arr, vector<vector<int>> &bracket){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int len=2; len<n; len++){
        for(int i=1; i<n-len+1; i++){
            int j = i+len-1;

            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++){
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];

                if (cost < dp[i][j]){
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
}

int main(){
    return 0;
}