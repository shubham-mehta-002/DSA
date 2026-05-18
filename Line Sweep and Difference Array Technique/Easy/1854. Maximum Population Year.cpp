#include <bits/stdc++.h>
using namespace std;

// ALTERNATIVE SOLUTION
// class Solution
// {
// public:
//     int minMeetingRooms(vector<int> &start, vector<int> &end)
//     {
//         sort(start.begin(), start.end());
//         sort(end.begin(), end.end());
//         int n = start.size();
//         int i = 0;
//         int j = 0;
//         int curr = 0;
//         int maxRooms = 0;

//         while (i < n && j < n)
//         {
//             if (start[i] < end[j])
//             {
//                 curr++;
//                 i++;
//             }
//             else if (start[i] > end[i])
//             {
//                 curr--;
//                 j++;
//             }
//             else
//             {
//                 i++;
//                 j++;
//             }

//             maxRooms = max(maxRooms, curr);
//         }

//         return maxRooms;
//     }
// };

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int n = logs.size();
        vector<pair<int, int>> events; // {event,delta}
        for (int i = 0; i < n; i++)
        {
            events.push_back({logs[i][0], +1});
            events.push_back({logs[i][1], -1});
        }

        sort(events.begin(), events.end());

        int maxPop = 0;
        int currPop = 0;
        int year = -1;

        for (auto e : events)
        {
            int yr = e.first;
            int delta = e.second;

            currPop += delta;
            if (currPop > maxPop)
            {
                maxPop = currPop;
                year = yr;
            }
        }

        return year;
    }
};