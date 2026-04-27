#include <bits/stdc++.h>
using namespace std;

struct Node
{
private:
    vector<Node *> links = vector<Node *>(26, NULL);
    int endsWithCount = 0;
    int prefixCount = 0;

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *newLink)
    {
        links[ch - 'a'] = newLink;
    }

    void increasePrefix()
    {
        prefixCount++;
    }

    void decreasePrefix()
    {
        prefixCount--;
    }

    void increaseEnd()
    {
        endsWithCount++;
    }

    void decreaseCount()
    {
        endsWithCount--;
    }

    int getEndsWithCount()
    {
        return endsWithCount;
    }

    int getPrefixCount()
    {
        return prefixCount;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            if (!curr->containsKey(ch))
            {
                curr->put(ch, new Node());
            }
            curr = curr->get(ch);
            curr->increasePrefix();
        }

        curr->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            if (!curr->containsKey(ch))
            {
                return 0;
            }

            curr = curr->get(ch);
        }

        return curr->getEndsWithCount();
    }

    int countWordsStartingWith(string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            if (!curr->containsKey(ch))
            {
                return 0;
            }

            curr = curr->get(ch);
        }

        return curr->getPrefixCount();
    }

    void erase(string &word)
    {
        Node *curr = root;
        for (char ch : word)
        {
            if (!curr->containsKey(ch))
            {
                return;
            }

            curr = curr->get(ch);
            curr->decreasePrefix();
        }

        curr->decreaseCount();
    }
};
