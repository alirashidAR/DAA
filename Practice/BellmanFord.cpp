#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct Edge {
 int source, destination, weight;
};
void BellmanFord(vector<Edge> &edges, int numVertices, int source) {
 vector<int> distance(numVertices, numeric_limits<int>::max());
 distance[source] = 0;
 for (int i = 0; i < numVertices - 1; ++i) {
 for (const auto &edge : edges) {
 if (distance[edge.source] != numeric_limits<int>::max() &&
 distance[edge.source] + edge.weight < distance[edge.destination]) {
 distance[edge.destination] = distance[edge.source] + edge.weight;
 }
 }
 }
 // Check for negative cycles
 for (const auto &edge : edges) {
 if (distance[edge.source] != numeric_limits<int>::max() &&
 distance[edge.source] + edge.weight < distance[edge.destination]) {
 cout << "Graph contains negative cycle, cannot find shortest paths" << endl;
 return;
 }
 }
 // Print shortest distances
 cout << "Shortest distances from source vertex " << source << ":" << endl;
 for (int i = 0; i < numVertices; ++i) {
 cout << "Vertex " << i << ": ";
 if (distance[i] == numeric_limits<int>::max()) {
 cout << "INF" << endl;
 } else {
 cout << distance[i] << endl;
 }
 }
}

int main() {
 int numVertices = 5;
 // s -> 0 t -> 1 x -> 2 z -> 3 y -> 4
 vector<Edge> edges = {{0, 1, 6}, {0, 4, 7}, {1, 2, 5}, {1, 4, 8}, {1, 3, -4},
 {2, 1, -2}, {3, 2, 7}, {3, 0, 2}, {4, 2,-3}, {4, 3, 9}};
 int source = 0;
 BellmanFord(edges, numVertices, source);
 return 0;
}