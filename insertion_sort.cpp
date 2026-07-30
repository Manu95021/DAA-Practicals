#include <iostream>
using namespace std;

int main() {
    int arr[] = {45, 12, 67, 23, 8};
    int n = 5;
    int i, j, target;

    for (i = 1; i < n; i++) {
        target = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > target) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = target;
    }

    cout << "Sorted array: ";

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}