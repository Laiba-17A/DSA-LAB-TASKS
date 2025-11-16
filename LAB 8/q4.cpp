#include<iostream>
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

class bst {
    node* root;
    
    node* insert(node* nd, int val){
        if(nd == NULL){
            return new node(val);
        }
        if(val < nd->data){
            nd->left = insert(nd->left, val);
        }
        else if(val > nd->data){
            nd->right = insert(nd->right, val);
        }
        return nd;
    }
    
    bool search(node* nd, int val) const{
        if(nd == NULL){
            return false;
        }
        if(nd->data == val){
            return true;
        }
        else if(val < nd->data){
            return search(nd->left, val);
        }
        else{
            return search(nd->right, val);
        }
    }
    
    void inorder(node* nd) const{
        if(nd != NULL){
            inorder(nd->left);
            cout << nd->data << " ";
            inorder(nd->right);
        }
    }
    
public:
    bst(){
        root = NULL;
    }
    
    void insert(int val){
        root = insert(root, val);
    }
    
    void searchinsert(int val){
        if(search(root, val)){
            cout << "value " << val << " found in tree" << endl;
        }
        else{
            cout << "value " << val << " not found, inserting" << endl;
            insert(val);
            cout << "new tree: ";
            inorder(root);
            cout << endl;
        }
    }
    
    void display() const{
        cout << "tree: ";
        inorder(root);
        cout << endl;
    }
};

int main(){
    bst tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "initial tree" << endl;
    tree.display();
    
    int val;
    cout << "\nenter value to search: ";
    cin >> val;
    
    tree.searchinsert(val);
    
    cout << "\nenter another value to search: ";
    cin >> val;
    
    tree.searchinsert(val);
    
    return 0;
}
