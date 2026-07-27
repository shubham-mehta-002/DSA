#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int bitmasks_row[9] = {0};
    int bitmasks_col[9] = {0};
    int bitmasks_block[3][3] = {0};

public:
    bool isValid(int row, int col, int val)
    {
        if ((bitmasks_row[row] >> val) & 1)
            return false;
        if ((bitmasks_col[col] >> val) & 1)
            return false;
        if ((bitmasks_block[row / 3][col / 3] >> val) & 1)
            return false;
        return true;
    }

    void markInBitmask(int row, int col, int val)
    {
        bitmasks_row[row] = bitmasks_row[row] | (1 << val);
        bitmasks_col[col] = bitmasks_col[col] | (1 << val);
        bitmasks_block[row / 3][col / 3] = bitmasks_block[row / 3][col / 3] | (1 << val);
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                if (!isValid(i, j, board[i][j] - '0'))
                {
                    return false;
                }
                markInBitmask(i, j, board[i][j] - '0');
            }
        }

        return true;
    }
};