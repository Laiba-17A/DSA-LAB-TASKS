#include <iostream>
using namespace std;

void displayBoard(char board[][4], int size) {
    int totalFlags = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j];
            if (board[i][j] == 'F') {
                totalFlags++;
            }
        }
        cout << endl;
    }
    cout << "Total flags = " << totalFlags << endl;
}

bool canPlace(char board[][4], int row, int col, int size) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == 'F' || board[i][col] == 'F')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'F')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < size; i--, j++) {
        if (board[i][j] == 'F')
            return false;
    }

    return true;
}

void placeFlags(char board[][4], int row, int size) {
    if (row == size) {
        displayBoard(board, size);
        cout << endl;
        return;
    }

    for (int col = 0; col < size; col++) {
        if (canPlace(board, row, col, size)) {
            board[row][col] = 'F';
            placeFlags(board, row + 1, size);
            board[row][col] = '.';
        }
    }
}

int main() {
    char board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = '.';
        }
    }
    placeFlags(board, 0, 4);
    return 0;
}

