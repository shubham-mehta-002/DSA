#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long find(int index, unordered_map<int, vector<int>> &tree, vector<int> &baseTime)
    {
        // left node
        if (tree.find(index) == tree.end())
        {
            return baseTime[index];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        for (auto child : tree[index])
        {
            long long res = find(child, tree, baseTime);
            earliest = min(earliest, res);
            latest = max(latest, res);
        }

        long long finishTime = (latest - earliest) + baseTime[index] + latest;
        return finishTime;
    }

    long long finishTime(int n, vector<vector<int>> &edges, vector<int> &baseTime)
    {
        if (n == 1)
        {
            return baseTime[0];
        }

        unordered_map<int, vector<int>> tree;
        for (auto e : edges)
        {
            tree[e[0]].push_back(e[1]);
        }

        return find(0, tree, baseTime);
    }
};