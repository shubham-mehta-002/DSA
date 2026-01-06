#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>s;
        vector<int>res(prices.size());

        for(int i=prices.size()-1 ; i>=0; i--){
            while(!s.empty() && s.top() > prices[i]){
                s.pop();
            }

            int val = prices[i];
            if(s.size()){
                val = val - s.top();
            }
            res[i] = val;
            s.push(prices[i]);
        }
        return res;
    }
};