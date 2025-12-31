#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>res;
        int initialNum = 0;

        int i = 0;
        int currentVal = 1;
        while(i<target.size()){
            int diff = target[i] - currentVal;

            if(diff >= 0){
                while(diff--){
                    res.push_back("Push");
                    res.push_back("Pop");
                    currentVal++;
                }
                res.push_back("Push");
                currentVal++;
            }

            ++i;
        }

        return res;
    }
};