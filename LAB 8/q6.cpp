#include<iostream>
using namespace std;

struct product {
    int id;
    int qty;
    
    product(int i = 0, int q = 0) {
        id = i;
        qty = q;
    }
};

struct node {
    product data;
    node* left;
    node* right;
    
    node(product val){
        data = val;
        left = right = NULL;
    }
};

class invbst {
    node* root;
    
    node* insert(node* nd, product val){
        if(nd == NULL){
            return new node(val);
        }
        if(val.id < nd->data.id){
            nd->left = insert(nd->left, val);
        }
        else if(val.id > nd->data.id){
            nd->right = insert(nd->right, val);
        }
        return nd;
    }
    
    node* search(node* nd, int id){
        if(nd == NULL){
            return NULL;
        }
        if(nd->data.id == id){
            return nd;
        }
        else if(id < nd->data.id){
            return search(nd->left, id);
        }
        else{
            return search(nd->right, id);
        }
    }
    
    void inorder(node* nd) const{
        if(nd != NULL){
            inorder(nd->left);
            cout << "id: " << nd->data.id << ", qty: " << nd->data.qty << endl;
            inorder(nd->right);
        }
    }
    
    void findmax(node* nd, product& maxp) const{
        if(nd == NULL) return;
        
        if(nd->data.qty > maxp.qty){
            maxp = nd->data;
        }
        
        findmax(nd->left, maxp);
        findmax(nd->right, maxp);
    }
    
public:
    invbst(){
        root = NULL;
    }
    
    void insert(int id, int qty){
        product prod(id, qty);
        root = insert(root, prod);
        cout << "inserted product id " << id << " with qty " << qty << endl;
    }
    
    void update(int id, int newqty){
        node* nd = search(root, id);
        if(nd != NULL){
            cout << "updating product id " << id << " from qty " << nd->data.qty 
                 << " to " << newqty << endl;
            nd->data.qty = newqty;
        }
        else{
            cout << "product id " << id << " not found" << endl;
        }
    }
    
    void searchprod(int id){
        node* nd = search(root, id);
        if(nd != NULL){
            cout << "product found - id: " << nd->data.id 
                 << ", qty: " << nd->data.qty << endl;
        }
        else{
            cout << "product id " << id << " not found" << endl;
        }
    }
    
    void gethighest() const{
        if(root == NULL){
            cout << "no products in inventory" << endl;
            return;
        }
        
        product maxp = root->data;
        findmax(root, maxp);
        
        cout << "\nproduct with highest quantity" << endl;
        cout << "id: " << maxp.id << ", qty: " << maxp.qty << endl;
    }
    
    void display() const{
        cout << "\ninventory list" << endl;
        if(root == NULL){
            cout << "no products in inventory" << endl;
        } else {
            inorder(root);
        }
    }
};

int main(){
    invbst inv;
    
    cout << "online retailer inventory management system" << endl;
    cout << "\ninserting products" << endl;
    
    inv.insert(105, 50);
    inv.insert(102, 120);
    inv.insert(108, 30);
    inv.insert(101, 80);
    inv.insert(104, 200);
    inv.insert(107, 45);
    inv.insert(110, 150);
    
    inv.display();
    
    cout << "\nsearching for products" << endl;
    inv.searchprod(104);
    inv.searchprod(999);
    
    cout << "\nupdating product quantities" << endl;
    inv.update(102, 180);
    inv.update(108, 5);
    inv.update(999, 100);
    
    inv.display();
    
    inv.gethighest();
    
    cout << "\nadding more stock" << endl;
    inv.update(110, 250);
    
    inv.display();
    
    inv.gethighest();
    
    return 0;
}
