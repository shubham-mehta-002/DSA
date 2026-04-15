#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]].push_back(i);
        }

        vector<int> res;
        for (int q : queries)
        {
            int key = nums[q];

            auto &temp = mpp[key];

            if (temp.size() == 1)
            {
                res.push_back(-1);
                continue;
            }

            int idx = -1;
            int l = 0;
            int h = mpp[key].size() - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (temp[mid] == q)
                {
                    idx = mid;
                    break;
                }
                else if (temp[mid] > q)
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            int minn = INT_MAX;

            if (idx > 0)
            {
                minn = min(minn, q - temp[idx - 1]);
            }
            else
            {
                minn = min(minn, q - temp[temp.size() - 1] + n);
            }

            if (idx < temp.size() - 1)
            {
                minn = min(minn, temp[idx + 1] - q);
            }
            else
            {
                minn = min(minn, temp[0] - q + n);
            }

            res.push_back(minn);
        }
        return res;
    }
};