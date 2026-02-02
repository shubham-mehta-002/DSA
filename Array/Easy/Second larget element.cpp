#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
    int f = -1, s = -1;

    for (int a : arr) {
        if (a > f) {
            s = f;
            f = a;
        } else if (a < f && a > s) {
            s = a;
        }
    }
    return s;
}

};