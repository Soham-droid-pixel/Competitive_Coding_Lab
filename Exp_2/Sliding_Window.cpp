#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findMaxInSlidingWindow(const vector<int>& numbers, int windowSize) {
    vector<int> maxValues;
    
    if (numbers.empty() || windowSize == 0) {
        return maxValues;
    }
    
    deque<int> windowIndices;
    
    for (int i = 0; i < numbers.size(); i++) {
        
        while (!windowIndices.empty() && windowIndices.front() < i - windowSize + 1) {
            windowIndices.pop_front();
        }
        
        while (!windowIndices.empty() && numbers[windowIndices.back()] < numbers[i]) {
            windowIndices.pop_back();
        }
        
        windowIndices.push_back(i);
        
        if (i >= windowSize - 1) {
            maxValues.push_back(numbers[windowIndices.front()]);
        }
    }
    
    return maxValues;
}

int main() {
    vector<int> numbers = {1, 3, -1, -3, 5, 3, 6, 7};
    int windowSize = 3;
    
    vector<int> result = findMaxInSlidingWindow(numbers, windowSize);
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
    
    return 0;
}