#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis, int V , int node){
        vis[node] = 1;
        
        for(int a : adj[node]){
            if(vis[a] || dfs(adj,vis,V,a)){
                return true;
            }
        }
        
        vis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>vis(V,0);
        
        vector<vector<int>>adj(V);
        
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i = 0 ; i<V;i++){
            if(!vis[i] && dfs(adj,vis,V,i)){
                return true;
            }
        }
        
        return false;
    }
};