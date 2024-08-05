#include <unordered_map>
#include <list>

bool isCycleDFS(vector<bool> &visited, vector<bool> &dfsVisited,
 unordered_map<int, list<int>> &adj, int node)
{
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool ans = isCycleDFS(visited, dfsVisited, adj, neighbour);
      if(ans)
        return true;
    }

    else if(dfsVisited[neighbour]){
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  unordered_map<int, list<int>> adj;

  for(auto i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  vector<bool> visited(n,false);
  vector<bool> dfsVisited(n,false);
  
  for(int i=0; i<n; i++){
    if(!visited[i]){
      bool ans = isCycleDFS(visited, dfsVisited, adj, i);
      if(ans) 
        return 1;
    }
  }

  return 0;
}
