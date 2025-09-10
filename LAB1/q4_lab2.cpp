#include <iostream>
using namespace std;

const int SIZE = 5;

//initialize array
bool friends[SIZE][SIZE] = {
    {false, true, false, true, true},
    {true, false, true, false, true},
    {false, true, false, false, false},
    {true, false, false, false, true},
    {true, true, false, true, false}
};

bool CommonFriend(int A, int B) {
    for (int i = 0; i < SIZE; ++i) {
        if (i != A && i != B) {
            if (friends[A][i] && friends[B][i]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    if (hasCommonFriend(0, 4)) {
        cout << " 0 and 4 have a common friend" << endl;
    } else {
        cout << "0 and 4 not have a common friend" << endl;
    }

    if (hasCommonFriend(1, 2)) {
         cout << " 1 and 2 have a common friend" << endl;
    } else {
        cout << "1 and 2 not have a common friend" << endl;
    }

    
    return 0;
}

