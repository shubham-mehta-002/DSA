#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
    void buildPrefixSum(vector<ll> &prefixSum, vector<int> &t)
    {
        ll sum = 0;
        for (int i = 0; i < t.size(); i++)
        {
            sum += t[i];
            prefixSum[i] = sum;
        }
    }

public:
    ll getSum(vector<int> &nums)
    {
        vector<int> t;
        t.push_back(0);
        for (int n : nums)
        {
            t.push_back(n);
            t.push_back(0);
        }

        int n = t.size();
        vector<ll> prefixSum(n, 0);
        buildPrefixSum(prefixSum, t);

        ll maxSum = 0;

        vector<int> p(n, 0);

        int right = 0;
        int center = 0;

        for (int index = 0; index < n; index++)
        {
            int mirror = 2 * center - index;

            if (index < right)
            {
                p[index] = min(p[mirror], right - index);
            }

            int a = index + p[index] + 1;
            int b = index - p[index] - 1;

            while (b >= 0 && a < n && t[a] == t[b])
            {
                a++;
                b--;
                p[index]++;
            }

            if (index + p[index] > right)
            {
                right = index + p[index];
                center = index;
            }

            if (index - p[index] - 1 >= 0)
            {
                maxSum = max(maxSum, prefixSum[index + p[index]] - prefixSum[index - p[index] - 1]);
            }
            else
            {
                maxSum = max(maxSum, prefixSum[index + p[index]]);
            }
        }
        return maxSum;
    }
};