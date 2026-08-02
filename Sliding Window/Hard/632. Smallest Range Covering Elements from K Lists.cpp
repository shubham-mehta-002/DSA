#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pp;
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        int maxElement = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i][0], {i, 0}});
            maxElement = max(maxElement, nums[i][0]);
        }

        int r1 = -1;
        int r2 = -1;

        int range = INT_MAX;

        while (true)
        {
            const pp &minElement = pq.top();
            auto [val, dim] = minElement;
            auto [row, index] = dim;

            pq.pop();

            if (maxElement - val < range)
            {
                range = maxElement - val;
                r1 = val;
                r2 = maxElement;
            }

            if (index + 1 == nums[row].size())
            {
                break;
            }
            pq.push({nums[row][index + 1], {row, index + 1}});
            maxElement = max(maxElement, nums[row][index + 1]);
        }

        return {r1, r2};
    }
};