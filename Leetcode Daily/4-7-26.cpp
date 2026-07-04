#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<pair<int,int>>>adj;
    vector<int>vis;
public:
    int find(int node){
        int ans = INT_MAX;
        vis[node] = 1;
        
        for(auto nbr : adj[node]){
            ans = min(ans, nbr.second);
            if(!vis[nbr.first]){
                ans = min(ans, find(nbr.first));
            }
        }

        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto r : roads){
            adj[r[0]].push_back( {r[1],r[2]} );
            adj[r[1]].push_back( {r[0],r[2]} );
        }
    
        vis.resize(n+1,0);

        return find(n);
    }
};