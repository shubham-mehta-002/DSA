#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void populateMap(unordered_map<char, pair<int, int>> &m)
    {
        m['I'] = {1, 1};
        m['V'] = {5, 2};
        m['X'] = {10, 3};
        m['L'] = {50, 4};
        m['C'] = {100, 5};
        m['D'] = {500, 6};
        m['M'] = {1000, 7};
    }

    int romanToInt(string s)
    {
        unordered_map<char, pair<int, int>> mpp;

        populateMap(mpp);

        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i == s.size() - 1 || mpp[s[i + 1]].second <= mpp[s[i]].second)
            {
                count += mpp[s[i]].first;
            }
            else
            {
                count -= mpp[s[i]].first;
            }
        }

        return count;
    }
};