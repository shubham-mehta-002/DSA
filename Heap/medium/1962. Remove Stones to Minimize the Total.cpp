#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;

        int total = 0;
        for (int p : piles)
        {
            pq.push(p);
            total += p;
        }

        while (k--)
        {
            int topp = pq.top();
            pq.pop();
            int removed = topp / 2;
            total -= removed;
            pq.push(topp - removed);
        }
        return total;
    }
};