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
        left = right = NULL;
    }
};

class Solution
{
    int count = 0;
    unordered_map<int, int> prefixSum;

public:
    void traverse(Node *root, int k, int currentSum)
    {
        if (!root)
            return;

        currentSum += (root->data);

        if (currentSum == k)
        {
            count++;
        }

        if (prefixSum.find(currentSum - k) != prefixSum.end())
        {
            count += prefixSum[currentSum - k];
        }

        prefixSum[currentSum]++;

        traverse(root->left, k, currentSum);
        traverse(root->right, k, currentSum);

        prefixSum[currentSum]--;
        if (prefixSum[currentSum] == 0)
        {
            prefixSum.erase(currentSum);
        }
    }

    int countAllPaths(Node *root, int k)
    {

        traverse(root, k, 0);

        return count;
    }
};