#include<queue>
#include<unordered_map>

void bfs(int n, vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> visited, int root){

    queue<int> q;
    q.push(root);

    visited[root] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i:adj[front]){

            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;

    unordered_map<int, bool> visited;

    bfs(n,adj,ans,visited,0);
    return ans;
}
