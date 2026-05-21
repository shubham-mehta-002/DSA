#include <bits/stdc++.h>
using namespace std;

class Node
{
    bool end;
    vector<Node *> links;

public:
    Node()
    {
        links = vector<Node *>(10, nullptr);
        end = false;
    }

    bool containsKey(char ch)
    {
        return (links[ch - '0'] != nullptr);
    }

    Node *get(char ch)
    {
        return links[ch - '0'];
    }

    void set(char ch, Node *newNode)
    {
        links[ch - '0'] = newNode;
    }

    void setEnd()
    {
        end = true;
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

    void insert(string num)
    {
        Node *curr = root;

        for (char c : num)
        {
            if (!curr->containsKey(c))
            {
                curr->set(c, new Node());
            }
            curr = curr->get(c);
        }

        curr->setEnd();
    }

    int getMaxPrefixLength(string str)
    {
        Node *curr = root;
        int cnt = 0;

        for (char ch : str)
        {
            if (curr->containsKey(ch))
            {
                cnt++;
                curr = curr->get(ch);
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie *trie = new Trie();

        for (int a : arr1)
        {
            trie->insert(to_string(a));
        }

        int maxx = 0;
        for (int a : arr2)
        {
            maxx = max(maxx, trie->getMaxPrefixLength(to_string(a)));
        }
        return maxx;
    }
};