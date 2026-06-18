#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> m;
        for (int i = 0; i < end.size(); i++)
        {
            m.push_back({end[i], start[i]});
        }

        sort(m.begin(), m.end());

        int currentTime = -1;
        int total = 0;

        for (int i = 0; i < end.size(); i++)
        {
            if (m[i].second > currentTime)
            {
                total++;
                currentTime = m[i].first;
            }
        }

        return total;
    }
};