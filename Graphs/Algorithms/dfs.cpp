#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int>res;
public:
    void traverse(vector<vector<int>>&adj, vector<int>&vis, int node){
        vis[node] = 1;
        res.push_back(node);
        for(int el : adj[node]){
            if(!vis[el])
            traverse(adj,vis,el);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
       int n = adj.size();
       vector<int>vis(n,0);
       
       for(int i=0;i<n;i++){
           if(!vis[i]){
               traverse(adj,vis,i);
           }
       }
       
       return res;
    }
};


// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1