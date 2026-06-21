#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct State
    {
        int node;
        int cnt;
        int cost;

        bool operator>(const State &other) const
        {
            return cost > other.cost;
        }
    };

    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        const int INF = 1e9;

        // dist[node][consecutiveCount]
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        priority_queue<
            State,
            vector<State>,
            greater<State>>
            pq;

        dist[0][1] = 0;

        pq.push({0, 1, 0});

        while (!pq.empty())
        {

            auto [u, cnt, cost] = pq.top();
            pq.pop();

            if (cost > dist[u][cnt])
                continue;

            if (u == n - 1)
                return cost;

            for (auto &[v, w] : adj[u])
            {

                int newCnt;

                if (labels[v] == labels[u])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k)
                    continue;

                int newCost = cost + w;

                if (newCost < dist[v][newCnt])
                {

                    dist[v][newCnt] = newCost;

                    pq.push({v, newCnt, newCost});
                }
            }
        }

        return -1;
    }
};