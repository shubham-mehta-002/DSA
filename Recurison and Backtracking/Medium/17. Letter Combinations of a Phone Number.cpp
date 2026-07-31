#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> res;
    unordered_map<int, string> mpp;

public:
    void find(int index, string &temp, string &digits)
    {
        if (index == digits.size())
        {
            res.push_back(temp);
            return;
        }

        for (char c : mpp[digits[index] - '0'])
        {
            temp += c;
            find(index + 1, temp, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        string temp = "";

        find(0, temp, digits);
        return res;
    }
};