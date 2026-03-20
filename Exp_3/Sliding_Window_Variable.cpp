#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> seen;

        for (int right = 0; right < s.length(); right++) {
            // While the current character is a duplicate...
            while (seen.find(s[right]) != seen.end()) {
                // Shrink from the left and remove characters from the set
                seen.erase(s[left]);
                left++;
            }
            
            // Now that the window is clean, add the new character
            seen.insert(s[right]);
            
            // Update the record
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    cout << "Test 1 (abcabcbb): " << sol.lengthOfLongestSubstring("abcabcbb") << " | Expected: 3" << endl;
    cout << "Test 2 (bbbbb): " << sol.lengthOfLongestSubstring("bbbbb") << " | Expected: 1" << endl;
    cout << "Test 3 (pwwkew): " << sol.lengthOfLongestSubstring("pwwkew") << " | Expected: 3" << endl;
    return 0;
}