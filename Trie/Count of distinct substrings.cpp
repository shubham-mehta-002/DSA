#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26] = {nullptr};
    bool flag;

    Node()
    {
        flag = false;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    bool setKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
    Node *root;
    int nodesCount;

public:
    Trie()
    {
        root = new Node();
        nodesCount = 0;
    }

    void insert(string &str)
    {

        Node *crawler = root;
        for (char ch : str)
        {
            if (!crawler->containsKey(ch))
            {
                crawler->setKey(ch, new Node());
                nodesCount++;
            }

            crawler = crawler->getKey(ch);
        }

        crawler->setEnd();
    }

    int getNodesCount()
    {
        return nodesCount;
    }
};

class Solution
{
public:
    int countSubs(string &s)
    {
        int n = s.size();
        Trie *trie = new Trie();

        for (int i = 0; i < n; i++)
        {
            string str = "";
            for (int j = i; j < n; j++)
            {
                str.push_back(s[j]);
                trie->insert(str);
            }
        }

        return trie->getNodesCount();
    }
};