#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.

    vector<int> minMax(int start, int end, int l, int r, int i, vector<vector<int>> &segTree)
    {
        if (start > r || end < l)
        {
            return {INT_MAX, INT_MIN};
        }

        if (start <= l && end >= r)
        {
            return segTree[i];
        }

        int mid = (l + r) / 2;
        vector<int> left = minMax(start, end, l, mid, 2 * i + 1, segTree);
        int leftMin = left[0];
        int leftMax = left[1];

        vector<int> right = minMax(start, end, mid + 1, r, 2 * i + 2, segTree);
        int rightMin = right[0];
        int rightMax = right[1];

        return {
            min(leftMin, rightMin),
            max(leftMax, rightMax)};
    }
    vector<int> getMinMax(vector<int> &arr, int L, int R,
                          vector<vector<int>> &segTree)
    {
        return minMax(L, R, 0, arr.size() - 1, 0, segTree);
    }

    // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
    void update(int l, int r, int i, int index, int val, vector<vector<int>> &segTree)
    {
        if (l == r)
        {
            segTree[i] = {val, val};
            return;
        }
        int mid = (l + r) / 2;

        if (index <= mid)
        {
            update(l, mid, 2 * i + 1, index, val, segTree);
        }
        else
        {
            update(mid + 1, r, 2 * i + 2, index, val, segTree);
        }

        segTree[i] = {
            min(segTree[2 * i + 1][0], segTree[2 * i + 2][0]),
            max(segTree[2 * i + 1][1], segTree[2 * i + 2][1])};
    }

    void updateValue(vector<int> &arr, int index, int value,
                     vector<vector<int>> &segTree)
    {
        update(0, arr.size() - 1, 0, index, value, segTree);
    }
};