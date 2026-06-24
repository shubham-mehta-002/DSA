#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    void clone(Node *node, Node *newGraph, unordered_map<Node *, Node *> &mpp)
    {
        if (!node)
            return;

        for (Node *nbr : node->neighbors)
        {
            // check if nbr already mpp;
            if (mpp.find(nbr) != mpp.end())
            {
                (newGraph->neighbors).push_back(mpp[nbr]);
            }
            else
            {
                Node *newNode = new Node(nbr->val);
                (newGraph->neighbors).push_back(newNode);
                mpp[nbr] = newNode;
                clone(nbr, newNode, mpp);
            }
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mpp;
        if (!node)
            return nullptr;

        Node *newGraph = new Node(1);

        mpp[node] = newGraph;

        clone(node, newGraph, mpp);

        return newGraph;
    }
};