#include <iostream>
using namespace std;

int main() {
    int arr[] = {25, 14, 63, 8, 41};
    int n = 5;
    int target = 63;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index " << i;
            return 0;
        }
    }

    cout << "Element not found";

    return 0;
}