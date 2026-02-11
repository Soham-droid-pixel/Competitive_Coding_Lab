#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    int index = -1;

    for(int i = 0; i < n; i++) {
        if(nums[i] == target) {
            index = i;
            break;
        }
    }

    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}