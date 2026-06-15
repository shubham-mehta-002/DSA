#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int m, n;

public:
    bool find(int row, int col, int index, vector<vector<char>> &board, string word)
    {
        if (index == word.size())
            return true;

        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;

        if (board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = find(row + 1, col, index + 1, board, word) ||
                     find(row - 1, col, index + 1, board, word) ||
                     find(row, col + 1, index + 1, board, word) ||
                     find(row, col - 1, index + 1, board, word);

        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();

        bool found = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && !found)
                {
                    found |= find(i, j, 0, board, word);
                }
            }
        }
        return found;
    }
};