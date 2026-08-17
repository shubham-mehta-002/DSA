#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;

    Node(int k = 0, int v = 0, Node *n = NULL)
    {
        this->key = k;
        this->val = v;
        this->next = n;
    }
};

class MyHashMap
{
    vector<Node *> map;
    const int size = 1e4 + 1;

    int hash(int key)
    {
        return key % size;
    }

public:
    MyHashMap()
    {
        map.resize(size, NULL);
    }

    void put(int key, int value)
    {
        int index = hash(key);

        // Reference to the actual head pointer
        Node *&head = map[index];

        // Check if key already exists
        Node *temp = head;

        while (temp)
        {

            if (temp->key == key)
            {

                // Update existing value
                temp->val = value;

                return;
            }

            temp = temp->next;
        }

        // Key doesn't exist
        // Insert new node at head

        Node *newNode = new Node(key, value);

        newNode->next = head;

        head = newNode;
    }

    int get(int key)
    {

        int index = hash(key);

        Node *head = map[index];

        while (head)
        {

            if (head->key == key)
            {
                return head->val;
            }

            head = head->next;
        }

        return -1;
    }

    void remove(int key)
    {

        int index = hash(key);

        // Reference to actual head pointer
        Node *&head = map[index];

        Node *temp = head;
        Node *prev = NULL;

        while (temp)
        {

            // Key found
            if (temp->key == key)
            {

                // Remove head
                if (prev == NULL)
                {
                    head = temp->next;
                }

                // Remove middle or tail
                else
                {
                    prev->next = temp->next;
                }

                delete temp;

                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }
};