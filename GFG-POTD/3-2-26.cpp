#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = INT_MIN;
        int maxVal = prices[prices.size()-1];
        
        for(int i=prices.size()-1; i>=0 ; i--){
            maxVal = max(maxVal , prices[i]);
            
            maxProfit = max(maxProfit, maxVal - prices[i]);
        }
        
        return maxProfit;
        
    }
};
