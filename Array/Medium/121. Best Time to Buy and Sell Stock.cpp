#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int maxVal = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxProfit = max(maxProfit , maxVal - prices[i]);
            maxVal = max(maxVal ,prices[i]);
        }
        return maxProfit;
    }
};