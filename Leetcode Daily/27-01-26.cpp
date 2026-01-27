#include<bits/stdc++.h>
using namespace std;    
typedef pair<int,int> pp;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // adj list 
        vector<vector<pp>>adj(n);
        for(auto e : edges){
            int from = e[0];
            int to = e[1];
            int cost = e[2];

            adj[from].push_back({to,cost});
            adj[to].push_back({from, cost*2});
        }
        // track which edge is visited at what cost  ?
        vector<int> cost(n,INT_MAX);
        cost[0] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();

            for(auto a : adj[node]){
                int u = a.first;
                int newCost = dist + a.second;
                if(newCost < cost[u]){
                    cost[u] = newCost;
                    pq.push({newCost,u});
                } 
            }
        }

        return cost[n-1] == INT_MAX ? -1 : cost[n-1];
    }
};