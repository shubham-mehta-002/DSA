#include <bits/stdc++.h>
using namespace std;


class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n, int m) {
        parent.resize(n * m);
        size.resize(n * m, 1);

        for (int i = 0; i < n * m; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv)
            return;

        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int getSize(int node) {
        return size[findUltimateParent(node)];
    }
};

class Solution {
    int n, m;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    int getIndex(int r, int c) {
        return r * m + c;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        DSU d(n, m);

        // Build connected components of 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int newr = i + dx[k];
                    int newc = j + dy[k];

                    if (newr >= 0 && newc >= 0 &&
                        newr < n && newc < m &&
                        grid[newr][newc] == 1) {

                        d.unionBySize(
                            getIndex(i, j),
                            getIndex(newr, newc)
                        );
                    }
                }
            }
        }

        int ans = 0;

        // Try converting each 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    continue;

                set<int> st;

                for (int k = 0; k < 4; k++) {
                    int newr = i + dx[k];
                    int newc = j + dy[k];

                    if (newr >= 0 && newc >= 0 &&
                        newr < n && newc < m &&
                        grid[newr][newc] == 1) {

                        st.insert(d.findUltimateParent(getIndex(newr, newc)));
                    }
                }

                int total = 0;

                for (auto parent : st)
                    total += d.getSize(parent);

                total++; // for the converted 0 to 1 cell

                ans = max(ans, total);
            }
        }

        // // Handle the case where the grid is already all 1's
        // for (int i = 0; i < n * m; i++)
        //     ans = max(ans, d.getSize(i));

        return ans == 0 ? n*m : ans;
    }
};