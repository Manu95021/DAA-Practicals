
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[10];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main() {
    int n, e, cost = 0;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge edges[20];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    int count = 0;

    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;

            cost += edges[i].w;
            parent[a] = b;
            count++;
        }
    }

    if (count != n - 1)
        cout << "MST cannot be constructed";
    else
        cout << "Minimum Cost = " << cost;

    return 0;
}




Time and Space Complexity
- Time Complexity: (O(Elog E))
- Space Complexity: (O(V+E)
