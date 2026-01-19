#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<int>l(leaves+1,-1);
        int visitedCount = 0;
        
        for(int i=0; i<N;i++){
            int val = frogs[i];
            
            if(val == 1)    return 0;
            
            if(val > leaves || l[val] == 1) continue;
            
            while(val <= leaves){
                if(l[val] == -1)    visitedCount++;
                l[val] = 1;
                val += frogs[i];
            }
        }
        
        
        return leaves-visitedCount;
    }
};
