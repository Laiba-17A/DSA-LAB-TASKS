#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows;
    cout << "Enter no of rows: ";
    cin >> rows;

    int* temp = new int[rows]; //temp=no.of columns in each row

    cout << "Enter no of seat for each row:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        cin >> temp[i];
    }
    string** seat = new string*[rows];
    for (int i = 0; i < rows; i++) {
        seat[i] = new string[temp[i]];
    }

    cout << "\nEnter attendee names for each seat:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ":\n";
        for (int j = 0; j < temp[i]; j++) {
            cout << "  Seat " << j + 1 << ": ";
            cin >> seat[i][j];
        }
    }

    cout << "\nSeating Chart:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < temp[i]; j++) {
            cout << seat[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] seat[i];
    }
    delete[] seat;
    delete[] temp;

    return 0;
}

