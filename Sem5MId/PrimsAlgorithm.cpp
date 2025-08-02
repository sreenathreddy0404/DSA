#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii; // {weight, node}

void primsAlgorithm(int V, vector<pii> adj[]) {
    vector<bool> inMST(V, false); // track included vertices
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    int totalCost = 0;

    // Start from node 0
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue;

        inMST[node] = true;
        totalCost += wt;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (!inMST[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Total weight of MST = " << totalCost << endl;
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

        // Since undirected, add both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primsAlgorithm(V, adj);

    return 0;
}
