#include<iostream>
#include<vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPS(string pattern, vector<int> &lps) {
    int m = pattern.length();
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // First value is always 0

    int i = 1;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1]; // Move to  previous LPS value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to find all occurrences of pattern in text
void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    
    computeLPS(pattern, lps); // Precompute LPS array

    int i = 0, j = 0; // Pointers for text and pattern
    
    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) { // Found a match
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Move j to the last matched LPS
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0) {
                j = lps[j - 1]; // Move j to previous LPS value
            } else {
                i++; // Move to the next character in text
            }
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    
    KMP(text, pattern);

    return 0;
}
