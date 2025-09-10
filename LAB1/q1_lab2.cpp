#include <iostream>
using namespace std;

class Mattrix {
    int **matt;
    int r, c;

public:
    Mattrix(int row, int col) : r(row), c(col) {
        matt = new int*[r];
        for (int i = 0; i < r; i++) {
            matt[i] = new int[c]{};
        }
    }

   void resize(int newr, int newc) {
    int **newm = new int*[newr];
    for (int i = 0; i < newr; i++) {
        newm[i] = new int[newc];
        for (int j = 0; j < newc; j++) {
            if (i < r && j < c) newm[i][j] = matt[i][j];
            else {
                cout << "Enter value for new element [" << i << "][" << j << "]: ";
                cin >> newm[i][j];
            }
        }
    }
    for (int i = 0; i < r; i++) delete[] matt[i];
    delete[] matt;
    matt = newm; r = newr; c = newc;
}


    void transpose() {
        int **transm = new int*[c];
        for (int i = 0; i < c; i++) {
            transm[i] = new int[r];
            for (int j = 0; j < r; j++) {
                transm[i][j] = matt[j][i];
            }
        }
        for (int i = 0; i < r; i++) {
        	delete[] matt[i];
		}
        delete[] matt;
        matt = transm; swap(r, c);
    }

    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << matt[i][j] << ' ';
            }
            cout << '\n';
        }
    }
//assumed that if any row or column number is odd then add 2,(index start from 0)  
    void add2odd() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i % 2 == 1) || (j % 2 == 1)) matt[i][j] += 2;
            }
        }
    }

    ~Mattrix() {
        for (int i = 0; i < r; i++) delete[] matt[i];
        delete[] matt;
    }
};

int main() {
    Mattrix d(3, 4);
    d.print();
    cout << "---\n";
    d.resize(4, 3);
    d.print();
    cout << "---\n";
    d.transpose();
    d.print();
    cout << "---\n";
    d.add2odd();
    d.print();
}

