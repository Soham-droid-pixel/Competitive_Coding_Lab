#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int nums[n];
    cout << "Enter sorted elements: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int comparisons = 0;
    int low = 0;
    int high = n - 1;
    bool found = false;

    while(low <= high) {
        comparisons++;
        int mid = (low + high) / 2;

        if(nums[mid] == target) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if(nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(!found) {
        cout << "Element not found" << endl;
    }

    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}