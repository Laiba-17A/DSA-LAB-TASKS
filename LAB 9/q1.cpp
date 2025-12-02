#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : data(val), left(NULL), right(NULL), height(1) {}
};

// Get height of node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Count total nodes in tree
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Store inorder traversal in array
void storeInorder(Node* root, int arr[], int& index) {
    if (!root) return;
    storeInorder(root->left, arr, index);
    arr[index++] = root->data;
    storeInorder(root->right, arr, index);
}

// Build balanced AVL from sorted array
Node* buildAVL(int arr[], int start, int end) {
    if (start > end) return NULL;
    
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    
    root->left = buildAVL(arr, start, mid - 1);
    root->right = buildAVL(arr, mid + 1, end);
    
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    return root;
}

// Main conversion function
Node* convertBSTtoAVL(Node* root) {
    int n = countNodes(root);
    int* arr = new int[n];
    int index = 0;
    
    storeInorder(root, arr, index);
    Node* avlRoot = buildAVL(arr, 0, n - 1);
    
    delete[] arr;
    return avlRoot;
}

// Helper function to print tree (for testing)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printTreeStructure(Node* root, string prefix = "", bool isLeft = true) {
    if (!root) return;
    
    cout << prefix;
    cout << (isLeft ? "+--" : "+--");
    cout << root->data << " (h=" << root->height << ", bf=" << getBalance(root) << ")" << endl;
    
    if (root->left || root->right) {
        if (root->left)
            printTreeStructure(root->left, prefix + (isLeft ? "¦   " : "    "), true);
        if (root->right)
            printTreeStructure(root->right, prefix + (isLeft ? "¦   " : "    "), false);
    }
}

int main() {
    // Example BST A: Creating the unbalanced tree from image
    Node* rootA = new Node(10);
    rootA->left = new Node(8);
    rootA->left->left = new Node(4);
    rootA->left->right = new Node(9);
    
    cout << "Original BST A (Inorder): ";
    printInorder(rootA);
    cout << "\n\nOriginal BST A Structure:\n";
    printTreeStructure(rootA);
    
    Node* avlA = convertBSTtoAVL(rootA);
    
    cout << "\n\nConverted AVL Tree A (Inorder): ";
    printInorder(avlA);
    cout << "\n\nConverted AVL Tree A Structure:\n";
    printTreeStructure(avlA);
    
    cout << "\n" << string(60, '=') << "\n\n";
    
    // Example BST B: Creating the unbalanced tree from image
    Node* rootB = new Node(10);
    rootB->right = new Node(16);
    rootB->right->left = new Node(12);
    rootB->right->right = new Node(18);
    
    cout << "Original BST B (Inorder): ";
    printInorder(rootB);
    cout << "\n\nOriginal BST B Structure:\n";
    printTreeStructure(rootB);
    
    Node* avlB = convertBSTtoAVL(rootB);
    
    cout << "\n\nConverted AVL Tree B (Inorder): ";
    printInorder(avlB);
    cout << "\n\nConverted AVL Tree B Structure:\n";
    printTreeStructure(avlB);
    
    return 0;
}


