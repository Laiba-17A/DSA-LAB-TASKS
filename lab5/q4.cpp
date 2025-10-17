#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class linked_list {
public:
    node* head = NULL;
    node* tail = NULL;

    void append(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

bool search(node* head, int val) {
    if (head == NULL)
        return false;
    if (head->data == val)
        return true;
    return search(head->next, val);
}

int main() {
    linked_list l1;
    l1.append(2);
    l1.append(6);
    l1.append(4);
    l1.append(8);

    if (search(l1.head, 6))
        cout << "Value found";
    else
        cout << "Value not found";
}

