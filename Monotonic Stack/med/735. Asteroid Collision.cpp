#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        int i = 0;

        while(i<asteroids.size()){
            if(res.size() == 0){
                res.push_back(asteroids[i]);
                i++;
                continue;
            }
            
            if(res.back() > 0  && asteroids[i] < 0){
                if(abs(res.back()) < abs(asteroids[i])){
                    res.pop_back();
                }else if(abs(res.back()) == abs(asteroids[i])){
                    res.pop_back();
                    i++;
                }else{
                    i++;
                }
            }else{
                res.push_back(asteroids[i]);
                i++;
            }

           
        }

        return res;
    }
};