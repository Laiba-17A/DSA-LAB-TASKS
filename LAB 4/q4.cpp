#include <iostream>
using namespace std;

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool hasDup(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {5, 3, 8, 2, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (hasDup(arr, size)) {
        cout << "Array has duplicates." << endl;
    } else {
        cout << "Array does not have duplicates." << endl;
    }

    return 0;
}
