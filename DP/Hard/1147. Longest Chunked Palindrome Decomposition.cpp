#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestDecomposition(string a)
    {
        int start = 0, end = a.size() - 1, cnt = 0;

        string temp, t;
        while (start < end)
        {
            temp += a[start];
            t += a[end];
            string t1 = t;
            reverse(t1.begin(), t1.end());
            if (t1 == temp)
            {
                cnt += 2;
                t1 = "";
                t = "";
                temp = "";
            }
            start++;
            end--;
        }

        if (start == end || temp != "")
            cnt++;
        return cnt;
    }
};