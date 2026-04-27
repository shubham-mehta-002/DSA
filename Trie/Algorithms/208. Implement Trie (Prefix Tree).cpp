#include <bits/stdc++.h>
using namespace std;

struct Node
{
    vector<Node *> links;
    bool flag; // denotes the end of the word

    Node()
    {
        links = vector<Node *>(26, nullptr);
        flag = false;
    }

    bool containsKey(char c)
    {
        return links[c - 'a'] != nullptr;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *curr = root;
        for (char c : word)
        {
            if (!curr->containsKey(c))
            {
                curr->put(c, new Node());
            }
            // move to next link
            curr = curr->get(c);
        }

        curr->setEnd();
    }

    bool search(string word)
    {
        Node *curr = root;
        for (char c : word)
        {
            if (!curr->containsKey(c))
            {
                return false;
            }
            curr = curr->get(c);
        }

        return curr->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        for (char c : prefix)
        {
            if (!curr->containsKey(c))
            {
                return false;
            }
            curr = curr->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */