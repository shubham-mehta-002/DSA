#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxElement(vector<int> &nums, unordered_map<int, vector<int>> &mpp)
    {
        int maxx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]].push_back(i);
            maxx = max(maxx, nums[i]);
        }

        return maxx;
    }
    void markIsPrime(vector<int> &isPrime, int maxEl, vector<unordered_set<int>> &adj)
    {
        isPrime[0] = 0;
        isPrime[1] = 0;

        for (int i = 2; i * i <= maxEl; i++)
        {
            if (isPrime[i] == 0)
                continue;

            for (int j = i * 2; j <= maxEl; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    int minJumps(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, vector<int>> mpp;
        int maxEl = getMaxElement(nums, mpp);

        vector<unordered_set<int>> adj(n);
        vector<int> isPrime(maxEl + 1, 1);

        markIsPrime(isPrime, maxEl, adj);

        // to avoid repeating the same iterations loop for primes with same values
        unordered_set<int> seenPrimes;

        // BFS
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int jumps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int top = q.front();
                q.pop();

                if (top == adj.size() - 1)
                {
                    return jumps;
                }

                // primes
                if (isPrime[nums[top]] && seenPrimes.find(nums[top]) == seenPrimes.end())
                {
                    for (int j = nums[top]; j <= maxEl; j += nums[top])
                    {
                        if (mpp.find(j) != mpp.end())
                        {
                            for (int idx : mpp[j])
                            {
                                if (!vis[idx])
                                {
                                    vis[idx] = 1;
                                    q.push(idx);
                                }
                            }
                        }
                    }

                    seenPrimes.insert(nums[top]);
                }

                // primes + non-primes
                if (top > 0)
                {
                    if (!vis[top - 1])
                    {
                        vis[top - 1] = 1;
                        q.push(top - 1);
                    }
                }

                if (top < adj.size() - 1)
                {
                    if (!vis[top + 1])
                    {
                        vis[top + 1] = 1;
                        q.push(top + 1);
                    }
                }
            }

            jumps++;
        }

        return jumps;
    }
};