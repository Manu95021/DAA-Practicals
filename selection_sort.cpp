#include <iostream>
using namespace std;

int main() {
    int arr[] = {8, 3, 6, 1, 5};
    int n = 5;
    int i, j, target, temp;

    for (i = 0; i < n - 1; i++) {
        target = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[target]) {
                target = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[target];
        arr[target] = temp;
    }

    cout << "Sorted array: ";

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}