#include <iostream>
#include <vector>
using namespace std;

void selectSort(int n, vector<int> &arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minn = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minn])
            {
                minn = j;
            }
        }

        swap(arr[minn], arr[i]);
    }
}

void selectSortRecursive(int index, vector<int> &arr)
{
    if (index == arr.size() - 1)
    {
        return;
    }
    int minn = index;
    for (int j = index + 1; j < arr.size(); j++)
    {
        if (arr[minn] > arr[j])
        {
            minn = j;
        }
    }
    swap(arr[minn], arr[index]);
    selectSortRecursive(index + 1, arr);
    return;
}

int main()
{
    vector<int> arr = {5, 4, 6, -1, -9, 0};
    selectSort(arr.size(), arr);
    selectSortRecursive(0, arr);
    for (int n : arr)
    {
        cout << n << " ";
    }
    return 0;
}