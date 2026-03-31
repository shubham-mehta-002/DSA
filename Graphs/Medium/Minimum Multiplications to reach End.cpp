#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e5;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        int steps = 0;
        vector<int> dist(1e5, INT_MAX);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int size = q.size();
            steps++;
            while (size--)
            {
                int top = q.front();
                q.pop();

                for (int i = 0; i < arr.size(); i++)
                {
                    int val = (arr[i] * top) % MOD;
                    if (steps < dist[val])
                    {
                        dist[val] = steps;
                        q.push(val);
                    }
                }
            }
        }

        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};
