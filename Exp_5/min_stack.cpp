#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Initial Min: " << ms.getMin() << endl;
    
    ms.pop();
    cout << "Min after one pop: " << ms.getMin() << endl;
    
    ms.pop();
    ms.pop();
    cout << "Min after three pops: " << ms.getMin() << endl;

    return 0;
}