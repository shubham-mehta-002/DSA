#include <bits/stdc++.h>
using namespace std;

void buildTree(int i, int l, int r, int *segmentTree, int arr[])
{
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(2 * i + 1, l, mid, segmentTree, arr);
    buildTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int *constructST(int arr[], int n)
{
    int *segmentTree = new int[n * 4];

    buildTree(0, 0, n - 1, segmentTree, arr);

    return segmentTree;
}

/* The functions returns the
 min element in the range
 from a and b */
int query(int l, int r, int start, int end, int i, int st[])
{
    // No overlap
    if (l > end || r < start)
        return INT_MAX;

    // Complete overlap
    if (l >= start && r <= end)
        return st[i];

    int mid = (l + r) / 2;

    return min(
        query(l, mid, start, end, 2 * i + 1, st),
        query(mid + 1, r, start, end, 2 * i + 2, st));
}

int RMQ(int st[], int n, int a, int b)
{

    return query(0, n - 1, a, b, 0, st);
}