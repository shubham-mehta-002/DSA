#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> res;

public:
    bool isPalin(int i, int j, string &s)
    {
        if (i > j)
            return true;

        return s[i] == s[j] && isPalin(i + 1, j - 1, s);
    }
    string getStr(int i, int j, string &s)
    {
        string str = "";
        for (int index = i; index <= j; index++)
        {
            str += s[index];
        }

        return str;
    }
    void find(int index, string &s, vector<string> &temp)
    {
        if (index == s.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalin(index, i, s))
            {
                temp.push_back(getStr(index, i, s));
                find(i + 1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        find(0, s, temp);

        return res;
    }
};