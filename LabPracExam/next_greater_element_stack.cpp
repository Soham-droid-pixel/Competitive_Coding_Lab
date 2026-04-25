#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // 1. Initialize the input array
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // 2. This will store our results
    int nge[n]; 
    
    // 3. Stack to keep track of elements on the right
    stack<int> s;

    // 4. Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        
        // 5. While stack is not empty and top is smaller or equal to current element, pop
        // We do this because the current element will be the "Next Greater" for elements to the left,
        // rendering smaller elements in the stack useless.
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop(); 
        }

        // 6. If stack is empty, no greater element exists to the right
        if (s.empty()) {
            nge[i] = -1; 
        } 
        // 7. Otherwise, the top of the stack is the next greater element
        else {
            nge[i] = s.top();
        }

        // 8. Push the current element onto the stack for the next elements on the left
        s.push(arr[i]);
    }

    // 9. Print the results
    cout << "Element -> Next Greater Element" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " \t -> \t " << nge[i] << endl;
    }

    return 0;
}