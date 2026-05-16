#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    long long NEG = LLONG_MIN / 2;

    vector<vector<vector<long long>>> dp(
        n1+1, vector<vector<long long>>(n2+1, vector<long long>(k+1, NEG))
    );

    // base case
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            dp[i][j][0] = 0;
        }
    }

    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            for(int rem = 1; rem <= k; rem++) {

                long long maxx = NEG;

                // take pair
                if (dp[i+1][j+1][rem-1] != NEG) {
                    maxx = max(maxx,
                        1LL * nums1[i] * nums2[j] + dp[i+1][j+1][rem-1]
                    );
                }

                // skip nums1[i]
                maxx = max(maxx, dp[i+1][j][rem]);

                // skip nums2[j]
                maxx = max(maxx, dp[i][j+1][rem]);

                dp[i][j][rem] = maxx;
            }
        }
    }

    return dp[0][0][k];
}
};