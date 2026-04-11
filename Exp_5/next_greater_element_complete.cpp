#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    void findNextGreater(const string& testName, vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[i] > arr[s.top()]) {
                nge[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }

        cout << "TEST CASE: " << testName << endl;
        cout << "Input:  ";
        for (int x : arr) cout << x << " ";
        cout << "\nOutput: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "->" << nge[i] << "  ";
        }
        cout << "\n-------------------------------" << endl;
    }
};

int main() {
    Solution sol;

    sol.findNextGreater("Standard Case", {4, 5, 2, 25});
    sol.findNextGreater("Increasing Order", {10, 20, 30, 40});
    sol.findNextGreater("Decreasing Order", {50, 40, 30, 20});
    sol.findNextGreater("Duplicates", {5, 2, 5, 2, 8});
    sol.findNextGreater("Single Element", {100});
    sol.findNextGreater("Empty Array", {});

    return 0;
}