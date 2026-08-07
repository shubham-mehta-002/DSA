#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>res;
public:
    int dfs(int node, unordered_map<int, vector<int>>&mpp, vector<int>&quiet){
        int minn = node;

        for(auto nbr : mpp[node]){
            if(res[nbr] != -1){
                if(quiet[res[nbr]] < quiet[minn]){
                    minn = res[nbr];
                }
            }else{
                int ans = dfs(nbr,mpp,quiet);
                if(quiet[ans] < quiet[minn]){
                    minn = ans;
                }
            }
        }

        return res[node] = minn;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>>mpp;
        for(auto r : richer){
            mpp[r[1]].push_back(r[0]);
        }

        res.resize(n,-1);

        for(int i=0;i<n;i++){
            if(res[i] == -1){
                res[i] = dfs(i,mpp,quiet);
            }
        }

        return res;
    }
};