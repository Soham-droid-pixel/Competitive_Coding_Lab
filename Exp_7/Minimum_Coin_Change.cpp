#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getGreedy(int n, vector<int> coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return (amount == 0) ? count : -1;
}

int getDP(int n, vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    
    if (!(cin >> n)) return 0;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> amount;

    int greedyResult = getGreedy(n, coins, amount);
    int dpResult = getDP(n, coins, amount);

    cout << "Greedy Coins = " << greedyResult << endl;
    cout << "DP Coins = " << dpResult << endl;

    if (greedyResult == dpResult) {
        cout << "Greedy is Optimal" << endl;
    } else {
        cout << "Greedy is Not Optimal" << endl;
    }

    return 0;
}