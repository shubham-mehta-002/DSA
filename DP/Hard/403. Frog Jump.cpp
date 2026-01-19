#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int>exists;
    // unordered_map<int,unordered_map<int,int>>dp;
public:
    // bool find(int value, int jump, vector<int>&stones){
    //     if(value == stones[stones.size()-1]){
    //         return true;
    //     }

    //     if(exists.count(value) == 0){
    //         return false;
    //     }

    //     if(dp.contains(value) && dp[value].contains(jump)){
    //         return dp[value][jump];
    //     }
    //     // k-1 jump
    //     if(jump > 1 && find(value+jump-1,jump-1,stones)){
    //         return dp[value][jump] = true;
    //     }

    //     // k jump
    //     if(find(value+jump, jump, stones)){
    //         return dp[value][jump] = true;
    //     }

    //     // k+1 jump
    //     if(find(value+jump+1,jump+1, stones)){
    //         return dp[value][jump] = true;
    //     }
    
    //     return dp[value][jump] = false;
    // }

    bool canCross(vector<int>& stones) {
        if(!(stones[1] == 1 && stones[0] == 0)){
            return false;
        }

        for(int s : stones){
            exists[s] = 1;
        }

        unordered_map<int, unordered_set<int>> dp;
        dp[stones[0]].insert(0);

       
        for(int i=0;i<stones.size();i++){
            for(int prevJump : dp[stones[i]]){
                if(prevJump > 1 && exists.count(stones[i] + prevJump - 1)){
                    dp[stones[i] + prevJump - 1].insert(prevJump-1);
                }
                if(exists.count(stones[i] + prevJump)) dp[stones[i] + prevJump].insert(prevJump);
                if(exists.count(stones[i] + prevJump+1)) dp[stones[i] + prevJump + 1].insert(prevJump+1);
            }
        }

        return dp[stones[stones.size()-1]].size() > 0;

       // return find(1,1,stones);
    }
};