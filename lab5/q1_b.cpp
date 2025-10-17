#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int data) {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
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
            temp->prev = last;
            last = temp;
        }
    }

    void insertAtPos(int data, int pos) {
        Node* temp = new Node(data);
        Node* current = first;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        temp->prev = current->prev;
        current->prev->next = temp;
        temp->next = current;
        current->prev = temp;
    }

    void delAtPos(int pos) {
        Node* current = first;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void display() {
        Node* current = first;
        while (current != NULL) {
            cout << current->value << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList list;
    list.addAtEnd(1);
    list.addAtEnd(2);
    list.addAtEnd(3);
    list.addAtEnd(4);
    list.delAtPos(2);
    list.display();
    list.insertAtPos(5, 3);
   
    list.display();

    return 0;
}

