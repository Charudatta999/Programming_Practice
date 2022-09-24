#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapIndex(int *arr, int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int getMax(int *array, int startIndex, int lastIndex)
{
    int max = startIndex;
    for (int i = startIndex; i <= lastIndex; i++)
    {
        if (array[i] > array[max])
        {
            max = array[i];
        }
    }
    return max;
}

void selectionSort(int *array, int i, int size)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
        if (arr[j] < arr[min])
        {
            min = j; // update the index of minimum element
        }
    }

    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    swap(arr, min, i);

    if (i + 1 < n)
    {
        selectionSort(arr, i + 1, n);
    }
}

int main()
{
    std::cout << "Enter Number Of ELements" << std::endl;
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    selectionSort(array,0, n);
    printArray(array, n);
    return n;
}
