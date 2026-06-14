#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void DFSUtil(int u, vector<bool>& visited,
                 vector<string>& nama) {
        visited[u] = true;
        cout << nama[u] << " ";

        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited, nama);
            }
        }
    }

    void DFS(int start, vector<string>& nama) {
        vector<bool> visited(V, false);

        cout << "DFS Traversal:\n";
        DFSUtil(start, visited, nama);
        cout << "\n";
    }

    void BFS(int start, vector<string>& nama) {
        vector<bool> visited(V, false);
        vector<int> level(V, -1);

        queue<int> q;
        visited[start] = true;
        level[start] = 0;
        q.push(start);

        cout << "BFS Traversal:\n";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << nama[u]
                 << " (Level " << level[u] << ")\n";

            for (auto [v, w] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    void Dijkstra(int src, vector<string>& nama) {
        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nJarak Terpendek dari "
             << nama[src] << ":\n";

        for (int i = 0; i < V; i++) {
            cout << nama[src]
                 << " -> "
                 << nama[i]
                 << " = "
                 << dist[i]
                 << "\n";
        }
    }
};

int main() {
    vector<string> nama = {
        "Andi",
        "Budi",
        "Citra",
        "Dina",
        "Eko"
    };

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "=== Sistem Pertemanan Media Sosial ===\n\n";

    g.DFS(0, nama);

    cout << "\n";
    g.BFS(0, nama);

    g.Dijkstra(0, nama);

    return 0;
}