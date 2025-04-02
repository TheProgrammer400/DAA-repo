#include<iostream>
using namespace std;

#define PRIME 101 // Prime number for hashing

// Function to calculate hash value of a string
long long calculateHash(string str, int len) {
    long long hash = 0;
    long long pow = 1;

    for(int i = 0; i < len; i++) {
        hash += (str[i] * pow);
        pow *= PRIME;
    }
    return hash;
}

// Rabin-Karp pattern matching algorithm
void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if(n < m) {
        return ;
    }

    long long patternHash = calculateHash(pattern, m);
    long long textHash = calculateHash(text, m);
    long long primePow = 1;

    // Precompute prime^(m-1) for rolling hash
    for(int i = 1; i < m; i++) {
        primePow *= PRIME;
    }

    for(int i = 0; i <= n - m; i++) {
        if(patternHash == textHash) { 
            // Check character by character in case of hash collision
            bool matched = true;

            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    matched = false;
                    break;
                }
            }

            if(matched) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Rolling hash: Remove first character, add next character
        if(i < n - m) {
            textHash = (textHash - text[i]) / PRIME + text[i + m] * primePow;
        }
    }
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";
    
    rabinKarp(text, pattern);
    
    return 0;
}
