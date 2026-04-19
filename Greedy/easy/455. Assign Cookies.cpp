#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int student = 0;
        int cookie = 0;

        while (student < g.size() && cookie < s.size())
        {
            if (g[student] <= s[cookie])
            {
                student++;
                cookie++;
            }
            else
            {
                cookie++;
            }
        }
        return student;
    }
};