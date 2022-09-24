#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int *array, int left, int mid, int right)
{

    int leftLength = mid - left + 1;

    int rightLength = right - mid;

    //temp arrays

    int leftTemp[leftLength],
        rightTemp[rightLength];

    //copying elemnts left of mid and mid to an temp array
    for (int i = 0; i < leftLength; i++)
    {

        leftTemp[i] = array[left + i];
    }

    //copying elemnts right of mid to an temp array
    for (int j = 0; j < rightLength; j++)
    {
        rightTemp[j] = array[mid + 1 + j];
    }

    //merging temp array to real array in sorted manner

    int indexOfSubArrayOne = 0; // Initial index of first sub-array

    int indexOfSubArrayTwo = 0; // Initial index of second sub-array

    int indexOfMergedArray = left; // Initial index of merged array

    while (indexOfSubArrayOne < leftLength && indexOfSubArrayTwo < rightLength)
    {
        //comparing elemnts of two sub-array an replacing them in original array

        if (leftTemp[indexOfSubArrayOne] <= rightTemp[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftTemp[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightTemp[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    //if right array is finished and elemnts are remaing in leftTemp then

    while (indexOfSubArrayOne < leftLength)
    {
        array[indexOfMergedArray] = leftTemp[indexOfSubArrayOne];
        indexOfMergedArray++;
        indexOfSubArrayOne++;
    }
    while (indexOfSubArrayTwo < rightLength)
    {
        array[indexOfMergedArray] = rightTemp[indexOfSubArrayTwo];
        indexOfMergedArray++;
        indexOfSubArrayTwo++;
    }
}

void mergeSort(int *array, int begin, int end)
{

    if (begin < end)
    {

        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);

        merge(array, begin, mid, end);
    }
}

int main()
{
    int arr[] = {4, 50, 2, 10, 30, -2, -50, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}