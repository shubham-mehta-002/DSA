#include <bits/stdc++.h>
using namespace std;

class Solution
{
    set<pair<int, int>> pos;
    vector<vector<string>> res;

public:
    bool isValid(int row, int col)
    {
        for (auto p : pos)
        {
            if (p.first + p.second == row + col)
            {
                return false;
            }
            else if (p.first - p.second == row - col)
            {
                return false;
            }
            else if (col == p.second)
            {
                return false;
            }
        }

        return true;
    }

    void find(int row, int n, vector<string> &board)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isValid(row, j))
            {
                board[row][j] = 'Q';
                pos.insert({row, j});

                find(row + 1, n, board);

                pos.erase({row, j});
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string str = "";
        for (int col = 0; col < n; col++)
        {
            str.push_back('.');
        }
        vector<string> board(n, str);

        find(0, n, board);

        return res;
    }
};