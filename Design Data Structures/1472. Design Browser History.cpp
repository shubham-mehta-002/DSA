#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string val;
    Node *next;
    Node *prev;

    Node(string val = "", Node *prev = nullptr, Node *next = nullptr)
    {
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};
class BrowserHistory
{
public:
    Node *current = NULL;

    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    string back(int steps)
    {
        while (steps && current->prev != NULL)
        {
            current = current->prev;
            steps--;
        }
        return current->val;
    }

    string forward(int steps)
    {
        while (steps && current->next)
        {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */