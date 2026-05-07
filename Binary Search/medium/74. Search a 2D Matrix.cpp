#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rows, cols;

public:
    int getVal(int index, vector<vector<int>> &matrix)
    {
        return matrix[index / cols][index % cols];
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        rows = matrix.size();
        cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int val = getVal(mid, matrix);

            if (val == target)
            {
                return true;
            }
            else if (val > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};