#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int find(int n, int k){
        if(n==1){
            return 0;
        }
        
        return (find(n-1,k)+k)%n;
    }
    int josephus(int n, int k) {
        // code here
        return find(n,k) + 1;
    }
};