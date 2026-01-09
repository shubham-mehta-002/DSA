#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(vector<vector<int>>&adj, int node, vector<int>&path,vector<int>&vis){
        path[node] = 1;
        vis[node] = 1;
        
        for(int a : adj[node]){
            if(path[a] == 1){
                return true;
            }        
            
            if(dfs(adj,a,path,vis)){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>vis(V,-1);
        // adj matrix
        vector<vector<int>>adj(V);
        for(auto a : edges){
            int from = a[0];
            int to = a[1];
            
            adj[from].push_back(to);
        }
        
        vector<int>path(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]!=1 && dfs(adj,i,path,vis)){
                return true;
            }
        }
        return false;
        
        
    }
};