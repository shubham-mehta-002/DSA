#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int get(vector<vector<int>> &dp, int i, int j)
    {
        if (i > j)
            return 0;
        return dp[i][j];
    }

    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int total = accumulate(
            nums.begin(),
            nums.end(),
            0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {

                int option1 = nums[i] + min(
                                            get(dp, i + 2, j),
                                            get(dp, i + 1, j - 1));

                int option2 = nums[j] + min(
                                            get(dp, i + 1, j - 1),
                                            get(dp, i, j - 2));

                dp[i][j] = max(option1, option2);
            }
        }

        int player1 = dp[0][n - 1];
        int player2 = total - player1;

        return player1 >= player2;
    }
};