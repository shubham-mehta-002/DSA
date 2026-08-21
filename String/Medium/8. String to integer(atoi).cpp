#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        long num = 0;
        int sign = 1;

        // skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // check sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // convert digits
        while (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');

            // handle overflow immediately
            if (sign * num > INT_MAX)
                return INT_MAX;
            if (sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
