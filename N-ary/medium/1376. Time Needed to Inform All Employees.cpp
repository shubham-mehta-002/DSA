#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int empId, unordered_map<int, vector<int>> &mpp, vector<int> &informTime, int time)
    {
        if (mpp[empId].size() == 0)
        {
            return time;
        }

        int maxx = 0;
        for (int em : mpp[empId])
        {
            maxx = max(maxx, find(em, mpp, informTime, time + informTime[empId]));
        }

        return maxx;
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> time(n, 0);
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                mpp[manager[i]].push_back(i);
            }
        }

        return find(headID, mpp, informTime, 0);
    }
};