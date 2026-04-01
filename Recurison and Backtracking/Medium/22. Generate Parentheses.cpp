#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> res;

public:
    void find(int open, int close, string &temp, int n)
    {
        if (open + close == 2 * n)
        {
            res.push_back(temp);
            return;
        }
        // open
        if (open < n)
        {
            temp += '(';
            find(open + 1, close, temp, n);
            temp.pop_back();
        }

        // close
        if (open > close)
        {
            temp += ')';
            find(open, close + 1, temp, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int open = 0;
        int close = 0;
        string temp = "";
        find(open, close, temp, n);

        return res;
    }
};