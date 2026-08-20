#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    string mergeCharacters(string s, int k)
    {
        string res = "";
        unordered_map<char, int> mpp;
        int offset = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (mpp.find(c) != mpp.end())
            {
                int dist = i - offset - mpp[c];
                if (dist <= k)
                {
                    offset++;
                }
                else
                {
                    mpp[c] = i - offset;
                    res += c;
                }
            }
            else
            {
                mpp[c] = i - offset;
                res += c;
            }
        }

        return res;
    }
};