#include <iostream>
#include <algorithm> // Used for the max() function
using namespace std;

// 1. Structure for an AVL Tree Node
struct Node {
    int key;            // The value of the node
    Node *left, *right; // Pointers to left and right children
    int height;         // Height of the node for balance calculation
    Node(int k) : key(k), left(NULL), right(NULL), height(1) {} // Initial height is 1
};

// 2. Helper function to get the height of a node safely
int getHeight(Node* n) {
    return n ? n->height : 0; // Return 0 if node is NULL, else return height
}

// 3. Helper function to calculate the balance factor
int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0; // Left height - Right height
}

// 4. Right Rotation (Used for LL Case)
Node* rightRotate(Node* y) {
    Node* x = y->left;          // x becomes the new root
    Node* T2 = x->right;        // Save x's right subtree
    x->right = y;               // Perform rotation
    y->left = T2;               // Link T2 as y's left child
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // Update y height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; // Update x height
    return x;                   // Return the new root
}

// 5. Left Rotation (Used for RR Case)
Node* leftRotate(Node* x) {
    Node* y = x->right;         // y becomes the new root
    Node* T2 = y->left;         // Save y's left subtree
    y->left = x;                // Perform rotation
    x->right = T2;              // Link T2 as x's right child
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; // Update x height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // Update y height
    return y;                   // Return the new root
}

// 6. Main Insert Function
Node* insert(Node* node, int key) {
    // Standard BST Insertion
    if (!node) return new Node(key); // Create node if spot is empty
    if (key < node->key) node->left = insert(node->left, key); // Go left if smaller
    else if (key > node->key) node->right = insert(node->right, key); // Go right if larger
    else return node; // Duplicate keys are not allowed in AVL

    // Update height of current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor to check for imbalance
    int balance = getBalance(node);

    // Case 1: Left Left (LL) -> Requires single Right Rotation
    if (balance > 1 && key < node->left->key) return rightRotate(node);

    // Case 2: Right Right (RR) -> Requires single Left Rotation
    if (balance < -1 && key > node->right->key) return leftRotate(node);

    // Case 3: Left Right (LR) -> Requires Left then Right Rotation
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL) -> Requires Right then Left Rotation
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the (potentially rotated) node
}

// 7. Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);    // Visit left
        cout << root->key << " "; // Print current
        inorder(root->right);   // Visit right
    }
}

int main() {
    Node* root = NULL; // Start with an empty tree
    int values[] = {10, 20, 30, 40, 50, 25}; // Sequence to insert

    for (int v : values) {
        root = insert(root, v); // Insert elements one by one
    }

    cout << "Inorder Traversal of constructed AVL Tree: ";
    inorder(root); // Should print values in sorted order
    cout << endl;

    return 0;
}