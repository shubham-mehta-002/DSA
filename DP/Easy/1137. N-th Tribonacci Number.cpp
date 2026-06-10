#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int find(int n){
    //     if(n == 0) return 0;
    //     if(n == 1) return 1;
    //     if(n == 2) return 1;

    //     return find(n-2) + find(n-1) + find(n-3);
    // }
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};