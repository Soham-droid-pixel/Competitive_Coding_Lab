#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to detect and remove loop
void detectAndRemoveLoop(Node* head) {
    if (!head || !head->next) return; // Base case: empty list or single node

    Node *slow = head, *fast = head; // Initialize both pointers at head

    // 1. Detect if a loop exists
    while (fast && fast->next) {
        slow = slow->next;          // Move slow 1 step
        fast = fast->next->next;    // Move fast 2 steps
        if (slow == fast) break;    // Loop detected!
    }

    // 2. If loop exists, find the start and remove it
    if (slow == fast) {
        slow = head;               // Reset slow to head
        
        // Special case: If the loop starts at the head itself
        if (slow == fast) {
            while (fast->next != slow) fast = fast->next; // Find the last node
        } else {
            // Move both pointers 1 step until they meet at loop start
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;          // Break the loop by setting next to NULL
    }
}

// Helper: Insert node at end
void insert(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Helper: Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    // Creating a loop for testing: 5 -> 3
    head->next->next->next->next->next = head->next->next; 

    cout << "Detecting and removing loop..." << endl;
    detectAndRemoveLoop(head);

    cout << "List after removal: ";
    printList(head);

    return 0;
}