#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard mix
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Test 1 | Expected: 0 0 1 1 2 2 | Got: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;

    // Test Case 2: Already sorted
    vector<int> nums2 = {0, 1, 2};
    sol.sortColors(nums2);
    cout << "Test 2 | Expected: 0 1 2 | Got: ";
    for(int x : nums2) cout << x << " ";
    cout << endl;

    // Test Case 3: All same elements
    vector<int> nums3 = {2, 2, 2};
    sol.sortColors(nums3);
    cout << "Test 3 | Expected: 2 2 2 | Got: ";
    for(int x : nums3) cout << x << " ";
    cout << endl;

    return 0;
}