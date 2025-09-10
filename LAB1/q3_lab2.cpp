#include <iostream>
using namespace std;

int main() {
    int dept;
    cout << "Enter number of departments: ";
    cin >> dept;

    int* students = new int[dept];
    cout << "Enter number of students in each department:\n";
    for (int i = 0; i < dept; i++) {
        cin >> students[i];
    }

    int** totalMarks = new int*[dept];
    for (int i = 0; i < dept; i++) {
        totalMarks[i] = new int[students[i]];
    }

    cout << "Enter total marks for 5 subjects:\n";
    for (int i = 0; i < dept; i++) {
        for (int j = 0; j < students[i]; j++) {
            cout << "Department " << i + 1 << ", Student " << j + 1 << ": ";
            cin >> totalMarks[i][j];
        }
    }

    for (int i = 0; i < dept; i++) {
        int high = 0, low = 1e9, sum = 0;

        for (int j = 0; j < students[i]; j++) {
            int total = totalMarks[i][j];
            if (total > high) high = total;
            if (total < low) low = total;
            sum += total;
        }

        double avg = (students[i] > 0) ? (double)sum / students[i] : 0;
        cout << "Department " << i + 1 << ": High=" << high << " Low=" << low << " Avg=" << avg << endl;
    }

    for (int i = 0; i < dept; i++) {
        delete[] totalMarks[i];
    }
    delete[] totalMarks;
    delete[] students;

    return 0;
}

