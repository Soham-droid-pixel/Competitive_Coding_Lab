#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test 1 | Expected: 4 | Got: " << sol.search(nums1, target1) << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test 2 | Expected: -1 | Got: " << sol.search(nums2, target2) << endl;

    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Test 3 | Expected: -1 | Got: " << sol.search(nums3, target3) << endl;

    vector<int> nums4 = {6, 7, 1, 2, 3, 4, 5};
    int target4 = 6;
    cout << "Test 4 | Expected: 0 | Got: " << sol.search(nums4, target4) << endl;

    return 0;
}