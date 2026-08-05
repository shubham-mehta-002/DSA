class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {

        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> mpp;
        for (auto i : invocations)
        {
            inDegree[i[1]]++;
            mpp[i[0]].push_back(i[1]);
        }

        vector<int> isSuspicious(n, 0);

        queue<int> q;
        q.push(k);
        isSuspicious[k] = 1;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto nbr : mpp[top])
            {
                inDegree[nbr]--;

                if (!isSuspicious[nbr])
                {
                    isSuspicious[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        vector<int> res;
        bool canBeRemoved = true;
        for (int i = 0; i < n; i++)
        {
            if (isSuspicious[i] && inDegree[i] > 0)
            {
                canBeRemoved = false;
                break;
            }
            if (!isSuspicious[i])
                res.push_back(i);
        }

        if (!canBeRemoved)
        {
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        return res;
    }
};