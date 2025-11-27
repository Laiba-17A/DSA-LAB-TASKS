#include <iostream>
using namespace std;

bool isHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2 * i + 1]) {
            return false;
        }
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int n = 5;

    if (isHeap(arr, n)) {
        cout << "Array is a heap" << endl;
    } else {
        cout << "Array is not a heap" << endl;
    }

    sortArray(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

