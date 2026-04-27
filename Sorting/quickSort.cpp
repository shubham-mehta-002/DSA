#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int low, int high, vector<int> &arr)
{
    if (low >= high)
        return;

    int idx = findPivot(arr, low, high);

    quickSort(low, idx - 1, arr);
    quickSort(idx + 1, high, arr);
}

int main()
{
    vector<int> arr = {5, 4, 6, -1, -9, 0};

    quickSort(0, arr.size() - 1, arr);

    for (int n : arr)
    {
        cout << n << " ";
    }

    return 0;
}