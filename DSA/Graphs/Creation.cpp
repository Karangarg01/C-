vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    // Initialize the adjacency list with n empty vectors
    vector<vector<int>> adj(n);

    // Fill the adjacency list with edges
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Include each node in its own list
    vector<vector<int>> result(n);
    for(int i = 0; i < n; i++) {
        result[i].push_back(i);
        for(int j = 0; j < adj[i].size(); j++) {
            result[i].push_back(adj[i][j]);
        }
    }

    return result;
}
