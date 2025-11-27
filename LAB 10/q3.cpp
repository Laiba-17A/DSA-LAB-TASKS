#include <iostream>
using namespace std;

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

int kthLargest(int arr[], int n, int k) {
    sortArray(arr, n);
    return arr[n - k];
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = 7;
    int k = 3;

    cout << "Kth largest: " << kthLargest(arr, n, k) << endl;

    int arr2[] = {12, 3, 5, 7, 19};
    int n2 = 5;
    int k2 = 2;

    cout << "Kth largest: " << kthLargest(arr2, n2, k2) << endl;

    return 0;
}

