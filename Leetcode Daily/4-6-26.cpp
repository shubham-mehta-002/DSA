#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long totalNumbersMem[16][2][2][10][10];
    long long wavinessScoreMem[16][2][2][10][10];

public:
    pair<long long, long long> find(int index, bool leadingZeros, bool tight, string &str, int prev1, int prev2)
    {
        if (index == str.size())
        {
            return {1, 0};
        }

        if (prev1 != -1 && prev2 != -1 && totalNumbersMem[index][leadingZeros][tight][prev1][prev2] != -1 && wavinessScoreMem[index][leadingZeros][tight][prev1][prev2] != -1)
        {
            return {
                totalNumbersMem[index][leadingZeros][tight][prev1][prev2],
                wavinessScoreMem[index][leadingZeros][tight][prev1][prev2]};
        }

        long long wavinessScore = 0;
        long long totalNumbers = 0;

        for (int i = 0; i <= 9; i++)
        {
            if (tight && str[index] - '0' < i)
            {
                continue;
            }

            auto [totalNumberOfCombinationsGeneratedInFutureHavingThisSamePeakOrValley,
                  wavinessScoreGotInFuture] = find(index + 1,
                                                   leadingZeros && i == 0,
                                                   tight && str[index] - '0' == i,
                                                   str,
                                                   leadingZeros && i == 0 ? -1 : prev2,
                                                   leadingZeros && i == 0 ? -1 : i);

            if (prev1 != -1 && prev2 != -1 &&
                ((prev1 < prev2 && prev2 > i) || (prev1 > prev2 && prev2 < i)))
            {
                wavinessScore += totalNumberOfCombinationsGeneratedInFutureHavingThisSamePeakOrValley;
            }

            wavinessScore += wavinessScoreGotInFuture;
            totalNumbers += totalNumberOfCombinationsGeneratedInFutureHavingThisSamePeakOrValley;
        }

        if (prev1 != -1 && prev2 != -1)
        {
            totalNumbersMem[index][leadingZeros][tight][prev1][prev2] = totalNumbers;
            wavinessScoreMem[index][leadingZeros][tight][prev1][prev2] = wavinessScore;
        }

        return {totalNumbers, wavinessScore};
    }

    long long solve(long long num)
    {
        if (num < 100)
        {
            return 0;
        }

        memset(totalNumbersMem, -1, sizeof(totalNumbersMem));
        memset(wavinessScoreMem, -1, sizeof(wavinessScoreMem));

        string str = to_string(num);
        return find(0, true, true, str, -1, -1).second;
    }
    long long totalWaviness(long long num1, long long num2)
    {
        string a = to_string(num1 - 1);
        string b = to_string(num2);

        return solve(num2) - solve(num1 - 1);
    }
};