#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k = 0, int v = 0, Node *p = nullptr, Node *n = nullptr)
    {
        key = k;
        value = v;
        prev = p;
        next = n;
    }
};
class LRUCache
{
    int capacity;
    unordered_map<int, Node *> mpp;
    Node *head = NULL, *tail = NULL;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    void deleteNodeAndAddToEnd(int key)
    {
        Node *node = mpp[key];
        if (node == tail)
        {
            return;
        }

        if (node->prev)
        {
            node->prev->next = node->next;
        }
        if (node->next)
        {
            node->next->prev = node->prev;
        }

        if (node == head)
        {
            head = head->next;
        }

        node->next = NULL;

        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
        {
            return -1;
        }

        deleteNodeAndAddToEnd(key);
        return mpp[key]->value;
    }

    void put(int key, int value)
    {
        // update
        if (mpp.find(key) != mpp.end())
        {
            deleteNodeAndAddToEnd(key);
            mpp[key]->value = value;
            return;
        }
        else
        {
            // add

            // enough capacity ?
            if (capacity == 0)
            {
                // remove LRU from map
                mpp.erase(head->key);

                // delete the node
                Node *node = head;

                if (head == tail)
                {
                    head = tail = NULL;
                }
                else
                {
                    node->next->prev = NULL;
                    head = head->next;
                }

                delete node;
                capacity++;
            }

            Node *newNode = new Node(key, value);
            if (tail == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            mpp[key] = newNode;
            capacity--;
        }
    }
};
