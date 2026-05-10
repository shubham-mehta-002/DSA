#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, bool> mem;

public:
    bool dfs(int index, vector<int> &arr, vector<int> &vis)
    {
        vis[index] = 1;

        if (mem.find(index) != mem.end())
        {
            return mem[index];
        }
        if (arr[index] == 0)
            return mem[index] = true;

        // left
        if (index - arr[index] >= 0 && !vis[index - arr[index]] && dfs(index - arr[index], arr, vis))
        {
            return mem[index] = true;
        }

        // right
        if (index + arr[index] < arr.size() && !vis[index + arr[index]] && dfs(index + arr[index], arr, vis))
        {
            return mem[index] = true;
        }

        vis[index] = 0;

        return mem[index] = false;
    }
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);

        return dfs(start, arr, vis);
    }
};