#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2] = {nullptr};
    Node() {}

    bool containsKey(int key)
    {
        return links[key] != nullptr;
    }

    void setKey(int key, Node *node)
    {
        links[key] = node;
    }

    Node *getKey(int key)
    {
        return links[key];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *crawler = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!crawler->containsKey(bit))
            {
                crawler->setKey(bit, new Node());
            }
            crawler = crawler->getKey(bit);
        }
    }

    int getMaxXOR(int n)
    {
        int ans = 0;
        Node *crawler = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (crawler->containsKey(!bit))
            {
                crawler = crawler->getKey(!bit);
                ans = (ans << 1) | 1;
            }
            else
            {
                crawler = crawler->getKey(bit);
                ans = (ans << 1);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int ans = 0;
        Trie *trie = new Trie();

        for (int n : nums)
        {
            trie->insert(n);
        }

        for (int n : nums)
        {
            ans = max(
                ans,
                trie->getMaxXOR(n));
        }

        return ans;
    }
};