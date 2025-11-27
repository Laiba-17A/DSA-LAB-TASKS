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

int kthSmall(Node* n, int& k) {
    if (!n) return -1;
    int x = kthSmall(n->l, k);
    if (x != -1) return x;
    if (--k == 0) return n->v;
    return kthSmall(n->r, k);
}

int kthLarge(Node* n, int& k) {
    if (!n) return -1;
    int x = kthLarge(n->r, k);
    if (x != -1) return x;
    if (--k == 0) return n->v;
    return kthLarge(n->l, k);
}

int main() {
    Node* root = NULL;
    int a[5] = {10, 5, 15, 3, 7};
    for (int i = 0; i < 5; i++) root = ins(root, a[i]);

    int k1, k2;
    int valToInsert = 12;
    root = ins(root, valToInsert);

    cout << "Left Height: " << ht(root->l) << endl;
    cout << "Right Height: " << ht(root->r) << endl;

    k1 = 3; 
    cout << "3rd Smallest: " << kthSmall(root, k1) << endl;

    k2 = 2;
    cout << "2nd Largest: " << kthLarge(root, k2) << endl;

    return 0;
}

