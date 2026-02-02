#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxVal=INT_MIN;
        for(int a : arr){
            maxVal = max(maxVal,a);
        }
        return maxVal;
    }
};
