#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_set<int> colUsed;
    unordered_set<int> diag1Used; // ..\..
    unordered_set<int> diag2Used; // ../..
    int size;

public:
    bool isValid(int row, int col)
    {
        if (colUsed.find(col) != colUsed.end())
            return false;
        if (diag1Used.find(row + col) != diag1Used.end(row + col))
            return false;
        if (diag2Used.find(row - col) != diag2Used.end(row - col))
            return false;
        return true;
    }

    int find(int row)
    {
        if (row == size)
        {
            return 1;
        }

        int ans = 0;
        for (int col = 0; col < size; col++)
        {
            if (isValid(row, col))
            {
                colUsed.insert(col);
                diag1Used.insert(row + col);
                diag2Used.insert(row - col);

                ans += find(row + 1);

                colUsed.erase(col);
                diag1Used.erase(row + col);
                diag2Used.erase(row - col);
            }
        }

        return ans;
    }

    int totalNQueens(int n)
    {
        size = n;
        return find(0);
    }
};