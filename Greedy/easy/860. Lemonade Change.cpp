#include <bits/stdc++.h>
using namespace std;
class Solution

{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0, tens = 0, twenties = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fives++;
            }
            else if (bills[i] == 10)
            {
                if (fives == 0)
                {
                    return false;
                }
                tens++;
                fives--;
            }
            else
            {
                if ((tens > 0 && fives > 0) || (fives > 2))
                {
                    twenties++;
                    if (tens > 0 && fives > 0)
                    {
                        tens--;
                        fives--;
                    }
                    else
                    {
                        fives -= 3;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};