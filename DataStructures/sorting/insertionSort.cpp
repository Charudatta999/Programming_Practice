#include<iostream>

using namespace std;

void swap(int *array, int startPosition, int minPosition)
{
    int temp = array[startPosition];
    array[startPosition] = array[minPosition];
    array[minPosition] = temp;
}

void insertionSort(int Array[],int n){
    int pos = 0;
    for (pos = 0; pos < n;pos++){
        int nextPos = pos;
        while (nextPos>0 && Array[nextPos]<Array[nextPos-1]){
            swap(Array, nextPos, nextPos - 1);
            nextPos = nextPos - 1;
        }

        
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {123, 233, 12, -55, 32, 0, 655};
   int n = 7;
   insertionSort(arr, n);
   display(arr, n);
}
