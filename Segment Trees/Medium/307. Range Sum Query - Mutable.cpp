#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    int n;
    int *segmentTree;
    void buildTree(int l, int r, int i, vector<int> &nums)
    {
        if (l == r)
        {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        buildTree(l, mid, 2 * i + 1, nums);
        buildTree(mid + 1, r, 2 * i + 2, nums);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    int findSum(int start, int end, int l, int r, int i)
    {
        if (r < start || l > end)
        {
            return 0;
        }

        if (l >= start && r <= end)
        {
            return segmentTree[i];
        }
        int mid = (l + r) / 2;

        return (findSum(start, end, l, mid, 2 * i + 1) + findSum(start, end, mid + 1, r, 2 * i + 2));
    }

    void updateTree(int l, int r, int i, int index, int val)
    {
        if (l == r)
        {
            segmentTree[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (index <= mid)
        {
            updateTree(l, mid, 2 * i + 1, index, val);
        }
        else
        {
            updateTree(mid + 1, r, 2 * i + 2, index, val);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segmentTree = new int[4 * n];
        buildTree(0, n - 1, 0, nums);
    }

    void update(int index, int val)
    {
        updateTree(0, n - 1, 0, index, val); // point update
    }

    int sumRange(int left, int right)
    {
        return findSum(left, right, 0, n - 1, 0);
    }
};
