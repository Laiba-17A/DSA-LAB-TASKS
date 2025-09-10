#include <iostream>
#include <string>
using namespace std;

int main() {
    int dept = 4;
    int crs[4] = {3, 4, 2, 1};

    double** gpa = new double*[dept];
    for (int i = 0; i < dept; i++) {
        gpa[i] = new double[crs[i]];
    }

    string d[4] = {"SE", "AI", "CS", "DS"};

    for (int i = 0; i < dept; i++) {
        cout << "Enter GPAs for " << d[i] << " (" << crs[i] << " courses):"<<endl;
        for (int j = 0; j < crs[i]; j++) {
            cout << "  Course " << j + 1 << ": ";
            cin >> gpa[i][j];
        }
    }

    cout << "GPA "<<endl;
    for (int i = 0; i < dept; i++) {
        cout << d[i] << ": ";
        for (int j = 0; j < crs[i]; j++) {
            cout << gpa[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < dept; i++) {
        delete[] gpa[i];
    }
    delete[] gpa;

    return 0;
}

