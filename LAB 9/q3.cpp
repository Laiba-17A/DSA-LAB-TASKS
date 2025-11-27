#include <iostream>
using namespace std;

struct Node {
    int v, h;
    Node *l, *r;
    Node(int x) { v = x; l = r = NULL; h = 1; }
};

int ht(Node* n) { return n ? n->h : 0; }
int up(Node* n) { return 1 + (ht(n->l) > ht(n->r) ? ht(n->l) : ht(n->r)); }
int bf(Node* n) { return ht(n->l) - ht(n->r); }

Node* rotL(Node* x) {
    Node* y = x->r;
    Node* t = y->l;
    y->l = x;
    x->r = t;
    x->h = up(x);
    y->h = up(y);
    return y;
}

Node* rotR(Node* y) {
    Node* x = y->l;
    Node* t = x->r;
    x->r = y;
    y->l = t;
    y->h = up(y);
    x->h = up(x);
    return x;
}

Node* ins(Node* n, int v) {
    if (!n) return new Node(v);
    if (v < n->v) n->l = ins(n->l, v);
    else if (v > n->v) n->r = ins(n->r, v);
    else return n;

    n->h = up(n);
    int b = bf(n);

    if (b > 1 && v < n->l->v) return rotR(n);
    if (b < -1 && v > n->r->v) return rotL(n);
    if (b > 1 && v > n->l->v) { n->l = rotL(n->l); return rotR(n); }
    if (b < -1 && v < n->r->v) { n->r = rotR(n->r); return rotL(n); }

    return n;
}

void print(Node* n, int s = 0) {
    if (!n) return;
    s += 4;
    print(n->r, s);
    cout << endl;
    for (int i = 4; i < s; i++) cout << " ";
    cout << n->v;
    print(n->l, s);
}

class AVLTree {
public:
    Node* root;
    AVLTree() { root = NULL; }
    void insert(int x) { root = ins(root, x); }
    void leftRotateRoot() { root = rotL(root); }
    void display() { print(root); }
};

int main() {
    AVLTree t;
    int a[7] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) t.insert(a[i]);

    t.insert(55);

    t.leftRotateRoot();

    cout << "\nFinal Tree:\n";
    t.display();
}

