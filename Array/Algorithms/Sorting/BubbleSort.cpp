#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int n, vector<int> &arr)
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void recursiveBubbleSort(int index, vector<int> &arr)
{
    int n = arr.size();
    if (index == arr.size() - 1)
        return;

    for (int j = 0; j < n - index - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }

    recursiveBubbleSort(index + 1, arr);
}

int main()
{
    vector<int> arr = {5, 4, 6, -1, -9, 0};
    // bubbleSort(arr.size(),arr);
    recursiveBubbleSort(0, arr);
    for (int n : arr)
    {
        cout << n << " ";
    }
    return 0;
}