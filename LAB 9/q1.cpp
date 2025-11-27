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

/*
=========================================================================================
WHY AVL? EXPLAINED IN TWO LINES:
=========================================================================================

1. AVL trees maintain O(log n) time complexity for search, insert, and delete operations
   by keeping the tree balanced, whereas BST can degrade to O(n) when unbalanced.

2. The height-balancing property (|left_height - right_height| = 1) ensures the tree
   depth stays minimal, preventing worst-case scenarios where BST becomes like a linked list.

=========================================================================================
CODE EXPLANATION (Each Step):
=========================================================================================

STEP 1: countNodes(root)
- Recursively counts total number of nodes in the BST
- WHY: We need to know array size for storing all node values
- Returns total count which is used to allocate dynamic array

STEP 2: storeInorder(root, arr[], index)
- Performs inorder traversal of BST (left ? root ? right)
- Stores all node values in array in sorted order using index parameter
- For BST A: [4, 8, 9, 10] and BST B: [10, 12, 16, 18]
- WHY: BST inorder gives sorted sequence, which we use to build balanced tree

STEP 3: buildAVL(arr[], start, end)
- Recursively builds a balanced AVL tree from sorted array
- Picks middle element as root (ensures balance)
- Recursively builds left subtree from left half [start to mid-1]
- Recursively builds right subtree from right half [mid+1 to end]
- Updates height at each node after building children
- WHY: Middle element as root creates height-balanced tree automatically

STEP 4: Node Linking in AVL
- Each recursive call returns a Node* which becomes child of parent
- Variables represent nodes at different levels during construction
- For BST A: middle index gives 8 or 9 as root (depending on array size)
- Left child gets built from smaller elements, right from larger
- Parent stores returned pointers in left/right fields
- WHY: Recursive approach naturally creates proper parent-child relationships

STEP 5: Rotation Types (Available but not used in this approach)
- RIGHT ROTATION: Used when left subtree is heavier (left-left case)
  Moves left child up, original root becomes right child
- LEFT ROTATION: Used when right subtree is heavier (right-right case)
  Moves right child up, original root becomes left child
- DOUBLE ROTATIONS: Combination for left-right/right-left cases
- NOTE: This conversion rebuilds from scratch, so rotations aren't explicitly needed
- Rotations would be used for incremental AVL insertions/deletions

STEP 6: Node Returned (buildAVL returns Node*)
- Each recursive call returns the root of the subtree it built
- The final return is the root of the complete balanced AVL tree
- This root has all children properly linked in balanced structure
- Memory for array is freed after tree construction
- WHY RETURN ROOT: Allows recursive construction where each level knows its subtree root

3-4 LINE SUMMARY OF WHICH NODE IS RETURNED:
The convertBSTtoAVL function returns the root node of the newly constructed balanced AVL 
tree. This root is the middle element of the sorted array, with its left and right 
children being roots of recursively built balanced subtrees. The returned node maintains 
AVL properties with all heights and balance factors correctly set, ensuring O(log n) 
operations for the tree.

=========================================================================================
*/
