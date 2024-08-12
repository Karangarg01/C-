#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

void solve(unordered_map<int, list<int>> &adj, vector<bool> &visited, int node, vector<int> &parent) {
    visited[node] = true;
    parent[node] = -1;

    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create an adjacency list from the edge list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize visited and parent arrays
    vector<bool> visited(n, false);
    vector<int> parent(n);

    // Perform BFS to find the shortest path
    solve(adj, visited, s, parent);

    // Reconstruct the shortest path from s to t
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);

    while (currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
