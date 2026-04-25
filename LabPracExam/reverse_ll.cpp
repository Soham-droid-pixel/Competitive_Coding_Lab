#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;           // Holds the value
    Node* next;         // Pointer to the next node
};

// Function to reverse the list in groups of K
Node* reverseKGroup(Node* head, int k) {
    if (!head) return NULL;           // Base case: if list is empty, stop
    
    Node* curr = head;                // 'curr' tracks the node we are currently processing
    Node* prev = NULL;                // 'prev' will become the new head of this reversed group
    Node* nextNode = NULL;            // 'nextNode' stores the rest of the list temporarily
    int count = 0;                    // Counter to keep track of how many nodes we've reversed

    // 1. Reverse the first k nodes of the current segment
    while (curr != NULL && count < k) { 
        nextNode = curr->next;        // Save the next node before we break the link
        curr->next = prev;            // Flip the pointer: current now points backwards to prev
        prev = curr;                  // Move prev one step forward (to the current node)
        curr = nextNode;              // Move curr one step forward (to the next node)
        count++;                      // Increment count until we hit k nodes
    }

    // 2. 'head' is now the tail of our reversed segment.
    // We recursively call the function for the remaining list and link it here.
    if (nextNode != NULL) {           
        head->next = reverseKGroup(nextNode, k); // Link the current tail to the next reversed group
    }

    // 3. 'prev' is now the head of this reversed segment
    return prev;                      
}

// Helper function to insert nodes at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node{val, NULL}; // Create a new node with value and NULL pointer
    if (!head) { head = newNode; return; } // If list is empty, new node is the head
    Node* temp = head;                 // Start from head to find the end
    while (temp->next) temp = temp->next; // Traverse to the last node
    temp->next = newNode;              // Link the last node to the new node
}

// Helper function to print the list
void printList(Node* head) {
    while (head) {                    // Loop until the end of the list
        cout << head->data << " -> "; // Print current data
        head = head->next;            // Move to the next node
    }
    cout << "NULL" << endl;           // Indicate the end of the list
}

int main() {
    Node* head = NULL;                // Initialize an empty list
    int n = 6, k = 2;                 // Total nodes and group size K

    for (int i = 1; i <= n; i++) insert(head, i); // Create list: 1->2->3->4->5->6

    cout << "Original List: ";
    printList(head);                  // Show original list

    head = reverseKGroup(head, k);    // Perform the group reversal

    cout << "Reversed in groups of " << k << ": ";
    printList(head);                  // Show the final modified list

    return 0;                         // End of program
}