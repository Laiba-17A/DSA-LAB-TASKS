#include <iostream>
using namespace std;

int main() {
    int stdC = 5, sub = 4;
    int** m = new int*[stdC];
    for (int i = 0; i < stdC; i++)
        m[i] = new int[sub];

    cout << "Enter marks for " << stdC << " students in " << sub << " subjects each:\n";
    for (int i = 0; i < stdC; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < sub; j++)
            cin >> m[i][j];
    }

    int top = 0, temp = 0;
    for (int i = 0; i < stdC; i++) {
        int total = 0;
        for (int j = 0; j < sub; j++) total += m[i][j];
        cout << "Total marks of student " << i + 1 << ": " << total << endl;
        if (total > top) {
            top = total;
            temp = i;
        }
    }

    for (int j = 0; j < sub; j++) {
        int sum = 0;
        for (int i = 0; i < stdC; i++) sum += m[i][j];
        cout << "Average marks of subject " << j + 1 << ": " << (double)sum / stdC << endl;
    }

    cout << "Topper student: " << temp + 1 << " with total marks " << top << endl;

    for (int i = 0; i < stdC; i++)
        delete[] m[i];
    delete[] m;

    return 0;
}

