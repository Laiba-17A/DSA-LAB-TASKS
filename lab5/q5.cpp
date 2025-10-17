#include <iostream>
using namespace std;

int arraySum(void** arr, int* sizes, int dim) {
    int sum = 0;
    if (dim == 1) {
        int* intArr = (int*)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += intArr[i];
        }
    } else {
        for (int i = 0; i < sizes[0]; i++) {
            sum += arraySum((void**)arr[i], sizes + 1, dim - 1);
        }
    }
    return sum;
}

int main() {
    int* row1 = new int[3]{2, 4, 6};
    int* row2 = new int[3]{1, 3, 5};
    int* row3 = new int[3]{7, 8, 9};

    void** arr2D = new void*[3];
    arr2D[0] = row1;
    arr2D[1] = row2;
    arr2D[2] = row3;

    int sizes[] = {3, 3};
    int total = arraySum(arr2D, sizes, 2);

    cout << "Total sum of elements: " << total << endl;

    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] arr2D;
}

