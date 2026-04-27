#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    // 1. Input array and window size k
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = arr.size();

    // 2. Deque to store indices of 'useful' elements
    deque<int> dq;

    cout << "Sliding Window Maximums: ";

    // 3. Iterate through the array using index-based loop
    for (int i = 0; i < n; i++) {
        
        // Step A: Remove indices that are out of the current window range
        // If the index at the front is too old (outside i-k+1 to i), pop it
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Step B: Maintain monotonic property (decreasing order)
        // Remove elements from the back that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Step C: Add current element's index to the back
        dq.push_back(i);

        // Step D: The front of the deque is the maximum for the current window
        // Only start printing once we've reached at least k elements
        if (i >= k - 1) {
            cout << arr[dq.front()] << " ";
        }
    }

    cout << endl;
    return 0;
}