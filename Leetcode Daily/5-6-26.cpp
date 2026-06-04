#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int num1)
    {
        int tot = 0;
        string str = to_string(num1);

        for (int i = 1; i < str.size() - 1; i++)
        {
            if (str[i - 1] < str[i] && str[i] > str[i + 1])
            {
                tot += 1;
            }
            else if (str[i - 1] > str[i] && str[i] < str[i + 1])
            {
                tot += 1;
            }
        }

        return tot;
    }
    int totalWaviness(int num1, int num2)
    {
        int tot = 0;
        for (int i = max(100, num1); i <= num2; i++)
        {
            tot += find(i);
        }

        return tot;
    }
};