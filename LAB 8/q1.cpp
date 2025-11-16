#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST {
    Node* root;
   
    Node* insert(Node* node, int val){
        if(node == NULL){
            return new Node(val);
        }
        if(val < node->data){
            node->left = insert(node->left, val);
        }
        else if(val > node->data){
            node->right = insert(node->right, val);
        }
        return node;
    }
   
    Node* delete_node(Node* node, int val){
        if(node == NULL){
            return node;
        }
        if(val < node->data){
            node->left = delete_node(node->left, val);
        } 
        else if(val > node->data){
            node->right = delete_node(node->right, val);
        } 
        else {
            
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            } 
            else if(node->left == NULL){
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL){
                Node* temp = node->left;
                delete node;
                return temp;
            } 
            else {
               
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
        return node;
    }
 
    Node* find_min(Node* node){
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }
  
    bool search(Node* node, int val) const{
        if(node == NULL){
            return false;
        }
        if(node->data == val){
            return true;
        }
        else if(val < node->data){
            return search(node->left, val);
        }
        else{
            return search(node->right, val);
        }
    }
    
    void inorder(Node* node) const{
        if(node != NULL){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) const{
        if(node != NULL){
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
   
    void postorder(Node* node) const{
        if(node != NULL){
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    
public:
    BST(){
        root = NULL;
    }
    

    void insert(int val){
        root = insert(root, val);
        cout << "Inserted: " << val << endl;
    }
    
  
    void remove(int val){
        if(search(val)){
            root = delete_node(root, val);
            cout << "Deleted: " << val << endl;
        }
        else{
            cout << "Value " << val << " not found " << endl;
        }
    }
   
    bool search(int val) const{
        if(search(root, val)){
            cout << "Value " << val << " found " << endl;
            return true;
        }
        else{
            cout << "Value " << val << " not found" << endl;
            return false;
        }
    }

    void displayInorder(){
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
    
    void displayPreorder(){
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }
    
    void displayPostorder(){
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
   
    void displayAll(){
        cout << "\nAll Traversals" << endl;
        displayInorder();
        displayPreorder();
        displayPostorder();
    }
};

int main(){
    BST tree;
    
    cout << "\n Insertion " << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "\n Display Tree" <<endl<<endl;
    tree.displayAll();
    
    cout << "\n Searching " <<endl<<endl;
    tree.search(40);
    tree.search(100);
    tree.search(20);
    
    cout << "\n Deletion " << endl<<endl;
    tree.remove(20);  
    tree.displayInorder();
    
    tree.remove(30);  
    tree.displayInorder();
    
    tree.remove(100); 
    
    cout << "\n Final Tree" << endl<<;
    tree.displayAll();
    
    return 0;
}
