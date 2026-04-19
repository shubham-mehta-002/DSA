#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPower(int x, int y)
    {
        if (x == 1)
            return y == 1;
        if (y == 1)
            return true;

        while (y % x == 0)
        {
            y /= x;
        }

        return y == 1;
    }
};