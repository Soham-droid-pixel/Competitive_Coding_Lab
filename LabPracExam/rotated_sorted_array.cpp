#include <iostream>
#include <vector>

using namespace std;

// Function to search in rotated sorted array
int searchRotated(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid to avoid overflow

        // 1. Check if mid is the target
        if (arr[mid] == target) return mid;

        // 2. Identify which half is sorted
        // If left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target lies within the sorted left half
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1; // Target is in the left half
            } else {
                low = mid + 1;  // Target is in the right half
            }
        } 
        // 3. Otherwise, the right half MUST be sorted
        else {
            // Check if target lies within the sorted right half
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;  // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
    }

    return -1; // Target not found
}

int main() {
    // Example: Sorted [0, 1, 2, 4, 5, 6, 7] rotated at index 3
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = searchRotated(arr, target);

    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}