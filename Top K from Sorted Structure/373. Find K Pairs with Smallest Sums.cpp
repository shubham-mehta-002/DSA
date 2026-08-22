#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    using pp = pair<int, pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> res;

        int n1 = nums1.size();
        int n2 = nums2.size();
        set<pair<int, int>> vis;
        vis.insert({0, 0});

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        while (!pq.empty() && k--)
        {
            pp top = pq.top();
            pq.pop();

            int sum = top.first;
            int index1 = top.second.first;
            int index2 = top.second.second;

            res.push_back({nums1[index1], nums2[index2]});

            if (index1 + 1 < n1 && (vis.find({index1 + 1, index2}) == vis.end()))
            {
                pq.push({nums1[index1 + 1] + nums2[index2], {index1 + 1, index2}});
                vis.insert({index1 + 1, index2});
            }

            if (index2 + 1 < n2 && (vis.find({index1, index2 + 1}) == vis.end()))
            {
                pq.push({nums1[index1] + nums2[index2 + 1], {index1, index2 + 1}});
                vis.insert({index1, index2 + 1});
            }
        }

        return res;
    }
};