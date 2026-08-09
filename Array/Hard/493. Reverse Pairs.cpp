#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(int left, int mid, int right, vector<int> &nums)
    {
        int cnt = 0;
        int ptr1 = left;
        int ptr2 = mid + 1;

        while (ptr1 <= mid && ptr2 <= right)
        {
            while (ptr1 <= mid && 1LL * nums[ptr1] <= 2LL * nums[ptr2])
            {
                ptr1++;
            }
            cnt += (mid - ptr1 + 1);
            ptr2++;
        }

        return cnt;
    }
    void merge(int left, int mid, int right, vector<int> &nums)
    {
        // sort the array
        int size = right - left + 1;
        vector<int> temp(size);

        int k = 0;
        int p1 = left;
        int p2 = mid + 1;

        while (p1 <= mid && p2 <= right)
        {
            if (nums[p1] <= nums[p2])
            {
                temp[k++] = nums[p1++];
            }
            else
            {
                temp[k++] = nums[p2++];
            }
        }

        while (p1 <= mid)
        {
            temp[k++] = nums[p1++];
        }

        while (p2 <= right)
        {
            temp[k++] = nums[p2++];
        }

        // transfer the array
        for (int i = 0; i < size; i++)
        {
            nums[left + i] = temp[i];
        }
    }

    int mergeSort(int i, int j, vector<int> &nums)
    {
        if (i >= j)
            return 0;
        int mid = (i + j) / 2;

        int cnt = 0;
        cnt += mergeSort(i, mid, nums);
        cnt += mergeSort(mid + 1, j, nums);
        cnt += count(i, mid, j, nums);
        merge(i, mid, j, nums);

        return cnt;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(0, nums.size() - 1, nums);
    }
};