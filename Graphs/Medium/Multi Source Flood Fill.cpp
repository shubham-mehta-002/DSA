#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        using pp = pair<int,pair<int,int>>;
        vector<vector<int>>res(n,vector<int>(m,0));
        
        queue<pp>q;

        for(auto s : sources){
            q.push({s[2],{s[0],s[1]}});
            res[s[0]][s[1]] = s[2];
        }

        while(!q.empty()){
            map<pair<int,int>, int>mpp;
            int size = q.size();
            while(size--){
                int color = q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                q.pop();

                for(int i=0;i<4;i++){
                    int new_r = r + dx[i];
                    int new_c = c + dy[i];

                    if(new_r >=0 && new_c >=0 && new_r < n && new_c < m && !res[new_r][new_c]){
                        mpp[{new_r,new_c}] = max(mpp[{new_r,new_c}] , color);
                    }
                }
            }


            for(auto it = mpp.begin(); it != mpp.end(); it++){
                res[it->first.first][it->first.second] = it->second; 
                q.push({it->second, {it->first.first,it->first.second}});   
            }
        }

        return res;
    }
};