#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, vector<int>> reversed;

    void dfs(int node, stack<int>& st, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, st, vis);
            }
        }

        // Push AFTER processing all neighbours
        st.push(node);
    }

    void getSCC(int node, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : reversed[node]) {
            if (!vis[it]) {
                getSCC(it, vis);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& edges) {

        // Build original graph and reversed graph
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            reversed[e[1]].push_back(e[0]);
        }

        // 1. Get finishing-time ordering
        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, st, vis);
            }
        }

        // 2. Reset visited
        fill(vis.begin(), vis.end(), 0);

        // 3. DFS on reversed graph
        int scc = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                scc++;
                getSCC(node, vis);
            }
        }

        return scc;
    }
};