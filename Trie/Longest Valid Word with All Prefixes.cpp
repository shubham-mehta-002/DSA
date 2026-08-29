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

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &str)
    {
        Node *crawler = root;
        for (char ch : str)
        {
            if (!crawler->containsKey(ch))
            {
                crawler->setKey(ch, new Node());
            }

            crawler = crawler->getKey(ch);
        }

        crawler->setEnd();
    }

    bool isValidWord(string &str)
    {
        Node *crawler = root;
        for (char ch : str)
        {
            crawler = crawler->getKey(ch);
            if (!crawler->isEnd())
            {
                return false;
            }
        }

        return true;
    }
};

class Solution
{
public:
    string longestValidWord(vector<string> &words)
    {
        Trie *trie = new Trie();

        for (string &str : words)
        {
            trie->insert(str);
        }

        string maxx = "";

        for (string &str : words)
        {
            bool ans = trie->isValidWord(str);
            if (ans)
            {
                if (str.size() > maxx.size())
                {
                    maxx = str;
                }
                else if (str.size() == maxx.size())
                {
                    maxx = min(maxx, str);
                }
            }
        }

        return maxx;
    }
};
