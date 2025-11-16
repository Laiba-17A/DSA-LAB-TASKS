#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct student {
    string name;
    int roll;
    int score;
    
    student(string n = "", int r = 0, int s = 0) {
        name = n;
        roll = r;
        score = s;
    }
};

struct node {
    student data;
    node* left;
    node* right;
    
    node(student val){
        data = val;
        left = right = NULL;
    }
};

class bst {
    node* root;
    
    node* insert(node* nd, student val){
        if(nd == NULL){
            return new node(val);
        }
        if(val.name < nd->data.name){
            nd->left = insert(nd->left, val);
        }
        else if(val.name > nd->data.name){
            nd->right = insert(nd->right, val);
        }
        return nd;
    }
    
    node* delnode(node* nd, string nm){
        if(nd == NULL){
            return nd;
        }
        if(nm < nd->data.name){
            nd->left = delnode(nd->left, nm);
        } 
        else if(nm > nd->data.name){
            nd->right = delnode(nd->right, nm);
        } 
        else {
            if(nd->left == NULL && nd->right == NULL){
                delete nd;
                return NULL;
            } 
            else if(nd->left == NULL){
                node* tmp = nd->right;
                delete nd;
                return tmp;
            } 
            else if (nd->right == NULL){
                node* tmp = nd->left;
                delete nd;
                return tmp;
            } 
            else {
                node* tmp = findmin(nd->right);
                nd->data = tmp->data;
                nd->right = delnode(nd->right, tmp->data.name);
            }
        }
        return nd;
    }
    
    node* findmin(node* nd){
        while (nd && nd->left != NULL)
            nd = nd->left;
        return nd;
    }
    
    bool search(node* nd, string nm) const{
        if(nd == NULL){
            return false;
        }
        if(nd->data.name == nm){
            return true;
        }
        else if(nm < nd->data.name){
            return search(nd->left, nm);
        }
        else{
            return search(nd->right, nm);
        }
    }
    
    void inorder(node* nd) const{
        if(nd != NULL){
            inorder(nd->left);
            cout << "name: " << nd->data.name << ", roll: " << nd->data.roll 
                 << ", score: " << nd->data.score << endl;
            inorder(nd->right);
        }
    }
    
    void dellow(node*& nd){
        if(nd == NULL) return;
        
        dellow(nd->left);
        dellow(nd->right);
        
        if(nd->data.score < 10){
            cout << "deleting " << nd->data.name << " (score: " << nd->data.score << ")" << endl;
            root = delnode(root, nd->data.name);
        }
    }
    
    void findmax(node* nd, student& maxs) const{
        if(nd == NULL) return;
        
        if(nd->data.score > maxs.score){
            maxs = nd->data;
        }
        
        findmax(nd->left, maxs);
        findmax(nd->right, maxs);
    }
    
public:
    bst(){
        root = NULL;
    }
    
    void insert(student val){
        root = insert(root, val);
        cout << "inserted: " << val.name << endl;
    }
    
    void search(string nm) const{
        if(search(root, nm)){
            cout << "student " << nm << " found" << endl;
        }
        else{
            cout << "student " << nm << " not " << endl;
        }
    }
    
    void display() const{
        cout << "\nall students" << endl;
        if(root == NULL){
            cout << "no students " << endl;
        } else {
            inorder(root);
        }
    }
    
    void dellow(){
        cout << "\ndeleting students with score < 10" << endl;
        dellow(root);
    }
    
    void getmax() const{
        if(root == NULL){
            cout << "no students" << endl;
            return;
        }
        
        student maxs = root->data;
        findmax(root, maxs);
        
        cout << "\nstudent with max score" << endl;
        cout << "name: " << maxs.name << ", roll: " << maxs.roll 
             << ", score: " << maxs.score << endl;
    }
};

int main(){
    srand(time(0));
    
    student stuarr[10] = {
        student("laiba", 101, 85),
        student("amna", 102, 5),
        student("fatima", 103, 92),
        student("arshia", 104, 78),
        student("zahra", 105, 8),
        student("sara", 106, 95),
        student("iqra", 107, 88),
        student("marwa", 108, 3),
        student("mariam", 109, 90),
        student("aqsa", 110, 82)
    };
    
    bst tree;
    
    cout << "student bst management system" << endl;
    cout << "\ninserting randomly 7" << endl;
    
    bool used[10] = {false};
    int cnt = 0;
    
    while(cnt < 7){
        int idx = rand() % 10;
        if(!used[idx]){
            tree.insert(stuarr[idx]);
            used[idx] = true;
            cnt++;
        }
    }
    
    tree.display();
    
    cout << "\nsearching students" << endl;
    tree.search("laiba");
    tree.search("amna");
    tree.search("fatima");
    
    tree.getmax();
    
    tree.dellow();
    
    cout << "\nafter deletion" << endl;
    tree.display();
    
    tree.getmax();
    
    return 0;
}
