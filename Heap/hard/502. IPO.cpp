#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();

        vector<pp> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back({capital[i], profits[i]});
        }

        sort(temp.begin(), temp.end(), [](const pp &a, const pp &b)
             {
            if(a.first == b.first){
                return a.second > b.first;
            }
            return a.first < b.first; });

        if (temp[0].first > w)
        {
            return w;
        }

        priority_queue<int> pq;

        int i = 0;
        int currCap = w;
        k = min(n, k);

        while (k--)
        {
            while (i < n && currCap >= temp[i].first)
            {
                pq.push(temp[i].second);
                i++;
            }

            if (pq.empty())
                break;

            int top = pq.top();
            pq.pop();

            currCap += top;
        }

        return currCap;
    }
};