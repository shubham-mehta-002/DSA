#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> segTree;
    const int MOD = 1e9 + 7;

public:
    void buildSegmentTree(int l, int r, int index, vector<int> &nums)
    {
        if (l == r)
        {
            segTree[index] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegmentTree(l, mid, 2 * index + 1, nums);
        buildSegmentTree(mid + 1, r, 2 * index + 2, nums);

        segTree[index] = segTree[2 * index + 1] ^ segTree[2 * index + 2];
    }

    void pointUpdate(int targetIndex, int l, int r, int index, int value)
    {
        if (l == r)
        {
            segTree[index] = ((long long)segTree[index] * value) % MOD;
            return;
        }
        int mid = (l + r) / 2;
        if (targetIndex <= mid)
        {
            pointUpdate(targetIndex, l, mid, 2 * index + 1, value);
        }
        else
        {
            pointUpdate(targetIndex, mid + 1, r, 2 * index + 2, value);
        }

        segTree[index] = segTree[2 * index + 1] ^ segTree[2 * index + 2];
    }

    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        segTree.resize(n * 4);

        buildSegmentTree(0, n - 1, 0, nums);

        for (auto q : queries)
        {
            int l = q[0];
            int r = q[1];
            int step = q[2];
            int value = q[3];

            for (int idx = l; idx <= r; idx += step)
            {
                pointUpdate(idx, 0, n - 1, 0, value);
            }
        }

        return segTree[0];
    }
};