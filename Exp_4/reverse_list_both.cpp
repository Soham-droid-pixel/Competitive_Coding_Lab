#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseIterative(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseRecursive(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    vector<int> values = {1, 2, 3, 4, 5};

    ListNode* head1 = createList(values);
    cout << "Iterative Original: ";
    printList(head1);
    head1 = sol.reverseIterative(head1);
    cout << "Iterative Reversed: ";
    printList(head1);
    cout << "-----------------------" << endl;

    ListNode* head2 = createList(values);
    cout << "Recursive Original: ";
    printList(head2);
    head2 = sol.reverseRecursive(head2);
    cout << "Recursive Reversed: ";
    printList(head2);

    deleteList(head1);
    deleteList(head2);

    return 0;
}