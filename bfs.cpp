
#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10] = {0}, n;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int e, u, v, start;

    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
