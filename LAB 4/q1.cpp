#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Enter 10 elements:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    cout << "\nThe 4 minimum elements are: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

