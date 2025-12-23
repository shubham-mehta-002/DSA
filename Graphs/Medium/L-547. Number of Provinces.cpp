#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void traverse(vector<vector<int>>&adj, vector<int>&vis,int node){
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();
                for(int neigh : adj[top]){
                    if(vis[neigh] == 0){
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                }

                q.pop();
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ;j < n ; j++){
                if(i!=j && isConnected[i][j]==1) adj[i].push_back(j);
            }
        }

        vector<int>vis(n,0);
        int componentCount = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                vis[i] = 1;    
                componentCount++;
                traverse(adj,vis,i);
            }
        }

        return componentCount;
    }
};



// https://leetcode.com/problems/number-of-provinces/