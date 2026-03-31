// ✅ Correct Time Complexity
// 🔹 findUltimateParent()
//     Amortized : O(α(n))
// 🔹 unionByRank()
//     Amortized : O(α(n))
// α(n) (inverse Ackermann function) is very small, it is not strictly constant

// But what is Ackermann function ? Ackermann function = a very fast - growing function
//                                                                         Grows faster than
// : exponential(2ⁿ)
//         factorial(n !)
//             even towers like 2 2 2 𝑛 2 2 2 n

// 👉 It becomes HUGE very quickly

// 🔁 So inverse Ackermann α(n) means :

// 👉 “How many steps to go backwards from a huge number to small
//     ?”

//     Since Ackermann grows insanely fast
//     :
// ➡️ Its inverse grows extremely slowly

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    // contructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // following 1-based indexing for ease
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v)
    {
        int parent_u = findUltimateParent(u);
        int parent_v = findUltimateParent(v);

        // if already in same component
        if (parent_u == parent_v)
        {
            return;
        }

        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else
        { // same rank
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};
