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

    void removeFromBitmasks(int row, int col, int val)
    {
        bitmasks_row[row] = bitmasks_row[row] ^ (1 << val);
        bitmasks_col[col] = bitmasks_col[col] ^ (1 << val);
        bitmasks_block[row / 3][col / 3] = bitmasks_block[row / 3][col / 3] ^ (1 << val);
    }

    bool find(int row, int col, vector<vector<char>> &board)
    {
        if (col == 9)
        {
            row++;
            col = 0;
        }

        if (row == 9 && col == 0)
            return true;
        if (board[row][col] != '.')
        {
            return find(row, col + 1, board);
        }
        else
        {
            for (int num = 1; num <= 9; num++)
            {
                if (isValid(row, col, num))
                {
                    board[row][col] = (num + '0');
                    markInBitmask(row, col, num);

                    if (find(row, col + 1, board))
                        return true;

                    removeFromBitmasks(row, col, num);
                    board[row][col] = '.';
                }
            }

            return false;
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    markInBitmask(i, j, board[i][j] - '0');
                }
            }
        }

        find(0, 0, board);
    }
};
