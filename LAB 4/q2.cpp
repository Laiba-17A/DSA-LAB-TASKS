#include <iostream>
using namespace std;

int main() {
    const int SIZE = 9;
    int arr[SIZE] = { 20, 12, 15, 2, 10, 1, 13, 9, 5 };

    // Insertion Sort
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
	int max = arr[SIZE - 1];
    // inserting max element in middle
    int mid = SIZE / 2;
    for (int i = SIZE - 1; i > mid; i--) {
        arr[i] = arr[i - 1];
    }

    arr[mid] = max;
    cout << "Final array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

