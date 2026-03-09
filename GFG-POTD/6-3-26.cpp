#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s, string &p)
    {
        unordered_map<char, int> required;
        for (char c : p)
        {
            required[c]++;
        }

        int n = s.size();
        int i = 0;
        int j = 0;

        unordered_map<char, int> track;
        int count = required.size();
        int minI = 0;
        int minJ = n;

        while (j < n)
        {
            if (required.find(s[j]) != required.end())
            {
                track[s[j]]++;
                if (track[s[j]] == required[s[j]])
                {
                    count--;
                }
            }
            // }
            while (count == 0)
            {
                // update window;
                if ((minJ - minI) > (j - i))
                {
                    minI = i;
                    minJ = j;
                }

                if (required.find(s[i]) != required.end())
                {
                    track[s[i]]--;
                    if (track[s[i]] < required[s[i]])
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }

        if (minI == 0 && minJ == n)
        {
            return "";
        }

        return s.substr(minI, minJ - minI + 1);
    }
};