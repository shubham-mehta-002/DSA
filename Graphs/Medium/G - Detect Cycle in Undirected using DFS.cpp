#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool hasCycle(vector<vector<int>>&adj,vector<int>&vis,int parent, int node){
        vis[node] = 1;
        for(int el : adj[node]){
            if(el != parent){
                if(vis[el] == 1 || (vis[el] == 0 && hasCycle(adj,vis,node,el)))    return true;
                
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(const vector<int>&v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                if(hasCycle(adj,vis,-1,i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1