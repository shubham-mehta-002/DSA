#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
    unordered_map<int, int> segTree;
    unordered_map<int, int> lazy;

    int query(int start, int end, int l, int r, int index)
    {
        // out of bounds
        if (r < start || l > end)
        {
            return 0;
        }

        // full overlap
        if (start <= l && r <= end)
        {
            return segTree[index];
        }

        int mid = (l + r) / 2;
        int leftTree = query(start, end, l, mid, 2 * index + 1);
        int rightTree = query(start, end, mid + 1, r, 2 * index + 2);

        // Add lazy val
        return lazy[index] + max(leftTree, rightTree);
    }

    void update(int start, int end, int l, int r, int index, int val)
    {
        // out of bounds
        if (r < start || l > end)
            return;

        // full overlap
        if (start <= l && end >= r)
        {
            segTree[index] += val;
            lazy[index] += val;
            return;
        }

        int mid = (l + r) / 2;
        update(start, end, l, mid, 2 * index + 1, val);
        update(start, end, mid + 1, r, 2 * index + 2, val);

        segTree[index] = lazy[index] + max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

public:
    MyCalendarTwo()
    {
    }

    bool book(int startTime, int endTime)
    {
        // check if already we are full capacity of 2 or more
        if (query(startTime, endTime - 1, 0, 1e9, 0) >= 2)
        {
            return false;
        }

        // safe -> update
        update(startTime, endTime - 1, 0, 1e9, 0, 1);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */