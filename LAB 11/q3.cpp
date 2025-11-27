#include <iostream>
#include <list>
using namespace std;

class Hash {
public:
    int BUCKET;
    list<int>* table;

    Hash(int b) {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }

    int hashFunction(int x) {
        return x % BUCKET;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i << ": ";
            for (int x : table[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h(7);
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.display();
    h.deleteKey(15);
    h.display();
    cout << h.search(20) << endl;
    return 0;
}

