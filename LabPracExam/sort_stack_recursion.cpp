#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert an element into a sorted stack
void sortedInsert(stack<int>& s, int element) {
    // If stack is empty or the element is greater than the top, push it
    if (s.empty() || element > s.top()) {
        s.push(element); // This is the correct spot for the element
        return;          // Return to the previous call
    }

    // If the top is greater, pop it and keep searching for the right spot
    int temp = s.top();  // Store the top element temporarily
    s.pop();             // Remove the top element
    sortedInsert(s, element); // Recursive call to insert in the remaining stack

    // Once the element is inserted, push the stored element back
    s.push(temp);        // Restoring the elements after insertion
}

// Main function to sort the stack
void sortStack(stack<int>& s) {
    // Base Case: If stack is empty, it is already sorted
    if (s.empty()) return;

    // Pop the top element
    int temp = s.top();  // Hold the top element in the function's stack frame
    s.pop();             // Remove it from the stack

    // Recursively sort the remaining stack
    sortStack(s);        // This will keep popping until the stack is empty

    // Insert the popped element back into the now-sorted stack
    sortedInsert(s, temp); // Place 'temp' in its correct sorted position
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original Stack (top to bottom): ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack (top to bottom): ";
    printStack(s);

    return 0;
}