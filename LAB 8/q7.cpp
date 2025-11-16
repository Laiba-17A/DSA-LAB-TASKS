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
    
    int countnd(node* nd){
        if(nd == NULL){
            return 0;
        }
        return 1 + countnd(nd->left) + countnd(nd->right);
    }
    
    void inorder(node* nd, int arr[], int& idx){
        if(nd != NULL){
            inorder(nd->left, arr, idx);
            arr[idx++] = nd->data;
            inorder(nd->right, arr, idx);
        }
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
    
    void findmed(){
        if(root == NULL){
            cout << "tree is empty" << endl;
            return;
        }
        
        int n = countnd(root);
        int* arr = new int[n];
        int idx = 0;
        
        inorder(root, arr, idx);
        
        cout << "total nodes: " << n << endl;
        cout << "sorted values: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        
        float med;
        
        if(n % 2 == 0){
            int mid1 = arr[n/2 - 1];
            int mid2 = arr[n/2];
            med = (mid1 + mid2) / 2.0;
            cout << "even nodes: median is "<<med<< endl;
        }
        else{
            med = arr[n/2];
            cout << "odd nodes: median at position " << (n/2 + 1) << endl;
            cout << "median: " << med << endl;
        }
                
        delete[] arr;
    }
    
    void display() const{
        cout << "tree: ";
        display(root);
        cout << endl;
    }
};

int main(){
    bst tree1;
    
    cout << "tree 1 with odd number of nodes" << endl;
    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);
    tree1.insert(60);
    tree1.insert(80);
    
    tree1.display();
    tree1.findmed();
    
    cout << "\ntree 2 with even number of nodes" << endl;
    bst tree2;
    
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(20);
    tree2.insert(40);
    tree2.insert(60);
    
    tree2.display();
    tree2.findmed();
    
    
    
    return 0;
}
