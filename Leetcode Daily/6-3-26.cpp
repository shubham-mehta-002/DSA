#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int count = 0;
        int n = s.size();
        int i = 0;

        while (i < n && count <= 1)
        {
            if (s[i] == '1')
            {
                while (i < n && s[i] == '1')
                {
                    i++;
                }
                count++;
            }
            else
            {
                i++;
            }
        }
        return (count <= 1);
    }
};