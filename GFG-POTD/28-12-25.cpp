//https://www.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1
#include<bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>,int> pp;

class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<ranks.size();i++){
            pq.push({{ranks[i],ranks[i]},ranks[i]}); // {{total time,next time to make},rank}
        }
        
        int count = 0;
        int maxTime = INT_MIN;
        while(count!=n){
            const pp &top = pq.top();
            int total = top.first.first;
            int next = top.first.second;
            int rank = top.second;
            maxTime = max(total,maxTime);
            
            pq.pop();
            count++;
            
            pq.push({{total+next+rank,next+rank},rank});
        }
        
        return maxTime;
        
    }
};