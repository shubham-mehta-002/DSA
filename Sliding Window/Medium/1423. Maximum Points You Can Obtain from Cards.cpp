#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int maxSum = 0;
        for(int i=0;i<k;i++){
            sum += cardPoints[i];
            maxSum = max(maxSum, sum);
        }

        if(k == n){
            return maxSum;
        }

        int i = k-1;
        int j = n-1;

        while(i>=0){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            i--;
            j--;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};