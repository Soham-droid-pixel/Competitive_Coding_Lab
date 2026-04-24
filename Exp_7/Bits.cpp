#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

unsigned int reverseBits(unsigned int n) {
    unsigned int res = 0;
    for (int i = 0; i < 8; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int getXOR(vector<int> arr) {
    int res = 0;
    for (int x : arr) res ^= x;
    return res;
}

void printSubsets(vector<char> S) {
    int n = S.size();
    int totalSubsets = (1 << n);
    for (int i = 0; i < totalSubsets; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                cout << S[j] << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    unsigned int reversed = reverseBits(n);
    cout << "Original Binary: " << bitset<8>(n) << endl;
    cout << "Reversed Binary: " << bitset<8>(reversed) << endl;
    cout << "Decimal Value: " << reversed << endl;
    cout << "Set Bits Count: " << countSetBits(n) << endl;

    vector<int> arr = {1, 2, 3, 4, 5}; 
    cout << "XOR of {1,2,3,4,5}: " << getXOR(arr) << endl;

    cout << "\nAll Subsets of {A, B, C}:" << endl;
    vector<char> set = {'A', 'B', 'C'};
    printSubsets(set);

    return 0;
}