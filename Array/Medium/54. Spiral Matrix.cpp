#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int rowStart = 0;
        int rowEnd = m - 1;

        int colStart = 0;
        int colEnd = n - 1;

        vector<int> res;

        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            // iterate over startRow
            for (int j = colStart; j <= colEnd; j++)
            {
                res.push_back(matrix[rowStart][j]);
            }
            rowStart++;

            for (int i = rowStart; i <= rowEnd; i++)
            {
                res.push_back(matrix[i][colEnd]);
            }

            colEnd--;

            if (rowStart <= rowEnd)
            {
                for (int j = colEnd; j >= colStart; j--)
                {
                    res.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;

            if (colStart <= colEnd)
            {
                for (int i = rowEnd; i >= rowStart; i--)
                {
                    res.push_back(matrix[i][colStart]);
                }
            }
            colStart++;
        }

        return res;
    }
};