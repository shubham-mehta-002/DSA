#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        stack<int> st;

        // {position, {direction, {health, original_index}}}
        using pp = pair<int, pair<char, pair<int, int>>>;
        vector<pp> robots;

        // Build robots with original index
        for (int i = 0; i < n; i++)
        {
            robots.push_back({positions[i], {directions[i], {healths[i], i}}});
        }

        // Sort by position
        sort(robots.begin(), robots.end());

        // Process collisions
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() &&
                   robots[st.top()].second.first == 'R' &&
                   robots[i].second.first == 'L')
            {

                int topIdx = st.top();

                int &topHealth = robots[topIdx].second.second.first;
                int &currHealth = robots[i].second.second.first;

                if (topHealth == currHealth)
                {
                    st.pop();
                    currHealth = 0;
                    break;
                }
                else if (topHealth > currHealth)
                {
                    topHealth--;
                    currHealth = 0;
                    break;
                }
                else
                {
                    st.pop();
                    currHealth--;
                }
            }

            // If current robot is still alive, push to stack
            if (robots[i].second.second.first > 0)
            {
                st.push(i);
            }
        }

        // Store results in original order
        vector<int> ans(n, -1);

        while (!st.empty())
        {
            int idx = st.top();
            st.pop();

            int originalIndex = robots[idx].second.second.second;
            int health = robots[idx].second.second.first;

            ans[originalIndex] = health;
        }

        // Build final result in input order
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != -1)
            {
                res.push_back(ans[i]);
            }
        }

        return res;
    }
};