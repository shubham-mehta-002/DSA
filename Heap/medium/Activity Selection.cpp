#include <bits/stdc++.h>
using namespace std;
class Solution
{
    typedef pair<int, int> pp;

public:
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (int i = 0; i < start.size(); i++)
            pq.push({finish[i], start[i]});

        int count = 0;
        int currentTime = INT_MIN;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int fin = top.first;
            int strt = top.second;

            if (strt > currentTime)
            {
                count++;
                currentTime = fin;
            }
        }

        return count;
    }
};