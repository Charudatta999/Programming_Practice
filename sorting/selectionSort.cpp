#include <stdio.h>
#include <iostream>

int getMaxIndex(int arr[], int startIndex, int lastIndex)
{
    int max = startIndex;
    for (int i = startIndex + 1; i <= lastIndex; i++)
    {
        if (arr[max] < arr[i])
            max = i;
    }
    return max;
}
void swapIndex(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void selectionSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        int lastIndex = arrSize - i - 1;
        int maxIndex = getMaxIndex(arr, 0, lastIndex);
        swapIndex(arr, maxIndex, lastIndex);
    }
}

int main()
{
    int arr[] = {0, 50, 90, 90, 1200, -40, 20, 60, -1500};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}