#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int maxx = INT_MIN;
        int n = nums.size();
        int totalSum = 0;

        int sum = 0;
        int cntr = 0;
        for (int num : nums)
        {
            totalSum += num;

            sum += cntr * num;
            cntr++;
        }

        maxx = max(maxx, sum);
        for (int i = 0; i < n; i++)
        { // n-1 times
            sum = sum - totalSum + n * nums[i];
            maxx = max(maxx, sum);
        }

        return maxx;
    }
};