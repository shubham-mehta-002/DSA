#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int cnt = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == 1)
            {
                cnt += (high - mid + 1);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return cnt;
    }

    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int maxx = 0;
        int index = -1;
        int n = arr.size();

        for (int row = 0; row < n; row++)
        {
            int cnt = find(arr[row]);
            if (maxx < cnt)
            {
                maxx = max(maxx, cnt);
                index = row;
            }
        }

        return index;
    }
};