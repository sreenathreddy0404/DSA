#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

// Dijkstra's Algorithm
void dijkstra(int V, vector<pii> adj[], int src) {
    vector<int> dist(V, 1e9); // distance array
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (dist[v] > d + wt) {
                dist[v] = d + wt;
                pq.push({dist[v], v});
            }
        }
    }

    // Print result
    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " → Distance = " << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pii> adj[V]; // adjacency list

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Since undirected, add both ways
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
