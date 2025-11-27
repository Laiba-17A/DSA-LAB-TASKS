#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) { return n ? n->height : 0; }
int balance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* newNode(int key) {
    Node* n = new Node();
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* convertToAVL(Node* root) {
    if (!root) return root;
    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);
    root->height = max(height(root->left), height(root->right)) + 1;
    int bf = balance(root);
    if (bf > 1 && balance(root->left) >= 0) return rightRotate(root);
    if (bf < -1 && balance(root->right) <= 0) return leftRotate(root);
    if (bf > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main() {
    Node* root = newNode(30);
    root->left = newNode(20);
    root->right = newNode(40);
    root = convertToAVL(root);
    cout << root->key;
}
