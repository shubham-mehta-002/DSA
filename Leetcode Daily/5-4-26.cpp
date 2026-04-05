#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int col = 0;
        int row = 0;

        for (char m : moves)
        {
            if (m == 'L')
                col--;
            if (m == 'R')
                col++;
            if (m == 'U')
                row--;
            if (m == 'D')
                row++;
        }

        return (col == 0 && row == 0);
    }
};