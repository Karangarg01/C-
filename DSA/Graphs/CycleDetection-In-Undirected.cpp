#include<unordered_map>
#include<queue>
#include<list>

bool isCycleBFS(unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, int src){

    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour:adj[front]){

            if(visited[neighbour] && neighbour!=parent[front]){
                return true;
            }

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

bool isCycleDFS(int node, int parent,
unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){

    visited[node] = true;

    for(neighbour: adj[node]){
        if(!visited[neighbour]){
            bool check = isCycleDFS(neighbour,node , visited, adj);
            if(check) 
                return true;
        }

        else if(neighbour!=parent){
            return true;
        }
    }

    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   unordered_map<int, list<int>> adj;
   unordered_map<int, bool> visited;

   for(int i=0; i<m; i++){
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }

    for(int i=0; i<n; i++){
        if(!visited[i]){

            bool check = isCycleDFS(i,-1,visited, adj);
            if(check) return "Yes";
        }
    }

    return "No";
}
