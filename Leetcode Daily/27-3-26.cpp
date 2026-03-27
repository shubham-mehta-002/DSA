#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int newPos = j;
                if (i % 2 == 0)
                {
                    newPos = (j - k + n) % n;
                }
                else
                {
                    newPos = (j + k) % n;
                }
                if (mat[i][newPos] != mat[i][j])
                    return false;
            }
        }

        return true;
    }
};