#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        map<int, vector<int>> mpp;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [top, index] = q.front();

                mpp[index].push_back(top->data);

                if (top->left)
                    q.push({top->left, index - 1});
                if (top->right)
                    q.push({top->right, index + 1});
                q.pop();
            }
        }

        for (auto it : mpp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};