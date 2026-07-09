#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

void recursiveIntertionSort(int index, vector<int> &arr)
{
    if (index == arr.size())
        return;

    for (int j = index; j > 0; j--)
    {
        if (arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
        }
    }
    recursiveIntertionSort(index + 1, arr);
}

int main()
{
    vector<int> arr = {5, 4, 6, -1, -9, 0};
    insertionSort(arr);

    for (int n : arr)
    {
        cout << n << " ";
    }
    return 0;
}