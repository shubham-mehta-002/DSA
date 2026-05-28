#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    // bool end;
    int idx;

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        // end = false;
        idx = -1;
    }

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    Node *get(char ch) { return links[ch - 'a']; }

    void set(char ch, Node *newNode) { links[ch - 'a'] = newNode; }

    int getIndex() { return idx; }

    void setIndex(int idx) { this->idx = idx; }

    // bool getEnd(){
    //     return end;
    // }

    // void setEnd(){
    //     end = true;
    // }

    ~Node()
    {
        for (int i = 0; i < 26; i++)
        {
            delete links[i];
            links[i] = nullptr;
        }
    }
};

class Trie
{
    Node *root = nullptr;

public:
    int maxxInsertionsNeeded = 0;
    Trie() { root = new Node(); }

    bool better(int newIdx, int oldIdx, vector<string> &wordsContainer)
    {
        if (oldIdx == -1)
            return true;
        if (wordsContainer[newIdx].size() < wordsContainer[oldIdx].size())
            return true;
        if (wordsContainer[newIdx].size() == wordsContainer[oldIdx].size() &&
            newIdx < oldIdx)
            return true;
        return false;
    }

    void insert(string &word, int idx, vector<string> &wordsContainer)
    {
        if (better(idx, root->getIndex(), wordsContainer))
        {
            root->setIndex(idx);
        }

        int n = word.size();
        Node *curr = root;

        for (int i = n - 1; i >= max(0, n - maxxInsertionsNeeded - 1); i--)
        {
            if (!curr->containsKey(word[i]))
            {
                curr->set(word[i], new Node());
            }
            curr = curr->get(word[i]);

            // setting index for smallest string with that prefix;
            if (better(idx, curr->getIndex(), wordsContainer))
            {
                curr->setIndex(idx);
            }
        }

        // curr->setEnd();
    }

    int longestCommonSuffixIndex(string &word)
    {
        Node *curr = root;

        int n = word.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (curr->containsKey(word[i]))
            {
                curr = curr->get(word[i]);
            }
            else
            {
                break;
            }
        }
        return curr->getIndex();
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer,
                              vector<string> &wordsQuery)
    {
        Trie *trie = new Trie();
        int n = wordsContainer.size();

        // (optimization) need for removing the MLE error
        int maxx = 0;
        for (string &word : wordsQuery)
        {
            maxx = max(maxx, (int)word.size());
        }
        trie->maxxInsertionsNeeded = maxx;

        for (int i = 0; i < n; i++)
        {
            trie->insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> res;
        for (int i = 0; i < wordsQuery.size(); i++)
        {
            res.push_back(trie->longestCommonSuffixIndex(wordsQuery[i]));
        }

        return res;
    }
};
