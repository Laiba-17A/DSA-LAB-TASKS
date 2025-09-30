#include <iostream>
using namespace std;

bool hasDup(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {5, 3, 8, 2, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (hasDup(arr, size)) {
        cout << "Array has duplicates" << endl;
    } else {
        cout << "Array does not have duplicates." << endl;
    }

    return 0;
}

