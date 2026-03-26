#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void buildTree(int l, int r, int i, vector<int> &heights, vector<int> &segmentTree)
    {
        if (l == r)
        {
            segmentTree[i] = l;
            return;
        }

        int mid = (l + r) / 2;
        buildTree(l, mid, 2 * i + 1, heights, segmentTree);
        buildTree(mid + 1, r, 2 * i + 2, heights, segmentTree);

        int left = segmentTree[2 * i + 1];
        int right = segmentTree[2 * i + 2];

        segmentTree[i] = (heights[left] > heights[right] ? left : right);
    }

    int RMIQ(int start, int end, int l, int r, int i, vector<int> &heights, vector<int> &segmentTree)
    {
        if (l > end || r < start)
            return -1;
        if (l >= start && r <= end)
            return segmentTree[i];

        int mid = l + (r - l) / 2;
        int leftIndex = RMIQ(start, end, l, mid, 2 * i + 1, heights, segmentTree);
        int rightIndex = RMIQ(start, end, mid + 1, r, 2 * i + 2, heights, segmentTree);

        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        if (heights[leftIndex] > heights[rightIndex])
            return leftIndex;
        return rightIndex;
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();

        vector<int> segmentTree(4 * n, 0);
        vector<int> res;

        buildTree(0, n - 1, 0, heights, segmentTree);

        for (auto q : queries)
        {
            if (q[0] == q[1])
            {
                res.push_back(q[0]);
                continue;
            }

            int a = min(q[0], q[1]);
            int b = a ^ q[0] ^ q[1];

            if (heights[b] > heights[a])
            {
                res.push_back(b);
                continue;
            }

            // binary Search
            int start = b + 1;
            int end = n - 1;
            int resultIdx = -1;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                int idx = RMIQ(start, mid, 0, n - 1, 0, heights, segmentTree);
                if (heights[idx] > heights[a] && heights[idx] > heights[b])
                {
                    resultIdx = idx;
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            res.push_back(resultIdx);
        }

        return res;
    }
};