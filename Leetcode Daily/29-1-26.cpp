#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<pair<int,int>>>m;
    unordered_map<char, unordered_map<char,int>>mem;
public:
    int findMinCostToConvert2(char source, char target,unordered_set<char>&vis){
        if(mem.find(source) != mem.end() && mem[source].find(target)!=mem[source].end()){
            return mem[source][target];
        }

        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>>pq;
        pq.push({0,source});
        vector<int>cost(26,INT_MAX);
        cost[source-'a'] = 0;

        while(!pq.empty()){
            auto [currCost,node] = pq.top();
            pq.pop();
            for(auto t : m[node]){
                auto [ch, dist] = t;
                int newCost = dist + currCost;
                if(newCost < cost[ch-'a']){
                    cost[ch-'a'] = newCost;
                    pq.push({newCost, ch});
                }
            }
        }

        return mem[source][target] = cost[target-'a'];
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i=0;i<original.size();i++){
            if(m.find(original[i]) == m.end()){
                vector<pair<int,int>> temp;
                m[original[i]] = temp;
            }
            m[original[i]].push_back({changed[i],cost[i]});
        }

        // set to prevent infinite loops 
        unordered_set<char> vis;

    
        long long totalCost = 0;
        for(int i=0;i<source.size();i++){
            if(source[i] == target[i]){
                continue;
            }

            int minCost = findMinCostToConvert2(source[i], target[i],vis);
            cout << minCost <<" ";
            if(minCost == INT_MAX){
                return -1;
            }

            totalCost += minCost;
        }    

        return totalCost;    
    }
};


