#include <iostream>
#include <string>

using namespace std;

void bruteForceSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    // 1. Loop through the text until the pattern can't fit anymore
    for (int i = 0; i <= n - m; i++) {
        int j;

        // 2. For the current starting position 'i', check the pattern
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, stop checking this position
            }
        }

        // 3. If j reached the end of the pattern, it's a full match!
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if (!found) cout << "Pattern not found." << endl;
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    bruteForceSearch(text, pattern);

    return 0;
}