#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                return{left+1,right+1};
            }
            else if(numbers[left]+numbers[right]<target){
                left++;
            }
            else{
                right--;
            }
        }
        return{-1,-1};
    }
};


int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Test 1 | Expected: 1 2 | Got: ";
    for(int i : res1) cout << i << " ";
    cout << endl;

    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Test 2 | Expected: 1 3 | Got: ";
    for(int i : res2) cout << i << " ";
    cout << endl;

    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "Test 3 | Expected: 1 2 | Got: ";
    for(int i : res3) cout << i << " ";
    cout << endl;

    return 0;
}