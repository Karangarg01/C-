#include<unordered_map>

void adjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges, int E){

    for(int i=0; i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(vector<int> &result,unordered_map<int, bool> &visited,
unordered_map<int, list<int>> &adj, int node){

    result.push_back(node);
    visited[node] = true;

    for(auto i:adj[node]){

        if(!visited[i]){
            dfs(result, visited, adj, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    // Create adjacency list
    adjList(adj, edges, E);

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> result;
            dfs(result, visited, adj, i);
            ans.push_back(result);
        }
    }

    return ans;
    
}
