#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    unordered_set<int> nums;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.insert(temp);
    }

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    if(nums.find(target) != nums.end()) {
        cout << "Element found in the set" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}