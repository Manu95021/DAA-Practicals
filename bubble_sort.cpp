#include <iostream>
using namespace std;

int main() {
    int arr[] = {56, 23, 71, 14, 39};
    int n = 5;
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}