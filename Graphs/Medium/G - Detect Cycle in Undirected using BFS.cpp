#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool hasCycle(vector<vector<int>>&adj, vector<int>&vis,queue<pair<int,int>>&q){
        while(!q.empty()){
            const pair<int,int>&p = q.front();
            int parent = p.first;
            int node = p.second;
            for(int el : adj[node]){
                if(el!=parent){
                    if(vis[el]){
                        return true;
                    }else{
                        vis[el] = 1;
                        q.push({node,el});
                    }
                }
            }
            q.pop();
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
        queue<pair<int,int>>q;
        
        for(int i = 0 ; i<V;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push({-1,i});
                if(hasCycle(adj,vis,q)){
                    return true;   
                }    
            }
            
        }
        
        return false;
    }
};

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1