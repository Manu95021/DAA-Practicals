#include <iostream>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    int wt[n], val[n];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << dp[n][W];

    return 0;
}










Time Complexity

O(n × W)
Where:
n = number of items
W = maximum knapsack capacity
Space Complexity
O(n × W)



Conclusion:
The 0/1 Knapsack problem is solved using Dynamic Programming by selecting items to maximize the total value without exceeding the given capacity.
Each item can be selected only once.

