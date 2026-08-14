#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

void maxHeapify(vector<int> &arr, int n, int i)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(vector<int> &arr, int n, int i)
{
    while (true)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(arr[i], arr[smallest]);
        i = smallest;
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    reverse(arr.begin(), arr.end());
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
    }

    vector<int> maxHeapArray = original;
    vector<int> minHeapArray = original;

    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto endMax = high_resolution_clock::now();

    auto startMin = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto endMin = high_resolution_clock::now();

    long long nanoMax =
        duration_cast<nanoseconds>(endMax - startMax).count();

    long long microMax =
        duration_cast<microseconds>(endMax - startMax).count();

    long long nanoMin =
        duration_cast<nanoseconds>(endMin - startMin).count();

    long long microMin =
        duration_cast<microseconds>(endMin - startMin).count();

    cout << "\n========== MAX HEAP SORT ==========\n";

    cout << "Sorted array: ";
    for (int x : maxHeapArray)
        cout << x << " ";

    cout << "\nNanoseconds  : " << nanoMax << " ns";
    cout << "\nMicroseconds : " << microMax << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";

    cout << "Sorted array: ";
    for (int x : minHeapArray)
        cout << x << " ";

    cout << "\nNanoseconds  : " << nanoMin << " ns";
    cout << "\nMicroseconds : " << microMin << " us\n";

    return 0;
}
