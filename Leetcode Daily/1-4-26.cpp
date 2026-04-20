#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        using pp = pair<int, int>;

        int n = positions.size();

        unordered_map<int, pp> mpp;
        vector<pp> robos;

        for (int i = 0; i < n; i++)
        {
            robos.push_back({positions[i], healths[i]});            // {position, health}
            mpp[positions[i]] = {i, directions[i] == 'L' ? -1 : 1}; // position -> {index, direction}
        }

        sort(robos.begin(), robos.end(), [](const pp &a, const pp &b)
             { return a.first < b.first; });

        stack<pp> st;

        for (int i = 0; i < n; i++)
        {
            bool pushtoStack = true;

            while (!st.empty() && (mpp[st.top().first].second == 1 && mpp[robos[i].first].second == -1))
            {
                int &health1 = st.top().second;
                int &health2 = robos[i].second;

                // health equal -> remove both
                if (health1 == health2)
                {
                    st.pop();
                    pushtoStack = false;
                    break;
                }
                else if (health1 > health2)
                {
                    health1--;
                    pushtoStack = false;
                    break;
                }
                else
                {
                    health2--;
                    st.pop();
                }
            }

            if (pushtoStack)
                st.push(robos[i]);
        }

        vector<pp> temp;
        while (!st.empty())
        {
            temp.push_back({mpp[st.top().first].first, st.top().second});
            st.pop();
        }

        sort(temp.begin(), temp.end());

        vector<int> res;
        for (pp &t : temp)
        {
            res.push_back(t.second);
        }

        return res;
    }
};