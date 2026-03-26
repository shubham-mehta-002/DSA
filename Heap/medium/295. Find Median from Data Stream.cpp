#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxHeap;                            // left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half

    MedianFinder() {}

    void addNum(int num)
    {

        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // balance heaps
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {

        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};