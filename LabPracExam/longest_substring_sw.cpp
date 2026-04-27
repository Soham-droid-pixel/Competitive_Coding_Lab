#include <iostream>       // For input and output
#include <string>         // For using the string class
#include <unordered_set>  // For the hashset data structure
#include <algorithm>      // For the max() function

using namespace std;

int main() {
    string s = "pwwkew";           // Example input string
    int n = s.length();            // Get the total length of the string
    
    unordered_set<char> charSet;   // Create a hashset to store unique characters in current window
    int left = 0;                  // Left pointer: marks the start of the window
    int right = 0;                 // Right pointer: marks the end of the window
    int maxLen = 0;                // Variable to track the longest valid window found

    // 1. Traverse the string using the 'right' pointer
    while (right < n) {
        
        // 2. Check if the current character already exists in our set (window)
        // .find() returns .end() if the character is NOT found
        while (charSet.find(s[right]) != charSet.end()) {
            
            // 3. Duplicate found! We must shrink the window from the left
            charSet.erase(s[left]); // Remove the leftmost character from the set
            left++;                 // Move the left pointer forward
        }

        // 4. Once the duplicate is removed, add the current character to the set
        charSet.insert(s[right]);

        // 5. Update the max length: current window size is (right - left + 1)
        maxLen = max(maxLen, right - left + 1);

        // 6. Move the right pointer to expand the window for the next iteration
        right++;
    }

    // Output the results
    cout << "Original String: " << s << endl;
    cout << "Longest Substring Length: " << maxLen << endl;

    return 0;
}