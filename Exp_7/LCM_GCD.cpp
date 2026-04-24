#include <iostream>
#include <numeric>

using namespace std;

long long getGCD(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long a, b, m;
    
    if (!(cin >> a >> b)) return 0;
    if (!(cin >> m)) return 0;

    long long gcdVal = getGCD(a, b);
    long long lcmVal = (a * b) / gcdVal;

    cout << "GCD = " << gcdVal << endl;
    cout << "LCM = " << lcmVal << endl;
    cout << "(a + b) mod m = " << (a + b) % m << endl;
    cout << "(a * b) mod m = " << (a * b) % m << endl;

    if (gcdVal == 1) {
        cout << "Coprime" << endl;
    } else {
        cout << "Not Coprime" << endl;
    }

    return 0;
}