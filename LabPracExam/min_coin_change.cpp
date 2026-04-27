#include <iostream>
#include <vector>
#include <algorithm> // Required for sort() and reverse()

using namespace std;

// 1. Greedy Approach
void greedyChange(int coins[], int n, int amount) {
    // Two-step sorting to get descending order
    sort(coins, coins + n);            // Sorts: 1, 5, 6, 9
    reverse(coins, coins + n);         // Flips to: 9, 6, 5, 1

    int count = 0;
    cout << "Greedy coins used: ";
    
    for (int i = 0; i < n; i++) {
        // While the current coin can fit into the remaining amount
        while (amount >= coins[i]) {
            amount -= coins[i];         // Deduct coin value
            cout << coins[i] << " ";    // Print the coin used
            count++;                    // Increment total coin count
        }
    }
    cout << "\nTotal Coins (Greedy): " << count << endl;
}

// 2. Dynamic Programming (DP) Approach
void dpChange(vector<int>& coins, int amount) {
    // Initialize dp table with "Infinity" (amount + 1)
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // Base case: 0 coins needed to make 0 amount

    // Build the table from 1 up to the target amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                // The core DP formula:
                // Current min vs. (1 coin + best way to make the remainder)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    if (dp[amount] > amount) {
        cout << "DP: Not possible to make change." << endl;
    } else {
        cout << "Total Coins (DP): " << dp[amount] << endl;
    }
}

int main() {
    // Example: Target 11 with coins {1, 5, 6, 9}
    int coinsArr[] = {1, 5, 6, 9};
    int n = sizeof(coinsArr) / sizeof(coinsArr[0]);
    vector<int> coinsVec = {1, 5, 6, 9};
    int target = 11;

    cout << "Target Amount: " << target << "\n" << endl;

    greedyChange(coinsArr, n, target);
    cout << "---------------------------" << endl;
    dpChange(coinsVec, target);

    return 0;
}