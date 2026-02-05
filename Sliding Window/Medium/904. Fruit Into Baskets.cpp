#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0;
        int j = 0;
        int maxFruits = 0;
        int count = 0;
        unordered_map<int,int>m;
        int total = 0;

        while(j<n){

            if(m[fruits[j]] == 0){
                count++;        
            }   

            m[fruits[j]]++;
            total++;


            while(count > 2){
                m[fruits[i]]--;
                total--;
                if(m[fruits[i]] == 0){
                    count--;
                }
                i++;
            }

            maxFruits = max(maxFruits, total); 
            j++;
        }
        return maxFruits;
    }
};