#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void buildSegmentTree(int l, int r, vector<int> &segmentTree, int arr[], int i)
    {
        if (l == r)
        {
            segmentTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSegmentTree(l, mid, segmentTree, arr, 2 * i + 1);
        buildSegmentTree(mid + 1, r, segmentTree, arr, 2 * i + 2);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    int rangeSumQuery(int start, int end, int i, int l, int r, vector<int> &segmentTree)
    {
        if (l > end || r < start)
        {
            return 0;
        }

        if (l >= start && r <= end)
        {
            return segmentTree[i];
        }
        int mid = (l + r) / 2;
        return (rangeSumQuery(start, end, 2 * i + 1, l, mid, segmentTree) + rangeSumQuery(start, end, 2 * i + 2, mid + 1, r, segmentTree));
    }

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> segmentTree(4 * n, 0);
        buildSegmentTree(0, n - 1, segmentTree, arr, 0);

        vector<int> res;

        for (int i = 0; i < 2 * q; i += 2)
        {
            res.push_back(rangeSumQuery(queries[i] - 1, queries[i + 1] - 1, 0, 0, n - 1, segmentTree));
        }

        return res;
    }
};