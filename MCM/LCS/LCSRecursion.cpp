#include<iostream>
#include<algorithm>
using namespace std;

int LCS(string s1, string s2, int i, int j) {
    if(i < 0 || j < 0) {
        return 0;
    }

    if(s1[i] == s2[j]) {
        return 1 + LCS(s1, s2, i - 1, j - 1);
    } else {
        return max(LCS(s1, s2, i - 1, j), LCS(s1, s2, i, j - 1));
    }
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "LCS length: " << LCS(s1, s2, s1.length() - 1, s2.length() - 1) << endl;
    return 0;
}
