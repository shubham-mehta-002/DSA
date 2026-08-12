#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[100][201];

public:
    int find(int i, int m, vector<int> &piles)
    {
        int n = piles.size();
        if (i == n)
        {
            return 0;
        }

        if (mem[i][m] != -1)
        {
            return mem[i][m];
        }

        int maxx = -1e6;
        int sum = 0;
        for (int k = i; k < min(n, i + 2 * m); k++)
        {
            sum += piles[k];
            maxx = max(
                maxx,
                sum - find(k + 1, max(m, k - i + 1), piles));
        }

        return mem[i][m] = maxx;
    }

    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);

        memset(mem, -1, sizeof(mem));

        int diff = find(0, 1, piles);
        return (total + diff) / 2;
    }
};