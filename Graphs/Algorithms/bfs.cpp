#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>res;
  public:
    void traverse(vector<vector<int>>&adj, vector<int>&vis, int node){
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                for(int neigh : adj[top]){
                    if(vis[neigh] == 0){
                        res.push_back(neigh);
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                }
                q.pop();
            }
        }
    }
    
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>vis(adj.size(),0);
        for(int i = 0; i <adj.size() ; i++){
            if(vis[i] == 0){
                vis[i] = 1; // mark as visited
                res.push_back(i);
                traverse(adj,vis,i);
            }
        }
        return res;
    }
};





// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1