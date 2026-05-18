#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int top = q.front();
                q.pop();

                if (top == n - 1)
                    return jumps;

                // same-value jumps
                for (int idx : mpp[arr[top]])
                {
                    if (!vis[idx])
                    {
                        vis[idx] = 1;
                        q.push(idx);
                    }
                }

                // important
                mpp[arr[top]].clear();

                // left
                if (top - 1 >= 0 && !vis[top - 1])
                {
                    vis[top - 1] = 1;
                    q.push(top - 1);
                }

                // right
                if (top + 1 < n && !vis[top + 1])
                {
                    vis[top + 1] = 1;
                    q.push(top + 1);
                }
            }
            jumps++;
        }

        return -1;
    }
};