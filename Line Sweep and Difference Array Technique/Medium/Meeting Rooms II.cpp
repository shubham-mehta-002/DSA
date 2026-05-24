#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end)
    {
        map<int, int> mpp;
        int n = start.size();

        for (int i = 0; i < n; i++)
        {
            mpp[start[i]]++;
            mpp[end[i]]--;
        }

        int maxRooms = 0;
        int curr = 0;

        for (auto m : mpp)
        {
            curr += m.second;
            maxRooms = max(maxRooms, curr);
        }
        return maxRooms;
    }
};
