#include <iostream>  // For input and output
#include <queue>     // For using the queue data structure
#include <string>    // For handling binary numbers as strings

using namespace std;

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n; // Input the limit N

    // 1. Create a queue to store binary numbers as strings to avoid integer overflow
    queue<string> q;

    // 2. Push the first binary number "1" into the queue
    q.push("1");

    cout << "Binary numbers from 1 to " << n << ":" << endl;

    // 3. Loop N times to generate and print each binary number
    for (int i = 1; i <= n; i++) {
        // 4. Get the front element of the queue
        string current = q.front();
        
        // 5. Remove the front element from the queue
        q.pop();

        // 6. Print the current binary number
        cout << current << " ";

        // 7. Generate the next two binary numbers by appending '0' and '1'
        string s1 = current + "0"; // Example: If current is "1", s1 becomes "10"
        string s2 = current + "1"; // Example: If current is "1", s2 becomes "11"

        // 8. Push the newly generated numbers back into the queue
        q.push(s1); // This will be processed later in order
        q.push(s2); // This will be processed after s1
    }

    cout << endl;
    return 0; // End of program
}