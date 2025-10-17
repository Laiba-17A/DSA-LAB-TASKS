#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = NULL;
    }
};

class SinglyList {
public:
    Node* first = NULL;
    Node* last = NULL;

    void addAtEnd(int data) {
        Node* temp = new Node(data);
        if (first == NULL) {
            first = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
};

int countNodes(Node* start, int total) {
    if (start == NULL) {
        return total;
    }
    return countNodes(start->next, total + 1);
}

int main() {
    SinglyList list;
    list.addAtEnd(2);
    list.addAtEnd(5);
    list.addAtEnd(6);
    list.addAtEnd(8);

    int length = countNodes(list.first, 0);
    cout << "Length: " << length;

    return 0;
}

