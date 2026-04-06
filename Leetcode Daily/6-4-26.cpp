#include <bits/stdc++.h>
using namespace std;

class Solution
{

    string convertToString(int i, int j)
    {
        return to_string(i) + "_" + to_string(j);
    }

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int res = 0;

        pair<int, int> dim = {0, 0};
        pair<int, int> dir = {0, 1}; // North

        unordered_map<string, int> obstr;
        for (auto o : obstacles)
        {
            obstr[convertToString(o[0], o[1])] = 1;
        }

        for (auto c : commands)
        {
            if (c == -1)
            {
                dir = {dir.second, -1 * dir.first};
            }
            else if (c == -2)
            {
                dir = {-1 * dir.second, dir.first};
            }
            else
            {
                for (int step = 0; step < c; step++)
                {
                    int newX = dim.first + dir.first;
                    int newY = dim.second + dir.second;

                    if (obstr.count(convertToString(newX, newY)))
                    {
                        break;
                    }
                    else
                    {
                        dim = {newX, newY};
                    }
                }
            }

            res = max(res, dim.first * dim.first + dim.second * dim.second);
        }

        return res;
    }
};