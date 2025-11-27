#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    bool occupied;
};

class StudentHashTable {
public:
    Student table[15];

    StudentHashTable() {
        for (int i = 0; i < 15; i++) {
            table[i].occupied = false;
        }
    }

    void InsertRecord(int roll, string name) {
        int index = roll % 15;
        int attempt = 0;
        while (table[(index + attempt * attempt) % 15].occupied) {
            attempt = attempt + 1;
        }
        int pos = (index + attempt * attempt) % 15;
        table[pos].roll = roll;
        table[pos].name = name;
        table[pos].occupied = true;
    }

    void SearchRecord(int roll) {
        int index = roll % 15;
        int attempt = 0;
        while (attempt < 15) {
            int pos = (index + attempt * attempt) % 15;
            if (table[pos].occupied && table[pos].roll == roll) {
                cout << table[pos].name << endl;
                return;
            }
            attempt = attempt + 1;
        }
        cout << "Record not found" << endl;
    }

    void Display() {
        for (int i = 0; i < 15; i++) {
            if (table[i].occupied) {
                cout << i << ": " << table[i].roll << " " << table[i].name << endl;
            }
        }
    }
};

int main() {
    StudentHashTable ht;
    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(102, "Sara");
    ht.InsertRecord(103, "Ahmed");
    ht.SearchRecord(102);
    ht.Display();
    return 0;
}

