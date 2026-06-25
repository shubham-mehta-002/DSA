#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        using pp = pair<int, pair<int, int>>;
        vector<vector<int>> res;

        set<pair<int, int>> visited;
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});

        while (!pq.empty() && k--)
        {
            const pp &top = pq.top();

            int p1 = top.second.first;
            int p2 = top.second.second;

            res.push_back({nums1[p1], nums2[p2]});

            if (p1 + 1 < n1 && visited.find({p1 + 1, p2}) != visited.end())
            {
                pq.push({nums1[p1 + 1] + nums2[p2], {p1 + 1, p2}});
                visited.insert({p1 + 1, p2});
            }
            if (p2 + 1 < n2 && visited.find({p1, p2 + 1}) != visited.end())
            {
                pq.push({nums1[p1] + nums2[p2 + 1], {p1, p2 + 1}});
                visited.insert({p1, p2 + 1});
            }
            pq.pop();
        }

        return res;
    }
};