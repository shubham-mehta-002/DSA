#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<pair<int, int>> track(26, {-1, -1});
        vector<int> ans;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (track[ch - 'a'].first != -1)
            {
                track[ch - 'a'].second = i;
            }
            else
            {
                track[ch - 'a'] = {i, i};
            }
        }

        sort(track.begin(), track.end());
        int i = 0;

        // skip all invalid ones
        while (i < 26 && track[i].first == -1)
        {
            i++;
        }

        while (i < 26)
        {
            int start = track[i].first;
            int end = track[i].second;
            int j = i;
            while (j < 26 && track[j].first <= end)
            {
                end = max(end, track[j].second);
                j++;
            }
            ans.push_back(end - start + 1);
            i = j;
        }

        return ans;
    }
};