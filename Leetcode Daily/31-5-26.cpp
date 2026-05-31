#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        long long curr = mass;
        for (int a : asteroids)
        {
            if (a > curr)
                return false;
            curr += a;
        }

        return true;
    }
};