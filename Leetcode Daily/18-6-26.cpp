#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double h_move = (hour % 12) * 30.0 + (minutes / 60.0) * 30.0;
        double m_move = minutes * 6.0;

        double diff = abs(h_move - m_move);
        return min({diff,
                    360 - diff});
    }
};
