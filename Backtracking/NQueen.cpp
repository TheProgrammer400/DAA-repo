#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void printSolution(vector<vector<int>> &board, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int i=0; i<row; i++){
        if (board[i][col] == 1){
            return false;
        }
    }

    for(int i=0; i<col; i++){
        if (board[row][i] == 1){
            return false;
        }
    }

    for(int i=row, j=col; i>=0, j>=0; i--, j--){
        if (board[i][j] == 1){
            return false;
        }
    }

    for(int i=row, j=col; i>=0, j<n; i--, j++){
        if (board[i][j] == 1){
            return false;
        }
    }

    return true;
}

void NQueen(vector<vector<int>> &board, int row, int n){
    if (row == n){
        printSolution(board, n);
        return ;
    }

    for(int col=0; col<n; col++){
        if (isSafe(board, row, col, n)){
            board[row][col] = 1;
            NQueen(board, row+1, n);
            board[row][col] = 0;
        }
    }
}


int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    NQueen(board, 0, n);
    return 0;
}