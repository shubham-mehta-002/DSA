#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> maxSegTree;
    vector<int> minSegTree;
    int n;

public:
    void buildMaxSegTree(int index, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            maxSegTree[index] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        buildMaxSegTree(2 * index + 1, l, mid, nums);
        buildMaxSegTree(2 * index + 2, mid + 1, r, nums);

        maxSegTree[index] = max(maxSegTree[2 * index + 1], maxSegTree[2 * index + 2]);
    }

    void buildMinSegTree(int index, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            minSegTree[index] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        buildMinSegTree(2 * index + 1, l, mid, nums);
        buildMinSegTree(2 * index + 2, mid + 1, r, nums);

        minSegTree[index] = min(minSegTree[2 * index + 1], minSegTree[2 * index + 2]);
    }

    int getRangeMax(int l, int r, int start, int end, int index)
    {
        // no overlap
        if (r < start || end < l)
        {
            return INT_MIN;
        }

        // fully cover
        if (start <= l && r <= end)
        {
            return maxSegTree[index];
        }

        // partial overlap
        int mid = (l + r) / 2;
        return max(getRangeMax(l, mid, start, end, 2 * index + 1), getRangeMax(mid + 1, r, start, end, 2 * index + 2));
    }

    int getRangeMin(int l, int r, int start, int end, int index)
    {
        // no overlap
        if (r < start || end < l)
        {
            return INT_MAX;
        }

        // fully cover
        if (start <= l && r <= end)
        {
            return minSegTree[index];
        }

        // partial overlap
        int mid = (l + r) / 2;
        return min(getRangeMin(l, mid, start, end, 2 * index + 1), getRangeMin(mid + 1, r, start, end, 2 * index + 2));
    }

    int getMinMax(int start, int end)
    {
        int maxx = getRangeMax(0, n - 1, start, end, 0);
        int minn = getRangeMin(0, n - 1, start, end, 0);
        if (maxx == INT_MIN || minn == INT_MAX)
        {
            return 0;
        }

        return maxx - minn;
    }

    long long maxTotalValue(vector<int> &nums, int k)
    {
        using pp = pair<int, pair<int, int>>;

        n = nums.size();
        maxSegTree.resize(4 * n);
        minSegTree.resize(4 * n);

        buildMaxSegTree(0, 0, n - 1, nums);
        buildMinSegTree(0, 0, n - 1, nums);

        priority_queue<pp> pq;

        int r = n - 1;
        for (int l = 0; l < n; l++)
        {
            pq.push({getMinMax(l, r), {l, r}});
        }

        long long sum = 0;
        while (k--)
        {
            pp top = pq.top();
            pq.pop();

            sum += top.first;

            int l = top.second.first;
            int r = top.second.second;

            if (r > l)
            {
                pq.push({getMinMax(l, r - 1), {l, r - 1}});
            }
        }

        return sum;
    }
};