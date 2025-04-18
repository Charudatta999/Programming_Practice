#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> tempVector;
    int leftIndex = left, midIndex = mid + 1;
    while (leftIndex <= mid && midIndex <= right)
    {
        if(arr[leftIndex] <= arr[midIndex])
        {
            tempVector.push_back(arr[leftIndex]);
            leftIndex++;
        }
        else if(arr[leftIndex] > arr[midIndex])
        {
            tempVector.push_back(arr[midIndex]);
            midIndex++;
        }
    }
    while (leftIndex <= mid)
    {
        tempVector.push_back(arr[leftIndex]);
        leftIndex++;
    }
    while (midIndex <= right)
    {
        tempVector.push_back(arr[midIndex]);
        midIndex++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = tempVector[i - left];
    }

}
void mergeSort(std::vector<int>& arr, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = left + (right -left) / 2; 
    mergeSort(arr, left,mid);
    mergeSort(arr, mid +1, right);
    merge(arr,left,mid,right);
}

void sort(std::vector<int>& colors)
{
    int sizeOfArr = colors.size();
    mergeSort(colors,0,sizeOfArr -1);
}

int main() {
    std::vector<int> colors{2,0,2,1,1,0};
    sort(colors);
    if(colors == std::vector<int> {0,0,1,1,2,2})
    {
        std::cout << "passsed";
    }
    else
    {
        std::cout << "failed" << std::endl;
    }
    return 0;
}