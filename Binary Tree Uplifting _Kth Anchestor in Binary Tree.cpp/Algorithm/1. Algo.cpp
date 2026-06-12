#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
    vector<vector<int>> ancestorTable;
    int rows;
    int cols;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        rows = n;
        cols = log2(n) + 1;

        ancestorTable.resize(rows, vector<int>(cols, -1));

        // fill the 0th column first- immediate parent(ancestor)
        for (int node = 0; node < n; node++)
        {
            ancestorTable[node][0] = parent[node]; // here 0 means 2^0 = 1 jump
        }

        for (int j = 1; j < cols; j++)
        {
            for (int node = 0; node < n; node++)
            {
                if (ancestorTable[node][j - 1] != -1)
                {
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < cols; j++)
        {
            if (k & (1 << j))
            {
                node = ancestorTable[node][j];
                if (node == -1)
                {
                    return -1;
                }
            }
        }

        return node;
    }
};
