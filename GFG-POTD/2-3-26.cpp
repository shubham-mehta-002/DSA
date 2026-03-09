#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void largestElementToLeft(vector<int> &height, vector<int> &left)
    {
        int n = height.size();

        int maxVal = height[0];
        for (int i = 1; i < n; i++)
        {
            if (height[i] > maxVal)
            {
                maxVal = height[i];
            }

            left[i] = maxVal;
        }
    }

    void largestElementToRight(vector<int> &height, vector<int> &right)
    {
        int n = height.size();

        int maxVal = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (height[i] > maxVal)
            {
                maxVal = height[i];
            }

            right[i] = maxVal;
        }
    }
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        largestElementToLeft(height, left);
        largestElementToRight(height, right);

        int waterTrapped = 0;
        for (int i = 0; i < n; i++)
        {
            if (left[i] == -1 || right[i] == -1)
            {
                waterTrapped += 0;
            }
            else
            {
                waterTrapped += (min(left[i], right[i]) - height[i]);
            }
        }

        return waterTrapped;
    }
};