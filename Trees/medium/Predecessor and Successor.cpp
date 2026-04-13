#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *findPred(Node *root)
    {
        while (root && root->right)
        {
            root = root->right;
        }
        return root;
    }

    Node *findSucc(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pred = NULL;
        Node *succ = NULL;

        Node *curr = root;
        while (curr)
        {
            if (curr->data < key)
            {
                pred = curr;
                curr = curr->right;
            }
            else if (curr->data > key)
            {
                succ = curr;
                curr = curr->left;
            }
            else
            {
                pred = curr->left ? findPred(curr->left) : pred;
                succ = curr->right ? findSucc(curr->right) : succ;
                break;
            }
        }

        return {pred, succ};
    }
};