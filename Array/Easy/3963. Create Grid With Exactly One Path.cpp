#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        string temp(n, '#');
        vector<string> res(m, temp);

        int row = 0;
        int col = 0;

        while (col < n)
        {
            res[0][col] = '.';
            col++;
        }
        row++;

        while (row < m)
        {
            res[row][n - 1] = '.';
            row++;
        }
        return res;
    }
};