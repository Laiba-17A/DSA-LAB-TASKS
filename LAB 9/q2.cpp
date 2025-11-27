#include <iostream>
using namespace std;

struct Node {
    int v;
    Node *l, *r;
    int h;
    Node(int x) { v = x; l = r = NULL; h = 1; }
};

int ht(Node* n) { return n ? n->h : 0; }
int bf(Node* n) { return ht(n->l) - ht(n->r); }
int up(Node* n) { return 1 + max(ht(n->l), ht(n->r)); }

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

Node* ins(Node* n, int val) {
    if (!n) return new Node(val);
    if (val < n->v) n->l = ins(n->l, val);
    else if (val > n->v) n->r = ins(n->r, val);
    else return n;

    n->h = up(n);
    int b = bf(n);

    if (b > 1 && val < n->l->v) return rotR(n);
    if (b < -1 && val > n->r->v) return rotL(n);
    if (b > 1 && val > n->l->v) { n->l = rotL(n->l); return rotR(n); }
    if (b < -1 && val < n->r->v) { n->r = rotR(n->r); return rotL(n); }

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

int main() {
    Node* root = NULL;

    int a[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
        root = ins(root, a[i]);

    root = ins(root, 15);

    cout << "\nFinal AVL Tree:\n";
    print(root);

    cout << "\n\nHeight = " << ht(root) << endl;
}

