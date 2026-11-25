
#include <iostream>
using namespace std;

int n, cost[10][10];
int visited[10] = {0};
int minCost = 99999;

void tsp(int city, int count, int totalCost) {
    if (count == n && cost[city][0] != 0) {
        int finalCost = totalCost + cost[city][0];

        if (finalCost < minCost)
            minCost = finalCost;

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = 1;

            tsp(i, count + 1, totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    if (minCost == 99999)
        cout << "Tour cannot be completed";
    else
        cout << "Minimum tour cost = " << minCost;

    return 0;
}




Time and Space Complexity
- Time Complexity: (O(n!))
- Space Complexity: (O(n))
