#include <iostream>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
};

class Dictionary {
public:
    Node* table[100];

    Dictionary() {
        for (int i = 0; i < 100; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum = sum + (int)s[i];
        }
        return sum % 100;
    }

    void Add_Record(string key, string value) {
        int index = hashFunction(key);
        Node* n = new Node();
        n->key = key;
        n->value = value;
        n->next = table[index];
        table[index] = n;
    }

    void Word_Search(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) {
                cout << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Not found" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            Node* temp = table[i];
            if (temp != NULL) {
                cout << "index " << i << ": ";
                while (temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Word_Search("AB");
    d.Print_Dictionary();
    return 0;
}

