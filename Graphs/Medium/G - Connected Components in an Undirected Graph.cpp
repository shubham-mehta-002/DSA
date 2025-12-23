#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<vector<int>>&adj, vector<int>&vis, vector<int>&nodes, int node){
        vis[node] = 1;
        nodes.push_back(node);
        
        for(int neigh : adj[node]){
            if(vis[neigh] ==0){
                dfs(adj,vis,nodes,neigh);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        // adj list
        vector<vector<int>>adj(V);
        for(const vector<int> &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        
        vector<vector<int>>res;
        vector<int>vis(V,0);
        
        for(int i = 0; i<V;i++){
            if(vis[i] == 0){
                vector<int>nodes;
                dfs(adj,vis,nodes,i);
                res.push_back(nodes);
            }
        }
        
        return res;
    }
};




// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1