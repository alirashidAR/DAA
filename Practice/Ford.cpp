#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

#define NUM_VERTICES 7

bool bfs(int residualGraph[NUM_VERTICES][NUM_VERTICES], int source, int sink, int parent[]) {
    bool visited[NUM_VERTICES];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < NUM_VERTICES; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int capacityGraph[NUM_VERTICES][NUM_VERTICES], int source, int sink) {
    int u, v;
    int residualGraph[NUM_VERTICES][NUM_VERTICES];
    for (u = 0; u < NUM_VERTICES; u++)
        for (v = 0; v < NUM_VERTICES; v++)
            residualGraph[u][v] = capacityGraph[u][v];
    int parent[NUM_VERTICES];
    int maxFlow = 0;
    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    // s -> 0, a -> 1, b -> 2, c -> 3, d -> 4, e -> 5, t -> 6
    int capacityGraph[NUM_VERTICES][NUM_VERTICES]
        = {{0, 7, 0, 0, 10, 0, 0},
           {0, 0, 5, 0, 1, 3, 0},
           {0, 0, 0, 2, 0, 0, 10},
           {0, 0, 0, 0, 0, 0, 4},
           {0, 0, 0, 7, 0, 2, 0},
           {0, 0, 3, 2, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0}};

    cout << "The maximum possible flow is "
         << fordFulkerson(capacityGraph, 0, 5);

    return 0;
}
