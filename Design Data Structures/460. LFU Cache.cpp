#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k = 0, int v = 0, Node *p = NULL, Node *n = NULL)
    {
        key = k;
        val = v;
        prev = p;
        next = n;
    }
};

struct FreqMapNode
{
    Node *head;
    Node *tail;

    FreqMapNode(Node *head = NULL, Node *tail = NULL)
    {
        this->head = head;
        this->tail = tail;
    }
};

class LFUCache
{
    map<int, FreqMapNode *> freqMap;

    // key -> {frequency, Node*}
    unordered_map<int, pair<int, Node *>> mpp;

    int cap;
    int size;

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    void insertInFreq(int freq, Node *newNode)
    {

        if (freqMap.find(freq) == freqMap.end())
        {
            freqMap[freq] = new FreqMapNode();
        }

        FreqMapNode *freqNode = freqMap[freq];

        if (freqNode->tail == NULL)
        {
            freqNode->head = freqNode->tail = newNode;
        }
        else
        {
            freqNode->tail->next = newNode;
            newNode->prev = freqNode->tail;
            freqNode->tail = newNode;
        }
    }

    void removeFromCurrentFreq(int freq, int key)
    {

        Node *node = mpp[key].second;
        FreqMapNode *freqNode = freqMap[freq];

        // Only node in this frequency
        if (freqNode->head == node && freqNode->tail == node)
        {
            delete freqNode;
            freqMap.erase(freq);
            node->next = NULL;
            node->prev = NULL;
            return;
        }

        // Remove head
        if (node == freqNode->head)
        {
            freqNode->head = node->next;
        }

        // Remove tail
        if (node == freqNode->tail)
        {
            freqNode->tail = node->prev;
        }

        // Connect previous
        if (node->prev)
        {
            node->prev->next = node->next;
        }

        // Connect next
        if (node->next)
        {
            node->next->prev = node->prev;
        }

        node->prev = NULL;
        node->next = NULL;
    }

    int get(int key)
    {

        if (mpp.find(key) == mpp.end())
        {
            return -1;
        }

        Node *node = mpp[key].second;
        int freq = mpp[key].first;

        // Remove from old frequency
        removeFromCurrentFreq(freq, key);

        // Increase frequency
        mpp[key].first++;

        // Add to new frequency
        insertInFreq(freq + 1, node);

        return node->val;
    }

    void put(int key, int value)
    {

        // Update existing key
        if (mpp.find(key) != mpp.end())
        {

            Node *node = mpp[key].second;
            int freq = mpp[key].first;

            node->val = value;

            removeFromCurrentFreq(freq, key);

            mpp[key].first++;

            insertInFreq(freq + 1, node);

            return;
        }

        // Cache full
        if (size == cap)
        {

            // Minimum frequency
            int minFreq = freqMap.begin()->first;

            // Head = LRU
            Node *node = freqMap[minFreq]->head;

            int keyToDelete = node->key;

            // Remove from frequency list
            removeFromCurrentFreq(minFreq, keyToDelete);

            // Remove from hashmap
            mpp.erase(keyToDelete);

            // Delete actual node
            delete node;

            size--;
        }

        // Insert new node
        Node *newNode = new Node(key, value);

        // Add to hashmap
        mpp[key] = {1, newNode};

        // Add to frequency 1
        insertInFreq(1, newNode);

        size++;
    }
};