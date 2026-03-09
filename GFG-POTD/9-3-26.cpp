#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestSwap(string &s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 2;

        int s1 = -1;
        int s2 = -1;
        int maxValIndex = n - 1;
        while (j >= 0)
        {
            if (s[j] > s[maxValIndex])
            {
                maxValIndex = j;
            }

            if (s[j] < s[maxValIndex])
            {
                s1 = j;
                s2 = maxValIndex;
            }
            j--;
        }

        if (s1 != -1)
        {
            swap(s[s1], s[s2]);
        }

        return s;
    }
};