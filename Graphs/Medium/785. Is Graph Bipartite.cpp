#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> m; // 1->Set1; 2->set2
public:
    bool find(vector<vector<int>>& graph, int start) {
        queue<pair<int,int>>q;
        q.push({start,-1});
        m[start] = 1;

        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();

            for(int adj : graph[node]){
                if(adj != node){
                    int set = (m[node] == 1 ? 2 : 1);
                    if(m[adj] != 0 && m[adj] != set){
                        return false;
                    }
                    if(m[adj] == 0) q.push({adj,node});
                    m[adj] = set;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph){
        int n =  graph.size();
        for(int i=0;i<n;i++){
            if(m[i] == 0){
                if(!find(graph,i)){
                    return false;
                }
            }
        }

        return true;
    }
};




// DFS
class Solution {
public:
    bool find(vector<vector<int>>& graph, int start,int set,vector<int>&vis){
        if(vis[start] != -1 && vis[start] != set){
            return false;
        }
        vis[start] = set;
        int other = (set==1 ? 2 :1);

        for(int adj : graph[start]){
            if(vis[adj] == -1){
                if(!find(graph,adj,other,vis)){
                    return false;
                }
            }

            if(vis[adj] != other){
                return false;
            }
    
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i] == -1 && !find(graph,i,1,vis)){
                return false;
            }
        }
        return true;
    }
};