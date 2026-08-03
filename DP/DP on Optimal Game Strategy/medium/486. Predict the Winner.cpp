#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[20][20];

public:
    int find(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;
        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }
        return mem[i][j] = max(
                   nums[i] - find(i + 1, j, nums),
                   nums[j] - find(i, j - 1, nums));
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        memset(mem, -1, sizeof(mem));
        return find(0, nums.size() - 1, nums) >= 0;
    }
};