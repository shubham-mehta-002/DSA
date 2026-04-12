// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
//     using pp = pair<int, int>;
//     pp getCoordinates(char c)
//     {
//         int num = c - 'A';

//         int row = num / 6;
//         int col = num % 6;

//         return {row, col};
//     }

//     int getCost(char a, char b)
//     {
//         if (a == '0')
//             return 0;

//         auto p1 = getCoordinates(a);
//         auto p2 = getCoordinates(b);
//         return abs(p1.first - p2.first) + abs(p1.second - p2.second);
//     }
//     string getKey(int index, char a, char b)
//     {
//         return (to_string(index) + "_" + to_string(a) + "_" + to_string(b));
//     }
//     int find(int index, string &word, char left, char right, unordered_map<string, int> &mem)
//     {
//         // base case
//         if (index == word.size())
//         {
//             return 0;
//         }

//         string key = getKey(index, left, right);

//         if (mem.find(key) != mem.end())
//         {
//             return mem[key];
//         }
//         int minCost = INT_MAX;

//         // left finger
//         int currentCost = getCost(left, word[index]);
//         minCost = min(minCost, currentCost + find(index + 1, word, word[index], right, mem));

//         // right finger
//         currentCost = getCost(right, word[index]);
//         minCost = min(minCost, currentCost + find(index + 1, word, left, word[index], mem));

//         return mem[key] = minCost;
//     }

// public:
//     int minimumDistance(string word)
//     {
//         unordered_map<string, int> mem;
//         return find(0, word, '0', '0', mem);
//         char left = '0';
//         char right = '0';

//         int n = word.size();

//         for (int index = 1; index < n; index++)
//         {

//             string key = getKey(index, left, right);
//             int minCost = INT_MAX;

//             // left finger
//             int currentCost = getCost(left, word[index]);
//             minCost = min(minCost, currentCost + mem(getKey(index - 1, word[index], right)));

//             // right finger
//             int currentCost = getCost(right, word[index]);
//             minCost = min(minCost, currentCost + mem(getKey(index - 1, left, word[index])));

//             mem[key] = minCost;
//         }
//     }
// };