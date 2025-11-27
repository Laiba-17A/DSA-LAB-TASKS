#include <iostream>
using namespace std;

class MinMaxHeap {
public:
    int arr[100];
    int size;

    MinMaxHeap() {
        size = 0;
    }

    void insert(int val) {
        arr[size] = val;
        size = size + 1;
        heapifyUp(size - 1);
    }

    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)] > arr[i]) {
            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l] < arr[smallest]) {
            smallest = l;
        }

        if (r < size && arr[r] < arr[smallest]) {
            smallest = r;
        }

        if (smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapifyDown(smallest);
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    void update_key(int i, int new_val) {
        arr[i] = new_val;
        heapifyUp(i);
        heapifyDown(i);
    }

    void delete_key(int i) {
        arr[i] = arr[size - 1];
        size = size - 1;
        heapifyUp(i);
        heapifyDown(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinMaxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Heap: ";
    h.printHeap();

    h.update_key(2, 1);
    cout << "After update: ";
    h.printHeap();

    h.delete_key(1);
    cout << "After delete: ";
    h.printHeap();

    return 0;
}

