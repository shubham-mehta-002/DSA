#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> res;

public:
    void find(int index, string &s, string &temp)
    {
        if (index == s.size())
        {
            if (temp.size() > 0)
            {
                res.push_back(temp);
            }
            return;
        }
        // take
        temp += s[index];
        find(index + 1, s, temp);
        temp.pop_back();
        // not take
        find(index + 1, s, temp);
    }
    vector<string> AllPossibleStrings(string s)
    {
        string temp = "";
        find(0, s, temp);
        sort(res.begin(), res.end());
        return res;
    }
};