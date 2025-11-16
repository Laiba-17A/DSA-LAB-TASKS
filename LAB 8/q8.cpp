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
    
    int countrange(node* nd, int a, int b){
        if(nd == NULL){
            return 0;
        }
        
        int count = 0;
        
        if(nd->data >= a && nd->data <= b){
            count = 1;
            cout << nd->data << " ";
        }
        
        if(nd->data > a){
            count += countrange(nd->left, a, b);
        }
        
        if(nd->data < b){
            count += countrange(nd->right, a, b);
        }
        
        return count;
    }
    
    void display(node* nd) const{
        if(nd != NULL){
            display(nd->left);
            cout << nd->data << " ";
            display(nd->right);
        }
    }
    
public:
    bst(){
        root = NULL;
    }
    
    void insert(int val){
        root = insert(root, val);
    }
    
    void countrange(int a, int b){
        cout << "nodes in range [" << a << ", " << b << "]: ";
        int cnt = countrange(root, a, b);
        cout << "\ncount: " << cnt << endl;
    }
    
    void display() const{
        cout << "tree: ";
        display(root);
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
    tree.insert(10);
    tree.insert(5);
    
    tree.display();
    cout << endl;
    
    tree.countrange(5, 60);
    cout << endl;
    
    tree.countrange(10, 45);
    cout << endl;
      
    return 0;
}
