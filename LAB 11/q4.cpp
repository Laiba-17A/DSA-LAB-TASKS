#include <iostream>
using namespace std;

struct Pair {
    int a;
    int b;
};

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    Pair sumMap[100];
    int sumArr[100];
    int count = 0;

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = arr[i] + arr[j];
            for (int k = 0; k < count; k++) {
                if (sumArr[k] == s) {
                    cout << "(" << sumMap[k].a << ", " << sumMap[k].b << ") and (" << arr[i] << ", " << arr[j] << ")" << endl;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
            sumArr[count] = s;
            sumMap[count].a = arr[i];
            sumMap[count].b = arr[j];
            count = count + 1;
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "No pairs found" << endl;
    }

    return 0;
}

