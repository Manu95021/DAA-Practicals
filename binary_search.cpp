#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 24, 36, 48, 60};
    int n = 5;
    int target = 48;
    int low = 0, high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index " << mid;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return 0;
}