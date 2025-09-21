#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* name;
    char* date;
    float score;

public:
    Exam(const char* n, const char* d, float s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        date = new char[strlen(d) + 1];
        strcpy(date, d);

        score = s;
    }

    ~Exam() {
        delete[] name;
        delete[] date;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam e1("Laiba", "2025-09-03", 90);

    cout << "Original e1 details:" << endl;
    e1.display();

    Exam e2 = e1;  // Shallow copy

    cout << "\nCopied e2 details:" << endl;
    e2.display();

    return 0;
}

