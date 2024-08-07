#include <bits/stdc++.h> 

void dfs(unordered_map<int, list<int>> &adj, vector<bool> &visited, int node, stack<int> &st){

    visited[node] = true;

    for(auto neighbours:adj[node]){

        if(!visited[neighbours]){
            dfs(adj, visited, neighbours, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   
   unordered_map<int, list<int>> adj;

   for(int i=0; i<e; i++){
       int u = edges[i][0];
       int v = edges[i][1];

       adj[u].push_back(v);
   }

   vector<bool> visited(v);
   stack<int> st;
   vector<int> ans;

   for(int i=0; i<v; i++){
       if(!visited[i]){
           dfs(adj, visited, i, st);
       }
   }

   while(!st.empty()){
       ans.push_back(st.top());
       st.pop();
   }

   return ans;
}
