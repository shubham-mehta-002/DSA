#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;

public:
    void find(int l, int r, int k, vector<int> &temp)
    {
        if (k == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = l; i <= r; i++)
        {
            temp.push_back(i);
            find(i + 1, r, k - 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        find(1, n, k, temp);
        return res;
    }
};