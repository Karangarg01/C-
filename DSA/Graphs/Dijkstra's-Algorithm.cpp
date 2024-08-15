#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   
   // Create adjacency list
   unordered_map<int, list<pair<int,int>>> adj; 
   for(int i = 0; i < vec.size(); i++) {
       int u = vec[i][0];
       int v = vec[i][1];
       int w = vec[i][2];

       adj[u].push_back(make_pair(v, w));
       adj[v].push_back(make_pair(u, w));
   }

   // Initialize distance vector with INT_MAX
   vector<int> distance(vertices, INT_MAX);

   // Set to store (distance, node) pairs
   set<pair<int, int>> st;

   // Initialize the source node's distance
   distance[source] = 0;
   st.insert(make_pair(0, source));

   while(!st.empty()) {
        
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second; 

        st.erase(st.begin());

        // Explore neighbors of topNode
        for(auto neighbours: adj[topNode]) {
            int neighborNode = neighbours.first;
            int edgeWeight = neighbours.second;

            // Relaxation step
            if(nodeDistance + edgeWeight < distance[neighborNode]) {
                
                auto record = st.find(make_pair(distance[neighborNode], neighborNode));

                if(record != st.end()) {
                    st.erase(record);
                }
                
                distance[neighborNode] = nodeDistance + edgeWeight;

                st.insert(make_pair(distance[neighborNode], neighborNode));
            }
        }
   }

   return distance;
}
