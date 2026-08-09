#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int bottles = numBottles;
        int ans = 0;

        while (bottles)
        {
            if (bottles >= numExchange)
            {
                ans += numExchange;
                bottles -= (numExchange - 1);
                numExchange++;
            }
            else
            {
                ans += bottles;
                bottles = 0;
            }
        }
        return ans;
    }
};