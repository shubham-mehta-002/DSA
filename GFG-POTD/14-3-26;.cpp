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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        map<int, int> mpp;

        queue<pair<Node *, int>> level;
        level.push({root, 0});

        while (!level.empty())
        {
            int size = level.size();
            while (size--)
            {
                Node *top = level.front().first;
                int index = level.front().second;

                if (mpp.find(index) == mpp.end())
                {
                    mpp[index] = top->data;
                }

                if (top->left)
                    level.push({top->left, index - 1});
                if (top->right)
                    level.push({top->right, index + 1});

                level.pop();
            }
        }

        for (auto it : mpp)
        {
            res.push_back(it.second);
        }

        return res;
    }
};