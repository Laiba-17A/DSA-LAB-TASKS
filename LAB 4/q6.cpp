#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[7] = {1014, 1010, 1023, 1232, 1005, 1062};
    int size = 6;
    int rollNo;

    cout << "Enter your 4-digit roll number: ";
    cin >> rollNo;

    int last2 = rollNo % 100;
    int target = 1000 + last2;

    bubbleSort(arr, size);
    int index = binarySearch(arr, size, target);

    if (index == -1) {
        int newSize = size + 1;
        int newArr[7];
        bool inserted = false;
        int j = 0;

        for (int i = 0; i < size; i++) {
            if (!inserted && target < arr[i]) {
                newArr[j++] = target;
                inserted = true;
            }
            newArr[j++] = arr[i];
        }

        if (!inserted) {
            newArr[j++] = target;
        }

        int newIndex = binarySearch(newArr, newSize, target);
        cout << "Sorted array after inserting " << target << ": ";
        for (int i = 0; i < newSize; i++) {
            cout << newArr[i] << " ";
        }
        cout << "\nValue " << target << " found at index: " << newIndex << endl;
    } else {
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nValue " << target << " found at index: " << index << endl;
    }

    return 0;
}

