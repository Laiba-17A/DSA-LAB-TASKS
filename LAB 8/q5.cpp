#include<iostream>
#include<climits>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
};

class bintree {
    node* root;
    
    bool isbst(node* nd, int minval, int maxval){
        if(nd == NULL){
            return true;
        }
        
        if(nd->data <= minval || nd->data >= maxval){
            return false;
        }
        
        return isbst(nd->left, minval, nd->data) && 
               isbst(nd->right, nd->data, maxval);
    }
    
    void inorder(node* nd) const{
        if(nd != NULL){
            inorder(nd->left);
            cout << nd->data << " ";
            inorder(nd->right);
        }
    }
    
public:
    bintree(){
        root = NULL;
    }
    
    void setroot(node* nd){
        root = nd;
    }
    
    bool isbst(){
        return isbst(root, INT_MIN, INT_MAX);
    }
    
    void display() const{
        cout << "tree: ";
        inorder(root);
        cout << endl;
    }
};

int main(){
    bintree tree1;
    
    node* root1 = new node(50);
    root1->left = new node(30);
    root1->right = new node(70);
    root1->left->left = new node(20);
    root1->left->right = new node(40);
    root1->right->left = new node(60);
    root1->right->right = new node(80);
    
    tree1.setroot(root1);
    
    cout << "tree 1" << endl;
    tree1.display();
    
    if(tree1.isbst()){
        cout << "this is a valid binary search tree" << endl;
    }
    else{
        cout << "this is not a valid binary search tree" << endl;
    }
    
    cout << endl;
    
    bintree tree2;
    
    node* root2 = new node(50);
    root2->left = new node(30);
    root2->right = new node(70);
    root2->left->left = new node(20);
    root2->left->right = new node(60);
    root2->right->left = new node(40);
    root2->right->right = new node(80);
    
    tree2.setroot(root2);
    
    cout << "tree 2" << endl;
    tree2.display();
    
    if(tree2.isbst()){
        cout << "this is a valid binary search tree" << endl;
    }
    else{
        cout << "this is not a valid binary search tree" << endl;
    }
    
    cout << endl;
    
    bintree tree3;
    
    
    
    return 0;
}
