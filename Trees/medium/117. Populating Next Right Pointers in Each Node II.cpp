#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        Node *head = root;

        while (head)
        {
            Node *dummy = new Node(-1);
            Node *temp = dummy;

            while (head)
            {
                if (head->left)
                {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if (head->right)
                {
                    temp->next = head->right;
                    temp = temp->next;
                }

                head = head->next;
            }

            head = dummy->next;
        }

        return root;
    }
};