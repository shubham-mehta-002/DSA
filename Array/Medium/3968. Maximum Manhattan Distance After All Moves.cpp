#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(string moves)
    {
        int row = 0;
        int col = 0;
        int allowed = 0;

        for (char ch : moves)
        {
            if (ch == 'U')
                row++;
            else if (ch == 'D')
                row--;
            else if (ch == 'L')
                col--;
            else if (ch == 'R')
                col++;
            else
                allowed++;
        }

        return abs(row - 0) + abs(col - 0) + allowed;
    }
};