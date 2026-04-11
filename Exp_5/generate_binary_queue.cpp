#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateBinaryNumbers(int n) {
        vector<string> result;
        if (n <= 0) return result;

        queue<string> q;
        q.push("1");

        for (int i = 0; i < n; i++) {
            string s = q.front();
            q.pop();

            result.push_back(s);

            string s1 = s + "0";
            string s2 = s + "1";

            q.push(s1);
            q.push(s2);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution sol;
    vector<string> binaryNumbers = sol.generateBinaryNumbers(n);

    for (const string& s : binaryNumbers) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}