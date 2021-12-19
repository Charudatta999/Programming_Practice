#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int *array, int Left, int mid, int right){
    int leftLenght = mid - Left + 1;
    int rightLenght = right - mid;
    int inversions = 0;

    //temp arrays

    int *leftArray = new int[leftLenght];
    int *rightArray = new int[rightLenght];

    //copying left-mid to leftArray
    for (int i = 0; i < leftLenght; i++)
    {
        leftArray[i] = array[Left + i];
    }

    //copying mid+1 to rightArray

    for (int j=0; j < rightLenght; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    //merging leftArray and rightArray to array

    int index_Of_LeftArray = 0; //initialize index of leftArray

    int index_Of_RightArray = 0; //initialize index of rightArray   

    int index_Of_Array = Left;//initialize index of array
    while(index_Of_LeftArray < leftLenght && index_Of_RightArray < rightLenght){


        if(leftArray[index_Of_LeftArray] <= rightArray[index_Of_RightArray]){

            array[index_Of_Array] = leftArray[index_Of_LeftArray];
            index_Of_LeftArray++;
        }
        else{
            array[index_Of_Array] = rightArray[index_Of_RightArray];
            index_Of_RightArray++;
            inversions += leftLenght - index_Of_LeftArray;
        }
        index_Of_Array++;
    }


   
}
int mergeSort(int *array, int begin, int end)
{

    if (begin < end)
    {

        auto mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);

        return merge(array, begin, mid, end);
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
