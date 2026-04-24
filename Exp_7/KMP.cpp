#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buildLPS(string pattern, vector<int>& lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);

    buildLPS(pattern, lps);

    cout << "LPS Array: [";
    for (int k = 0; k < m; k++) {
        cout << lps[k] << (k == m - 1 ? "" : " ");
    }
    cout << "]" << endl;

    int i = 0; 
    int j = 0; 
    bool found = false;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index: " << i - j << endl;
            j = lps[j - 1];
            found = true;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        cout << "Pattern not found in the given text." << endl;
    }
}

int main() {
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;
    cout << "Enter Pattern: ";
    cin >> pattern;

    kmpSearch(text, pattern);

    return 0;
}