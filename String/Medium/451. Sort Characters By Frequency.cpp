#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        vector<pair<int, char>> pp;

        for (unordered_map<char, int>::iterator it = freq.begin(); it != freq.end(); it++)
        {
            pp.push_back({it->second, it->first});
        }

        sort(pp.begin(), pp.end(), [](pair<int, char> &a, pair<int, char> &b)
             { return a.first > b.first; });

        string res = "";
        for (auto p : pp)
        {
            for (int i = 1; i <= p.first; i++)
            {
                res += p.second;
            }
        }

        return res;
    }
};