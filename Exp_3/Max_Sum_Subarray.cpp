#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int sum=0;
        int max_sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        max_sum=sum;
        for(int i=k;i<nums.size();i++){
            sum=sum+nums[i];
            sum=sum-nums[i-k];
            if(sum>max_sum){
                max_sum=sum;
            }
        }
        return max_sum;
    }
};
int main() {
    Solution sol;

    vector<int> arr1 = {2, 1, 5, 1, 3, 2};
    int k1 = 3;
    cout << "Test 1 | Expected: 9 | Got: " << sol.maxSumSubarray(arr1, k1) << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Test 2 | Expected: 9 | Got: " << sol.maxSumSubarray(arr2, k2) << endl;

    vector<int> arr3 = {10, 20, 30, 40};
    int k3 = 4;
    cout << "Test 3 | Expected: 100 | Got: " << sol.maxSumSubarray(arr3, k3) << endl;

    vector<int> arr4 = {-1, -2, -3, -4};
    int k4 = 2;
    cout << "Test 4 | Expected: -3 | Got: " << sol.maxSumSubarray(arr4, k4) << endl;

    return 0;
}
