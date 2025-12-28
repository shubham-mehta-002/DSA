// https://leetcode.com/problems/apple-redistribution-into-boxes/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),[](int a, int b){
            return a>b;
        } );
        int sum = 0;
        for(int a  :apple){
            sum += a;
        }
        int count = 0;
        for(int c : capacity){
            sum -= c;
            count++;
            if(sum <= 0 ){
                break;
            }
        }

        return count;
    }
};